#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
//com
int main(){
printf("Pocatek\n");
if(fork()==0){
	execlp("ls","ls","-a",NULL);
	perror("Blad uruchmienia\n");
	exit(1);
}
wait(NULL);
printf("Koniec\n");
return 0;
}
