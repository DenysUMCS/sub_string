#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(){
	int pdesk[2];
	if(pipe(pdesk)==-1){
	perror("Tworzenie potoku\n");
	exit(1);
	}
	int key=fork();
	if(key==-1){
	perror("Tworzenie procesu\n");
	exit(1);
	}else if(key==0){
	if(write(pdesk[1],"Hallo!",7)==-1){
	perror("Zapis do potoku\n");
	exit(1);
	}
	exit(0);
	}else{
	char buf[10];
	if(read(pdesk[0],buf,10)==-1){
		perror("Odczyt z potoku\n");
		exit(1);
	}
	printf("Odczytano z potoku\n %s\n",buf);
	}
return 0;
}
