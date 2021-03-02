/*Write a C program where parent process sends a number to child process using PIPE and child process compute whether that number is a prime number or not.*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void is_prime(int val)
{
	int i,flag=0;
	for(i=2;i<=val/2;i++)
		{
			if(val%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("%d is not prime\n",val);
		else
			printf("%d is prime\n",val);
}	

int main()
{
	pid_t pid;
	int fd[2],val,i,flag=0;
	pipe(fd);
	pid=fork();
	
	 if(pid>0)
	{
		
		printf("Enter the number: ");
		scanf("%d",&val);
		close(fd[0]);
		write(fd[1],&val,sizeof(val));
		printf("Parent(%d) sends %d to child\n",getpid(),val);
		close(fd[1]);
	}
	else if(pid==0)
	{
		wait(NULL);
		close(fd[1]);
		read(fd[0],&val,sizeof(val));
		printf("Child(%d) received :%d\n",getpid(),val);
		is_prime(val);
		close(fd[1]);
	}

}
