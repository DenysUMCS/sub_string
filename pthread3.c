#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int mojazmiennaglobalna;
pthread_mutex_t mojmutex=PTHREAD_MUTEX_INITIALIZER;

void *Hello(void *arg){
int i,j;
	for(i=0;i<20;i++){
	j=mojazmiennaglobalna;
	j=j+1;
	printf(".");
	fflush(stdout);
	sleep(1);
	mojazmiennaglobalna=j;
	pthread_mutex_unlock(&mojmutex);
	}
return 0;
}

int main(){
pthread_t mojwatek;
int i;
if(pthread_create(&mojwatek,NULL,Hello,NULL)){
	printf("blad przy tworzeniu watku\n");
	abort();
}
for(i=0;i<20;i++){
	pthread_mutex_lock(&mojmutex);
	mojazmiennaglobalna+=1;
	printf("o");
	fflush(stdout);
	sleep(1);
}

if(pthread_join(mojwatek,NULL)){
	printf("blad przy konczeniu watku\n");
	abort();
}
printf("Moja zmiennaglobalna wynosi %d\n",mojazmiennaglobalna);
exit(0);
return 0;
}
