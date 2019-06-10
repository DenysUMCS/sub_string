#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char* argv[] ){
int desc_zrod;
long rozm;

if(argc<2){
	printf("Za malo argumentow. Uzyj:\n");
	printf("%s <plik zrodlowy>\n",argv[0]);
	exit(1);
}
desc_zrod= open(argv[1], O_RDONLY);
if(desc_zrod == -1){
	printf("Blad otwarcia pliku: %s\n",argv[1]);
	exit(1);
}
rozm = lseek(desc_zrod,0,SEEK_END);

if(rozm == -1){
	printf("Blad w pozycijuwaniu\n");
	exit(1);
}

printf("Rozmiar pliku %s : %ld \n",argv[1],rozm);

if(close(desc_zrod)== -1){
	printf("Blad zamkniecia pliiku\n");
	exit(1);
}

	return 0;
}
