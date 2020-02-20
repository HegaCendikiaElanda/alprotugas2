#include<stdio.h>
#include<string.h>
#include<conio.h>

FILE *newFile;

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

void buatArsip(){
	char lagi;
	newFile = fopen("Arsip.txt","w");
	do{
		printf("Masukkan data berikut\n");
		printf("Kode : "); scanf("%s",&produk.kode);
		printf("Nama : "); scanf("%s",&produk.nama);
		printf("Harga : "); scanf("%d",&produk.harga);
		fprintf(newFile,"%s %s %d\n",produk.kode, produk.nama, produk.harga);
		printf("Input lagi(y/n) : "); scanf("%c",&lagi);
	}while(lagi=='y');
	fprintf(newFile,"XXX XXX XXX");
	fclose(newFile);
}

void tampilArsip(){
	//rian
}

int hitungTotalProduk(){
	int totalHarga = 0;
	// randi
	return totalHarga;
}

int hitungRataProduk(){
	int rataProduk = 0;
	//nenden
	return rataProduk;
}

main(){
	int pilih,tp,rt;
	do{
		system("cls");
		tampilMenu();
		printf("Pilih Menu : "); scanf("%d",&pilih);
		switch(pilih){
			case 1: buatArsip(); break;
			case 2: tampilArsip(); break;
			case 3 : 
				tp = hitungTotalProduk();
				printf("Total produk : %d"),tp;
				break;
			case 4 :
				rt = hitungRataProduk();
				printf("Rata-rata produk : %d",rt);
				break
			case 5: printf("Aplikasi keluar....."); break;
			default : printf("Input tidak valid !!\n");
		}
		getch();
	}while(pilih!=5);
}
