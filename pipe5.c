#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX 512

int main(int argc, char * argv[]){
	int pdesk;
	if(mkfifo("/tmp/fifo1",0600)== -1){
		perror("Tworzenie kolejki\n");
		exit(1);
	}
if(fork()==0){
	close(1);
	open("/tmp/fifo1",O_WRONLY);
	execvp("ls",argv);
	perror("Urochomienie programu ls\n");
	exit(1);
}else{
	char buf[MAX];
	int lb,i;
	wait(0);
	pdesk=open("/tmp/fifo1",O_RDONLY);
	while((lb=read(pdesk,buf,MAX))>0){
		for(i=0;i<lb;i++)
			buf[i]=toupper(buf[i]);
		write(1,buf,lb);
	}
}
return 0;
}
