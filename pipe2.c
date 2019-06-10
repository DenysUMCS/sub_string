#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char*argv[]){
int pdesk[2];
pid_t pr;
pipe(pdesk);
pr=fork();
if(pr== -1){
	perror("Tworzenie procesu\n");
}else if(pr==0){
	dup2(pdesk[1],1);
	execvp("ls",argv);
	perror("Uruchumienie programu ls\n");
	exit(1);
}else{
	char buf[512];
	int lb,i;
	close(pdesk[1]);
	while((lb=read(pdesk[0],buf,512))>0){
		for(i=0;i<lb;i++)
			buf[i]=toupper(buf[i]);
		if(write(1,buf,lb)==-1){
			perror("Zapis na standartowe wyjscie\n");
			exit(1);
		}
	}
	if(lb==-1){
		perror("Odczyt z potoku\n");
		exit(1);
	}
}
return 0;
}
