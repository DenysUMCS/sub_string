#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#define MAX 10

int main(){
	int shmid, *buf;
	shmid = shmget(45281, MAX*sizeof(int),IPC_CREAT | 0600);
if(shmid == -1){
	perror("Utworzenie segmentu pamienci wspoldzielonej\n");
	exit(1);
}
buf=(int *)shmat(shmid,NULL,0);
if(buf== NULL){
	perror("Przylaczenie segmentu pamieci wspoldzielonej\n");
	exit(1);
}
for(int i=0;i<10000;i++)
	printf("Numer : %5d wartosc: %5d\n",i,buf[i%MAX]);
}
