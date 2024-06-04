#include <stdio.h>
#include <sys/utsname.h>

int main() {
	struct utsname system_info;

	if(uname(&system_info) == -1) {
		perror("uname");
		return 1;
	}

	printf("%s\n", system_info.sysname);
	return 0;
}
