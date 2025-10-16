#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    char *arguments[10] = {"-a", "-l", "-t", NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    if (pid == 0)
    {
        // Notice you can add as many NULLs on the end as you want
        int ret = execl("/bin/ls", "ls", arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9], NULL);

        if (ret == -1)
        {
            perror("execl failed: ");
        }
    }
    else
    {
        int status;
        wait(&status);
    }

    return 0;
}
