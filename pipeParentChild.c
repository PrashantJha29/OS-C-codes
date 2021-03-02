#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#define MAX 20

void main()
{
	int pid,fd[2];
	char s1[MAX]=" Hello Pipe!";
	char s2[MAX];
	
	pipe(fd);
	pid=fork();
	
	printf("\nStart!");
	if(pid==0)
	{
		printf("\nChild process!");
		close(fd[1]);
		read(fd[0],s2,MAX);
		printf("\nChild process receives the message!");
		puts(s2);
		close(fd[0]);
	}
	else
	{
		printf("\nParent process!");
		close(fd[0]);
		write(fd[1],s1,strlen(s1)+1);
		printf("\nParent process writes the message!");
		puts(s1);
		close(fd[1]);
	}
	printf("\nEnd!\n");
}
