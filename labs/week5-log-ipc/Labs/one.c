#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int fd[2], nbytes;
    pid_t pid;
    char string[]= "It's a joke!!!!\n";
    char readbuffer[100];

	pipe(fd);
	pid = fork();
    if(pid < -1)
    {
        perror("Something went wrong with fork");
        return 1;
    }
    if(pid == 0)
    {
        close(fd[1]);
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Message from Parent: %s\n", readbuffer);
    }
    else
    {
        close(fd[0]);
        write(fd[1], string, (strlen(string)+1));
    }
    return(0);
}