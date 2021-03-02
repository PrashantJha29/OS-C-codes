#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int a[10][10],b[10][10],r1,c1,r2,c2;

void* func()
{
	pthread_mutex_lock(&mutex1);
	int i,j;
	printf("enter the no of rows in matrix1: ");
	scanf("%d",&r1);
	printf("enter the no of cols in matrix1: ");
	scanf("%d",&c1);
	printf("Enter matrix1:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the no of rows in matrix2: ");
	scanf("%d",&r2);
	printf("enter the no of cols in matrix2: ");
	scanf("%d",&c2);
	printf("Enter matrix2:\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}	
	pthread_mutex_unlock(&mutex1);	
}

void* func1()
{
	pthread_mutex_lock(&mutex1);
	int i,j,c[10][10];
	if(r1==r2 && c1==c2){
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	
	printf("Matrix after addition:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	}
	else
		printf("Addition not possible\n");
	pthread_mutex_unlock(&mutex1);
}

int main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,&func,NULL);
	pthread_create(&thread2,NULL,&func1,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return(0);
}
