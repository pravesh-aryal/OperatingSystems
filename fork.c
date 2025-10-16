#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
        pid_t pid2 = fork();
	printf("Hello from %d process. My parent process is %d. I am pid2 %d  \n", getpid(), getppid(), getpid());
	
	return 0;

}
