#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char* argv[] ){
char buf[MAX];
int desc_zrod,desc_cel;
int lbajt;
if(argc<3){
	printf("Za malo argumentow. Uzyj:\n");
	printf("%s <plik zrodlowy> <plik docelowy> \n",argv[0]);
	exit(1);
}
desc_zrod= open(argv[1], O_RDONLY);
if(desc_zrod == -1){
	printf("Blad otwarcia pliku: %s\n",argv[1]);
	exit(1);
}
desc_cel=open(argv[2],O_WRONLY);
if(desc_cel==-1){
	printf("Blad otwarcia pliku: %s\n", argv[2]);
	exit(1);
}

while((lbajt= read(desc_zrod,buf,MAX))>0){
	printf("%d",lbajt);
	if(write(desc_cel,buf,lbajt)== - 1){
		printf("Blad zpisu pliku docelowego\n");
		exit(1);
	}
}
if(lbajt == -1){
	printf("Blad odczytu pliku zrodlowego\n");
	exit(1);
}
if(close(desc_zrod)== -1 || close(desc_cel)== -1){
	printf("Blad zamkniecia pliiku\n");
	exit(1);
}

	return 0;
}
