#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char* argv[]){
int src, dest;
int buf[MAX];
int lbajt;

if(argc<3){
	printf("Nie poprawna ilosc argumentow\n");
	printf("Uzyj:\n");
	printf("%s <plik zrodlowy> <plik docelowy>\n",argv[0]);
}
src=open(argv[1],O_RDONLY);
if(src == -1){
	printf("Blad otwarcia plika zrodlowego\n");
	exit(1);
}
dest=creat(argv[2],0640);
if(dest == -1){
	printf("Blad utworzenia plika docelowego\n");
	exit(1);
}

while((lbajt=read(src,buf,MAX))>0){
	if(write(dest,buf,lbajt)==-1){
		printf("Blad zapisu pliku docelowego\n");
		exit(1);
	}
}
if(lbajt == -1){
	printf("Blad odczytu pliku zrodlowego");
	exit(1);
}


if(close(src)==-1 || close(dest)==-1){
	printf("Blad zamkniecia plika\n");
}
return 0;
}
