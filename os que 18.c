#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
        int  i,fd[2], n;
        pid_t childpid;
        char string[]="Hello, world!\n";
        char rb[20];
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
                n = read(fd[0], rb, sizeof(rb));
                printf("input string: %s", rb);
                for(i=0;i<sizeof(rb)-1;i++)
                {
                  if(rb[i]>64 && rb[i]<91)
                   rb[i]+=32;
                  else if(rb[i]>96 && rb[i]<123)
                   rb[i]-=32;
                  else
                  rb[i]=rb[i];
                  }
                printf("output string: %s",rb);
        }
        return(0);
}





