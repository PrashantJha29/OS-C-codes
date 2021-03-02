#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int counter=0;
void *fun()
{
	int i,t;
	
	for(i=0;i<10;i++)
	{	
		pthread_mutex_lock(&mutex1);
			t=counter;
			t++;	
			//sleep(1);	
			counter=t;
			//counter++;
			printf("Thread %ld print counter value %d\n",pthread_self(),counter);
		pthread_mutex_unlock(&mutex1);
	}
}		
int main()
{
	pthread_t th1,th2,th3;
	pthread_create(&th1,NULL,&fun,NULL);
	pthread_create(&th2,NULL,&fun,NULL);
	pthread_create(&th3,NULL,&fun,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	return 0;
}
