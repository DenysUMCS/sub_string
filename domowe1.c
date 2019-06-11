#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){
int shmid,i=0;
char ha[]="haaaa", ho[]="hooooo";
char *to_write;

shmid = shmget(45224,7*sizeof(char),IPC_CREAT|0600);

if(shmid == -1){
	perror("Utworzenie segmentu pamiencu\n");
	exit(1);
}
to_write=(char*)shmat(shmid,NULL,0);
if(ha==NULL){
	perror("Przylaczenie segmentu pamieci\n");
	exit(1);
}
while(1){
sleep(1);
if(i%2==0){
	*to_write='\0';
	strcat(to_write,"haaa");

}else{
	*to_write='\0';
	strcat(to_write,"hooo");
}
i++;
}

}
