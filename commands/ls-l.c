#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// 파일 유형과 권한을 출력하는 함수
void printPermissions(mode_t mode) {
    // 파일 유형 출력
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((S_ISLNK(mode)) ? "l" : "-");
    printf((S_ISREG(mode)) ? "-" : "");

    // 사용자 권한 출력
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    // 그룹 권한 출력
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    // 기타 권한 출력
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

// 파일의 상세 정보를 출력하는 함수
void printFileInfo(struct stat fileInfo, char* fileName) {
    // 파일 유형과 권한 출력
    printPermissions(fileInfo.st_mode);
    
    // 링크 수 출력
    printf(" %ld", (long)fileInfo.st_nlink);
    
    // 소유자 이름 출력
    struct passwd *pw = getpwuid(fileInfo.st_uid);
    printf(" %s", pw->pw_name);
    
    // 그룹 이름 출력
    struct group *gr = getgrgid(fileInfo.st_gid);
    printf(" %s", gr->gr_name);
    
    // 파일 크기 출력
    printf(" %lld", (long long)fileInfo.st_size);
    
    // 마지막 수정 시간 출력
    char time[20];
    strftime(time, 20, "%b %d %H:%M", localtime(&fileInfo.st_mtime));
    printf(" %s", time);
    
    // 파일 이름 출력
    printf(" %s\n", fileName);
}

int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *entry;
    struct stat fileInfo;

    // 현재 디렉토리 열기
    directory = opendir(".");
    if (directory == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    // 디렉토리 내의 각 파일 및 디렉토리에 대한 정보 출력
    while ((entry = readdir(directory)) != NULL) {
        if (stat(entry->d_name, &fileInfo) == -1) {
            perror("Unable to get file status");
            return 1;
        }
        printFileInfo(fileInfo, entry->d_name);
    }

    // 디렉토리 닫기
    closedir(directory);

    return 0;
}

