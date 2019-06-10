#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

int main(int argc , char * argv[]){
	int pdesk[2];


	if(pipe(pdesk)==-1){
	perror("Tworzenie potoku\n");
	exit(1);
	}

	switch(fork()){
	case -1:
		perror("Tworzenie procesu\n");
		exit(1);
	case 0:
		dup2(pdesk[1],1);
		execvp("ls",argv);
		perror("Urochomienie programu ls\n");
		exit(1);
	default:{
		close(pdesk[1]);
		dup2(pdesk[0],0);
		execlp("tr","tr","a-z","A-Z",NULL);
		perror("Uruchumienie programu tr\n");
		exit(1);
		}
	}
return 0;
}
