#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char kode[6];
	char nama[25];
	int harga;
}arsipProduk;
arsipProduk produk;

FILE *fs1, *fs2, *ft;
char file1[20], file2[20], file3[20];

main() {
	printf("Masukan nama file pertama ");
	gets(file1);
	printf("Masukan nama file kedua ");
	gets(file2);
	printf("Masukan nama file baru ");
	gets(file3);
	fs1 = fopen(file1,"r");
	fs2 = fopen(file2,"r");
	if( fs1 == NULL || fs2 == NULL ) {
		perror("Error ");
		printf("Press any key to exit...\n");
		getch();
		exit(EXIT_FAILURE);
	}
	ft = fopen(file3,"w");
	if( ft == NULL ) {
		perror("Error ");
		printf("Press any key to exit...\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fs1,"%s %s %d\n",&produk.kode,&produk.nama,&produk.harga);
	while( strcmp(produk.kode,"XXX") != 0 ){
		fprintf(ft,"%s %s %d\n",produk.kode,produk.nama,produk.harga);
		fscanf(fs1,"%s %s %d\n",&produk.kode,&produk.nama,&produk.harga);
	}
	fscanf(fs2,"%s %s %d\n",&produk.kode,&produk.nama,&produk.harga);
	while( strcmp(produk.kode,"XXX") != 0 ){
		fprintf(ft,"%s %s %d\n",produk.kode,produk.nama,produk.harga);
		fscanf(fs2,"%s %s %d\n",&produk.kode,&produk.nama,&produk.harga);
	}
	fprintf(ft,"XXX XXX XXX\n");
	printf("Berhasil di merge di %s.\n",file3);
	fclose(fs1);
	fclose(fs2);
	fclose(ft);
	getch();
}
