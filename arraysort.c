#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int n,a[100];

void* func()
{
	pthread_mutex_lock(&mutex1);
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("enter the array elements");
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	pthread_mutex_unlock(&mutex1);	
}

void* func1()
{
	pthread_mutex_lock(&mutex1);
	for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<n-1-i;j++)
	    {
	        if(a[j]>a[j+1])
	        {
	            int temp=a[j];
	            a[j]=a[j+1];
	            a[j+1]=temp;
	        }
	    }
	}
	printf("The array after sorting is:");
	for(int i=0;i<n;i++)
	    printf("%d ",a[i]);
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
