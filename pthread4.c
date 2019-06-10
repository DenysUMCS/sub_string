#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void * Hello(void *arg){
	for(int i=0;i<20;i++){
		printf("Watek mowi czesc!\n");
		sleep(1);
	}
	return NULL;
}

int main(){
pthread_t mojwatek;
if(pthread_create(&mojwatek,NULL,Hello,NULL)){
	printf("blad przy tworzeniu watku\n");
}
if(pthread_join(mojwatek,NULL)){
	printf("blad w konczeniu watkiu\n");
	exit(1);
}
exit(0);
return 0;
}
