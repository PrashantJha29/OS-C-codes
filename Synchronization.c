/*Write a C program to create multiple threads and check the memory address of a variable before and after modification by all the threads. Synchronize the threads using lock-unlock.*/
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int counter=0;

void *fun()
{
	int i,t;
		pthread_mutex_lock(&mutex1);
			t=counter;
			//t++;	
			sleep(1);	
			counter=t;
			counter++;
			printf("Thread %ld print counter value %d\n",pthread_self(),counter);
		pthread_mutex_unlock(&mutex1);
}		
int main()
{
	pthread_t th1,th2;
  printf("Address of counter before modification= %d\n",&counter);
	pthread_create(&th1,NULL,&fun,NULL);
	pthread_create(&th2,NULL,&fun,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
  printf("Address of counter after modification= %d\n",&counter);
	return 0;
}

/*OUTPUT:
Address of counter before modification= 1804738664
Thread 140433373619968 print counter value 1
Thread 140433365227264 print counter value 2
Address of counter after modification= 1804738664

NOTE: It will just show that all the threads access the same memory space. That is shared Memory.
U can also print the "&counter" value within the fun().*/
