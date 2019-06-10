#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t zombi;
	zombi=fork();
	if(zombi>0){
		sleep(6);
	}else{
		exit(0);
	}
	return 0;
}
