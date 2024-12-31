#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<Sys/types.h>

void main()
{
    int pipefds[2];
    pipe(pipefds);
    char buffer[256]={0};
    printf("parent pid is %d\n",getppid());
    write(pipefds[1],"JSSTU",5);
    if(fork()>0){
       return; 
    }
    read(pipefds[0],buffer,5);
    printf("got from pipe : %s\n",buffer);
    printf("child pid : %d\n",getpid());
}