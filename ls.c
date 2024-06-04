#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *directory;
    struct dirent *entry;

    // 현재 디렉토리 열기
    directory = opendir(".");
    if (directory == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(directory)) != NULL) {	//디렉토리 내의 각 파일 출력
        if (entry->d_name[0] != '.') {			//숨겨진 파일인 경우 무시
            printf("%s\t", entry->d_name);
        }
    }
    
    printf("\n");
    
    closedir(directory);				//directory 닫기
    return 0;
}

