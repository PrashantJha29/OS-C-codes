#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
   int a=0, b=1, n=a+b,i,ii,j,f=0;
   pid_t pid;

   printf("Enter the range of Fibonacci Sequence:\n");
   scanf("%d", &ii);

   if (ii < 0)
      printf("Please enter a non-negative integer!\n");
   else
   {
      pid = fork();
      if (pid == 0)
      {
         printf("Child is producing the Fibonacci Sequence...\n");
         printf("%d %d ",a,b);
         for (i=0;i<ii-2;i++)
         {
            n=a+b;
            printf("%d ", n);
            a=b;
            b=n;
         }
         printf("\nChild ends\n"); 
      }
      else 
      {
         printf("Parent is waiting for child to complete...\n");
         wait(NULL);
				 printf("Parent is printing the prime numbers...\n");
				 for(i=2; i<=ii; i++)
   			 {
      		 f=0;
      		 for(j=2; j<=i/2; ++j)
       		 {
         		 	if(i%j==0)
         			{
            		f=1;
            		break;
         			}
      		 }
      		 if(f==0)
         	 printf("%d ",i);
 				 }
         printf("\nParent ends\n");
      }
   }
   return 0;
}
