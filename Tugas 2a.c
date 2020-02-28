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
	printf("3. Update Arsip Beruntun\n");
	printf("4. Hitung Total Produk\n");
	printf("5. Hitung rata-rata total produk\n");
	printf("6. exit\n");
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
		system("cls");
		printf("Masukkan data berikut\n");
		printf("Kode : "); scanf("%s",&produk.kode);
		printf("Nama : "); scanf("%s",&produk.nama);
		printf("Harga : "); scanf("%d",&produk.harga);
		fprintf(newFile,"%s %s %d\n",produk.kode, produk.nama, produk.harga);
		printf("\nInput lagi(y/n) : "); fflush(stdin); scanf("%c",&lagi);
	}while(lagi=='y');
	fprintf(newFile,"XXX XXX XXX");
	fclose(newFile);
}

void tampilArsip(){
	system("cls");
	if(cekFile()==1){
		newFile=fopen("Arsip.txt","r");
		printf("Isi Arsip Produk\n");
		printf("-----------------------\n");
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
	int total = 0;
	if(cekFile()==1){
		newFile=fopen("Arsip.txt","r");
		fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		do{
			total=total+produk.harga;	
			fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		}while(strcmp(produk.kode, "XXX") != 0);
		fclose(newFile);
	}
	return total;
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

void updateArsip(){//menggunakan pilih urutan data
	int urutan,i;
	int jmlh=0;
	char kodelama[25][100];
	char namalama[25][100];
	int hargalama[100];
	if(cekFile()==1){
		tampilArsip();
		newFile=fopen("Arsip.txt","r");
		fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		do{
			strcpy(kodelama[jmlh],produk.kode);
			strcpy(namalama[jmlh],produk.nama);
			hargalama[jmlh] = produk.harga;
			jmlh++;
			fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		}while(strcmp(produk.kode, "XXX") != 0);
		printf("Pilih Data ke : "); scanf("%d",&urutan);
//		system("cls");
		printf("Masukkan data baru pada kode %s :\n",kodelama[urutan-1]);
		printf("Nama : "); scanf("%s",&produk.nama);
		printf("Harga : "); scanf("%d",&produk.harga);
		newFile=fopen("Arsip.txt","w");
		for(i=0; i<jmlh; i++){
			if(i==urutan-1){
				fprintf(newFile, "%s %s %d\n",kodelama[urutan-1], produk.nama, produk.harga);
				printf("Disini diganti");
			}else{
				fprintf(newFile, "%s %s %d\n",kodelama[i], namalama[i], hargalama[i]);
				printf("Disini ga diganti");
			}
		}
		fprintf(newFile,"XXX XXX XXX");
		fclose(newFile);
	}else{
		printf("Arsip Kosong\n");
	}
}

void updateArsip2(){//menggunakan pilih kode data
	int i=0;
	int jmlh=0;
	char kodebaru[25];
	char kodelama[25][100];
	char namalama[25][100];
	int hargalama[100];
	if(cekFile()==1){
		tampilArsip();
		newFile=fopen("Arsip.txt","r");
		fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		do{
			strcpy(kodelama[jmlh],produk.kode);
			strcpy(namalama[jmlh],produk.nama);
			hargalama[jmlh] = produk.harga;
			jmlh++;
			fscanf(newFile, "%s %s %d\n",&produk.kode, &produk.nama, &produk.harga );
		}while(strcmp(produk.kode, "XXX") != 0);
		printf("Masukan Kode yang akan diubah : "); scanf("%s",&kodebaru);
//		system("cls");
		printf("Masukkan data baru pada kode %s :\n",kodebaru);
		printf("Nama : "); scanf("%s",&produk.nama);
		printf("Harga : "); scanf("%d",&produk.harga);
		newFile=fopen("Arsip.txt","w");
		for(i=0;i<jmlh;i++){
			if(strcmp(kodebaru,kodelama[i])==0){
				fprintf(newFile, "%s %s %d\n",kodebaru, produk.nama, produk.harga);
				printf("Disini diganti");
			}else{
				fprintf(newFile, "%s %s %d\n",kodelama[i], namalama[i], hargalama[i]);
				printf("Disini ga diganti");
			}
		}
		fprintf(newFile,"XXX XXX XXX");
		fclose(newFile);
	}else{
		printf("Arsip Kosong\n");
	}
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
			case 3: updateArsip2(); break;
			case 4 : 
				tp = hitungTotalProduk();
				printf("Total produk : %d",tp);
				break;
			case 5 :
				rt = hitungRataProduk();
				printf("Rata-rata produk : %f",rt);
				break;
			case 6: printf("Aplikasi keluar....."); break;
			default : printf("Input tidak valid !!\n");
		}
		getch();
	}while(pilih!=6);
}

