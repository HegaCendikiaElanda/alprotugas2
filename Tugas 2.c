#include<stdio.h>
#include<string.h>
#include<conio.h>

FILE *newFile;

int totalHarga;

typedef struct{
	char kode[6];
	char nama[25];
	int harga;
}arsipProduk;
arsipProduk produk;

void tampilMenu(){
	printf("Pilih Salah satu menu dibawah :\n");
	printf("1. Buat Arsip Beruntun\n");
	printf("2. Tampilkan Arsip beruntun\n");
	printf("3. Hitung Total Produk\n");
	printf("4. Hitung rata-rata total produk\n");
	printf("5. exit\n");
}

int cekFile(){
	int status,size;
	newFile = fopen("Arsip.txt","r");
	fseek(newFile, 0, SEEK_END);
	size = ftell(newFile);
	if (size == 0){
		status = 0;
	}else{
		status = 1;
	}
	fclose(newFile);
	return status;
}

void buatArsip(){
	char lagi;
	newFile = fopen("Arsip.txt","w");
	do{
		printf("Masukkan data berikut\n");
		printf("Kode : "); scanf("%s",&produk.kode);
		printf("Nama : "); scanf("%s",&produk.nama);
		printf("Harga : "); scanf("%d",&produk.harga);
		fprintf(newFile,"%s %s %d\n",produk.kode, produk.nama, produk.harga);
		printf("Input lagi(y/n) : "); fflush(stdin); scanf("%c",&lagi);
	}while(lagi=='y');
	fprintf(newFile,"XXX XXX XXX");
	fclose(newFile);
}

void tampilArsip(){
	if(cekFile()==1){
		newFile=fopen("Arsip.txt","r");
		printf("Isi Arsip Produk\n");
		fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		if(strcmp(produk.kode, "XXX") == 0){
			printf("Arsip Kosong\n");
		}else{
			do{
				printf("Kode : %s\n",produk.kode);
				printf("Nama Produk  : %s\n",produk.nama);
				printf("Harga : %d\n",produk.harga);
				printf("-----------------------\n");
				fscanf(newFile, "%s %s %d\n", &produk.kode, &produk.nama, &produk.harga);
			}while(strcmp(produk.kode, "XXX") != 0);
		}   
		fclose(newFile);
	}else{
		printf("Arsip Kosong\n");
	}
}

int hitungTotalProduk(){
	// Randy
}

float hitungRataProduk(){
	float total,hasil;
	int jmlhproduk=0;
	if(cekFile()==1){
		newFile=fopen("Arsip.txt","r");
		fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		do{
			total=total+produk.harga;	
			jmlhproduk++;
			fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		}while(strcmp(produk.kode, "XXX") != 0);
		hasil=total/jmlhproduk;
		fclose(newFile);
	}
	return hasil;
}

main(){
	int pilih,tp;
	float rt;
	do{
		system("cls");
		tampilMenu();
		printf("Pilih Menu : "); scanf("%d",&pilih);
		switch(pilih){
			case 1: buatArsip(); break;
			case 2: tampilArsip(); break;
			case 3 : 
				tp = hitungTotalProduk();
				printf("Total produk : %d",tp);
				break;
			case 4 :
				rt = hitungRataProduk();
				printf("Rata-rata produk : %f",rt);
				break;
			case 5: printf("Aplikasi keluar....."); break;
			default : printf("Input tidak valid !!\n");
		}
		getch();
	}while(pilih!=5);
}
