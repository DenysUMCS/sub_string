#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
if(fork()==0)
	exit(0);
sleep(30);
wait(NULL);
return 0;
}

