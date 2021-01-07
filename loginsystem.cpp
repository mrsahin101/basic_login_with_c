#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void giris();
int basmesaj();
void dosyaoku();
void kayit();
char id_data[50][20];
char pw_data[50][20];
int main()
{
	dosyaoku();
	basmesaj();
}
void giris()
{
	int donendeger=0;
	char id[20];
	char pw[20];
	printf("Kullanici Adi:"); scanf("%s",&id);
	printf("Sifre:"); scanf("%s",&pw);
	for(int i=0;i<50;i++)
	{
		if((strcmp(id,id_data[i])==0) &	(strcmp(pw,pw_data[i])==0))
		{
			printf("Giris Basarili.Sisteme Hosgeldiniz...\n\n");
			printf("Devam Etmek icin bir tusa basiniz.....");
			system("pause");
		}
	}
	
}
int basmesaj()
{	

	int yerel=0;
	bas:
	system("CLS");
	printf("Merhaba.Otomasyona hos geldiniz....\n\n");
	printf("Sisteme kayit olmak icin 	  1 :\n");
	printf("Sisteme giris yapmak  icin 	  2 :\n"); 
	printf("Seciminiz:"); scanf("%d",&yerel);
	if(yerel==1 || yerel==2)
	{
		if (yerel==1)
		{
		kayit();
		}
		else
		{
		giris();
		}
	}
	else 
	{
		goto bas;
	}
	
}
void dosyaoku()
{
	int i=0;
	FILE *dosya;
	dosya=fopen("deneme.txt","r");
	while(!feof(dosya))
	{
		fscanf(dosya,"%s %s",id_data[i],pw_data[i]);
	//	printf("%s %s\n",id_data[i],pw_data[i]); used for testing code
		i++;
	}
//	system("pause"); used for testing code
}
void kayit()
{	
	char kadi[20];
	char pw[20];
	FILE *dosya;
	bas:
	system("CLS");
	printf("Sisteme Kayit olmak icin turkce karakter kullanmayiniz.");
	printf("En fazla 20 karakter uzunluguna izin verilmistir...\n\n");
	printf("Kullanci Adi:"); scanf("%s",&kadi);
	for (int i=0;i<50;i++)
	{
		if(strcmp(kadi,id_data[i])==0)
		{
			printf("Girdiginiz kullanci adi sistemde mevcut..Lutfen baska kullanci adi giriniz...\n\n");
			printf("Devam etmek icin bir tusa basiniz....");
			system("pause");
			goto bas;
		}
	}
	printf("Sifre:"); scanf("%s",&pw);
	dosya=fopen("deneme.txt","a");
	fprintf(dosya,"%s %s\n",kadi,pw);
	fclose(dosya);
	dosyaoku();
	basmesaj();
}


