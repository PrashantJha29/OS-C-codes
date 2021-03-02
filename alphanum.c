/*Write a C program to create a child process. Parent process send a string to child process using PIPE then child process will calculate how many, alphabet, numeric and special characters (#, &) are there?*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
        unsigned fd[2];
		int n,i;
        pipe(fd);
        pid_t pid;
        pid=fork();
        char buff[100]={"this #s & 1 3 "},buff1[20];

        if(pid==0)
        {
                int alp=0,num=0,spl=0;
                //printf("-------------This is child process----------------\n\n");
                read(fd[0],&buff1,20);
                for(i=0;i<=20;i++)
                {
                        printf("%c",buff1[i]);
                        if((buff1[i]>='a' && buff1[i]<='z') || (buff1[i]>='A' && buff1[i]<='Z'))
                                alp++;
                        else if(buff1[i]=='&' || buff1[i]=='#')
                                spl++;
                        else if(buff1[i]>='0' && buff1[i]<='9')
                                num++;



                }
                printf("\nThe alphabets =%d ,Numbers = %d, Special char = %d\n\n",alp,num,spl);

        }
        else if(pid>0)
        {
                //printf("--------------This is parent process--------------\n\n");     

                write(fd[1],&buff,20);
                wait(NULL);
        }

        else
                printf("process not created\n\n");
}
