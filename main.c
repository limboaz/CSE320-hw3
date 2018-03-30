#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv){
	pid_t sh_pid;
	char buf[256];

	if (argc != 2){
		printf("Invalid input.\n");
		exit(0);
	}
	while(1){
		printf("Please select from the following menu:\nsolver\ntrace\nfib\nquit\nchange\n");
		scanf("%s", argv[0]);
		if ( strcmp(argv[0], "quit") == 0){
			exit(0);
			//wait(NULL);
		}
		if ( strcmp(argv[0], "fib") == 0){
			strcpy(buf, argv[1]);
			FILE *f = fopen(argv[1], "r");
			fscanf(f, "%s", argv[1]);
			fclose(f);
		}
		if ( strcmp(argv[0], "change") == 0){
			scanf("%s", argv[1]);
		} else if ((sh_pid = fork()) == 0){
			execve(argv[0], argv, NULL);
			exit(0);
		} else {
			waitpid(sh_pid, NULL, 0);
		}
		if ( strcmp(argv[0], "fib") == 0)
			strcpy(argv[1],buf);
		wait(NULL);

	}
	return 0;

}
