#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void is_armstrong(int val)
{
    int i,sum=0,temp,d,c=0,r;
    temp=val;
    while(temp!=0)
    {
        temp=temp/10;
        c++;
    }
    temp=val;
    while(temp!=0)
    {
        r=temp%10;
        sum+=pow(r,c);
        temp=temp/10;
    }
    if(sum==val)
        printf("Armstrong number");
    else
        printf("Not an armstrong number");
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
		is_armstrong(val);
		close(fd[1]);
	}

}
