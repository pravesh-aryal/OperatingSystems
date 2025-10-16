//below is a snippet for making proper paths for exec function works independently.

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {

//     char *paths[4] = {"/bin/", "/sbin/", "/usr/sbin/", "/usr/bin/"};
//     char *command = "mkdir";
    
//     for (int i = 0; i < 4; i ++)
//     {
//         char *finalPath = malloc(strlen(command) + strlen(paths[i]) + 1);
//         strcpy(finalPath, paths[i]);
//         strcat(finalPath, command);
//         printf("The final path is %s \n", finalPath);
//         free(finalPath);
//     }
// }