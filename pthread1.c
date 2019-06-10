/*#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void main() {
	int pdesk[2];
	int x =10;
   if (fork() == 0){ // proces potomny
	for(int i = 0; i<5;i++)
	x+=1;	
	printf("%d\n",x);   
   }
	else { // proces macierzysty
	for(int i = 0; i<5;i++)
	x-=1;
	printf("%d\n",x);   
	}
}

*//*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int x = 5;
void *wykonaj1(void *a)
{
	int i;
	for(i = 0;i<5000;i++)
		x+=1;
	printf("watek1 zmienna - %d\n",x);
return NULL;
}

void *wykonaj2(void *a)
{
	int i;
	for(i = 0;i<5000;i++)
		x-=1;
	printf("watek2 zmienna - %d\n",x);
return NULL;
}
void main() {
	pthread_t t1;
	pthread_t t2;
	pthread_create (&t1 , NULL, wykonaj1,NULL);
	pthread_create (&t2 , NULL, wykonaj2,NULL);

	void *result;
	pthread_join(t1,&result);
	pthread_join(t2,&result);

}
*//*
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int x = 2000000;
pthread_mutex_t sygnalizacja = PTHREAD_MUTEX_INITIALIZER;
void *wykonaj1(void *a)
{

	int i;
	pthread_mutex_lock(&sygnalizacja);
	for(i = 0;i<1000000;i++)
		x-=1;
	printf("watek1 zmienna - %d\n",x);
	pthread_mutex_unlock(&sygnalizacja);
return NULL;
}

void main() {
	
	pthread_t t1;
	pthread_t t2;

	pthread_create (&t1 , NULL, wykonaj1,NULL);
	pthread_create (&t2 , NULL, wykonaj1,NULL);

	void *result;
	pthread_join(t1,&result);
	pthread_join(t2,&result);
	
	printf("zmienna %d",x);
	
	pthread_mutex_destroy(&sygnalizacja);
		
}
*/
/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *hello_world(void *arg)
{
	char *s = (char *) arg;
	printf("Hello %p!\n",arg);
}

void main(int argc, char *argv[]) {

	pthread_t hello_world_thread[5];
	
	for(int i = 0;i<5;i++)
	pthread_create (&hello_world_thread[i] , NULL, hello_world,&hello_world_thread[i]);

//	sleep(3);

	for(int i =0 ;i<5;i++)
	pthread_join(hello_world_thread[i],NULL);	

	printf("main thread existing\n");
	
}
*/
/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *print_message_function(void *ptr)
{
	char *s = (char *) ptr;
	printf("Hello %s!\n",ptr);
}

void main(int argc, char *argv[]) {

	pthread_t thread1,thread2;
	
	const char * message1 = "thread1";
	const char * message2 = "thread2";
	int iret1,iret2;

	iret1 = pthread_create (&threat1 , NULL, print_message_functions,(void *)message);
	if(iret1)
	{
		fprintf(stderr,"erorr - pthread create() return code: %d\n",iret1);
		exit(EXIT_FAILURE);
	}
//	sleep(3);
	
	iret2 = pthread_create (&threat2 , NULL, print_message_functions,(void *));
	if(iret2)
	{
		fprintf(stderr,"erorr - pthread create() return code: %d\n",iret2);
		exit(EXIT_FAILURE);
	}
	


}

*/
/*
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 16

int counter = 0;
pthread_mutex_t counter_lock;

void *incrementer_thread(void *arg) {
    printf("Start thread.");
    pthread_mutex_lock(&counter_lock);
    int temp = counter;
    sleep(1);
    counter = temp + 1;
    pthread_mutex_unlock(&counter_lock);
    printf("Done.");
}

int main(int argc, char* argv[]) {
    pthread_t incrementer_threads[THREAD_COUNT];

    pthread_mutex_init(&counter_lock, NULL);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int result = pthread_create(&(incrementer_threads[i]), NULL, incrementer_thread, NULL);
            if (result != 0) {
                perror("Could not create thread.");
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(incrementer_threads[i], NULL);
    }

    pthread_mutex_destroy(&counter_lock);

    printf("\nCounter value after executing %d threads is %d.\n", THREAD_COUNT, counter);
    return 0;
}*/

#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int x = 2000000;
pthread_mutex_t sygnalizacja = PTHREAD_MUTEX_INITIALIZER;
char buf[500];

void *wykonaj1()
{


return NULL;
}

void main() {
	
	pthread_t producent;
	pthread_t consument;



	if(strlen(buf) == 500){
	pthread_mutex_lock(&sygnalizacja);
	pthread_create (&producent , NULL, wykonaj1,NULL);
	pthread_mutex_unlock(&sygnalizacja);
	}
	pthread_create (&consument , NULL, wykonaj1,NULL);

	void *result;
	pthread_join(t1,&result);
	pthread_join(t2,&result);
	
	printf("zmienna %d",x);
	
	pthread_mutex_destroy(&sygnalizacja);
		
}

