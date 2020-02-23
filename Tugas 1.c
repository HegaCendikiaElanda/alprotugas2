#include <stdio.h>
#include <conio.h>
#include <string.h>

FILE *newFile;
char namaFile[100];
char removeFile[100];
char masukFile[100];
char keluarFile[100];
int p,del,size,cek;

void tampilMenu(){
	printf("Pilih Salah satu menu dibawah :\n");
	printf("1. Buat File teks\n");
	printf("2. Tambahkan data file\n");
	printf("3. Tampilkan data file\n");
	printf("4. Hapus file teks\n");
	printf("5. exit\n\n");
	printf("Pilih Menu : ");
	scanf("%d",&p);
}

int cekFile(char nama[100]){
	int status;
	newFile = fopen(nama,"r");
	if (newFile == NULL){
		status = 0;
	}else{
		status = 1;
	}
	fclose(nama);
	return status;
}

void buatFile(){
	printf("Masukan nama file : ");
	fflush(stdin);
	gets(namaFile);
	strcat(namaFile,".txt");
	cek = cekFile(namaFile);
	if(cek == 1){
		printf("File tersebut sudah ada");
	}else{
		newFile = fopen(namaFile,"w");
		if(newFile != NULL){
			printf("File %s telah dibuat !!\n",namaFile);
			fclose(newFile);
		}else{
			printf("File %s tidak bisa dibuat !!\n");
			fclose(newFile);
		}
	}
}

void inputFile(){
	cek = cekFile(namaFile);
	if (cek == 0){
		printf("Maaf anda harus membuat file terlebih dahulu !!");
	}else{
		printf("Masukan Kata atau Kalimat : ");
		fflush(stdin);
		gets(masukFile);
		fclose(newFile);
		newFile = fopen(namaFile,"a");
		fprintf(newFile,"%s",masukFile);
		printf("Kata atau Kalimat %s berhasil dimasukkan !!\n",masukFile);
	}
	fclose(newFile);
}

void outputFile(){
	cek = cekFile(namaFile);
	if(cek == 0){
		printf("Maaf anda harus membuat file terlebih dahulu !!");
	}else{
		fgets(keluarFile,100,newFile);
		fseek(newFile, 0, SEEK_END);
		size = ftell(newFile);
		if(size == 0){
			printf("Maaf isi file masih kosong");
		}else{
			printf("Kata atau kalimat yang tertulis dalam file adalah : %s\n",keluarFile);
		}
	}
	fclose(newFile);
}

void deleteFile(){
	cek = cekFile(namaFile);
	if(cek == 0){
		printf("Maaf anda harus membuat file terlebih dahulu !!");
	}else{
		del = remove(namaFile);
		if (del == 0){
			printf("File %s telah dihapus !! \n",namaFile);
		}else{
			perror("File tidak bisa dihapus / tidak ada !!\n");
		}
	}
}

int main(){
	do{
		system("cls");
		tampilMenu();
		switch(p){
			case 1:
				buatFile();
				break;
			case 2:
				inputFile();
				break;
			case 3:
				outputFile();
				break;
			case 4:
				deleteFile();
				break;
			case 5:
				return 0;
				break;
			default:
				printf("Menu yang anda masukan tidak Valid");
		}
		getch();
	}while(p!=5);
}
