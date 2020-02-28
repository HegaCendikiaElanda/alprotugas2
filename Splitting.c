#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char npm[6];
	char nama[25];
	char nilai;
}mahasiswa;
mahasiswa mhs;

FILE *ft1, *ft2, *fs;
char file[20], file1[20], file2[20];

main() {
	printf("Masukan nama file yang akan di split ");
	gets(file);
	printf("Masukan nama file baru pertama ");
	gets(file1);
	printf("Masukan nama file baru kedua ");
	gets(file2);
	fs = fopen(file,"r");
	if( fs == NULL) {
		perror("Error ");
		printf("Press any key to exit...\n");
		getch();
		exit(EXIT_FAILURE);
	}
	ft1 = fopen(file1,"w");
	ft2 = fopen(file2,"w");
	if( ft1 == NULL || ft2 == NULL ) {
		perror("Error ");
		printf("Press any key to exit...\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fs,"%s %s %c\n",&mhs.npm,&mhs.nama,&mhs.nilai);
	while( strcmp(mhs.npm,"XXX") != 0 ){
		if(mhs.nilai == 'A' || mhs.nilai == 'B' || mhs.nilai == 'C'){
			fprintf(ft1,"%s %s %c\n",mhs.npm,mhs.nama,mhs.nilai);
			fscanf(fs,"%s %s %c\n",&mhs.npm,&mhs.nama,&mhs.nilai);
		}else if(mhs.nilai == 'D' || mhs.nilai == 'E'){
			fprintf(ft2,"%s %s %c\n",mhs.npm,mhs.nama,mhs.nilai);
			fscanf(fs,"%s %s %c\n",&mhs.npm,&mhs.nama,&mhs.nilai);
		}else{
			fscanf(fs,"%s %s %c\n",&mhs.npm,&mhs.nama,&mhs.nilai);
		}
	}
	fprintf(ft1,"XXX XXX XXX\n");
	fprintf(ft2,"XXX XXX XXX\n");
	printf("Berhasil di split ke %s dan %s.\n",file1,file2);
	fclose(fs);
	fclose(ft1);
	fclose(ft2);
	getch();
}
