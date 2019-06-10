#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int num[5]={1,2,3,4,5};
int main(){
	int i;
	pid_t pid;
	pid=fork();
	pid_t pid1,pid2;
	if(pid==0){

		printf("Pierwszy proces pid = %d\n",pid);
		pid1=fork();
		if(pid1==0){
			printf("Potomek pirwszego procesu pid = %d\n",pid1);
		}else{
			wait(NULL);
			printf("pototmek pierwszego procesu pid = %d\n",pid1);
		}
	}else{
	wait(NULL);
	printf("Drugi proces pid = %d\n",pid);
		pid2=fork();
		if(pid2==0){
			printf("Potomek drugiego procesu pid = %d\n",pid2);
		}else{
		wait(NULL);
		printf("Potomek drugiego procesu pid = %d\n",pid2);
		}
	}

return 0;
}
