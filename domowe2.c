#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(){
int shmid,i=0;
char *to_write;
shmid = shmget(45224,7*sizeof(char),IPC_CREAT|0600);
if(shmid == -1){
	perror("Utworzenie segmentu pamiencu\n");
	exit(1);
}
to_write=(char*)shmat(shmid,NULL,0);
if(to_write==NULL){
	perror("Przylaczenie segmentu pamieci\n");
	exit(1);
}
while(1){
sleep(1);
if(to_write=="haaa")
	printf("%s\n",to_write);
else if(to_write=="hooo")
	printf("%s\n",to_write);
else
	printf("Blednyj napis - %s\n",to_write);
}
return 0;
}
