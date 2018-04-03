#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		printf("Error occured!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("Child process: \nID: %d\tParentID: %d\n", getpid(), getppid());
	}
	//The value of pid in the parent process is the process id of the child and not 0
	else
	{
		wait(NULL);
		printf("Parent process: \nID: %d\tChildID: %d\n", getpid(), pid);
		exit(0);
	}
	return 0;
}