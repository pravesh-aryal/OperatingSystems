#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		printf("Child process is terminating\n");
		exit(0);
	}
	else if (pid > 0)
	{
		usleep(10000);
	}
	return 0;

}
