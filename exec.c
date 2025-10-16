#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Run "echo Hello world" through /bin/sh
        int ret = execl("/bin/sh", "sh", "-c", "echo Hello world", (char *)NULL);

        if (ret == -1)
        {
            perror("execl failed");
        }
    }
    else
    {
        int status;
        wait(&status);
    }

    return 0;
}
