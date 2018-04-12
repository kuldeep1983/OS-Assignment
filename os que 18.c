#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
        int    i, fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "Hello, world!\n";
        char    readbuffer[80];
        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }
        if(childpid == 0)
        {
                close(fd[0]);
                write(fd[1], string, (strlen(string)+1));
                exit(0);
        }
        else
        {
                close(fd[1]);
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                printf("Received string: %s", readbuffer);
               int  max=strlen(readbuffer);
                for(int i=0;i<max-1;i++)
                {
                  if(readbuffer[i]>64 && readbuffer[i]<91)
                   readbuffer[i]+=32;
                  else if(readbuffer[i]>96 && readbuffer[i]<123)
                   readbuffer[i]-=32;
                  else
                  readbuffer[i]=readbuffer[i];
                  }
                printf("output is %s",readbuffer);
        }
        return(0);
}





