/*
Program: Öðrenci Ýþleri Otomasyon Sistemi
Hazýrlayan & Kodlayan: Berkay Asrýn FINDIK
Site: www.asrinfindik.net
Bismillahirahmanirrahim
Hello World!
*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <conio.h>
//#include <dos.h>
#include <process.h>
//#include <file.h>
#include <windows.h>
/*#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
*/

struct ogrenci
{
	char * isim;
	char * disim;
	char * soyisim;
	char * no;
	char * dtarihi;
	char * bolum;
};

int main(void)
{
	typedef ogrenci bilgiler;
	char c;
	int anamenusecim;
	int oimenusecim;
	int dimenusecim;
	int rmenusecim;
	//int ramenusecim;
	system("COLOR 0E");
	printf("Ogrenci isleri otomasyonuna hos geldiniz. Lutfen menuden yapmak istediginiz islemi secip basindaki numarayi tuslayiniz:\n\n");
	printf("1) Ogrenci Islemleri\n");
	printf("2) Ders Islemleri\n");
	printf("3) Raporlar\n");
	printf("4) Cikis\n\n");
	
	printf("Lutfen numarayi giriniz: ");
	scanf("%d" , &anamenusecim);
	if( anamenusecim == 1 )
	{
		system("cls");
		printf("Ogrenci Islemleri Menusu\n\n");
		printf("1) Yeni Ogrenci Kayit\n");
		printf("2) Mevcut Ogrenci Kayit Guncelleme\n");
		printf("3) Ogrenci Silme\n");
		printf("4) Ana menuye don.\n\n");
		
		printf("Lutfen numarayi giriniz: ");
		scanf("%d" , &oimenusecim);
		if( oimenusecim == 1 )
		{
			system("cls");
			bilgiler ogrencinin;
			ogrencinin.isim = (char*)malloc(sizeof(char)*20);
			ogrencinin.disim = (char*)malloc(sizeof(char)*20);
			ogrencinin.soyisim = (char*)malloc(sizeof(char)*20);
			ogrencinin.no = (char*)malloc(sizeof(char)*20);
			ogrencinin.dtarihi = (char*)malloc(sizeof(char)*20);
            ogrencinin.bolum = (char*)malloc(sizeof(char)*20);
            printf("Ogrencinin adini giriniz: ");
            scanf("%s",ogrencinin.isim);
            printf("Ogrencinin ikinci adiniz giriniz: ");
            scanf("%s",ogrencinin.disim);
            printf("Ogrencinin soyadini giriniz: ");
            scanf("%s",ogrencinin.soyisim);
            printf("Ogrencinin no giriniz: ");
            scanf("%s",ogrencinin.no);
            printf("Ogrencinin dogum tarihini giriniz: ");
            scanf("%s",ogrencinin.dtarihi);
            printf("Ogrencinin bolumunu giriniz: ");
            scanf("%s",ogrencinin.bolum);
            printf("\n\nKayit ediliyor...\n\n");
			FILE *ogrencilistesi = fopen("ogrenciler.txt","a");
            fprintf(ogrencilistesi,"%s\t %s\t %s\t %s\t %s\t %s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
			fclose(ogrencilistesi);
			Sleep(2000);
			printf("Kayit basari ile gerceklestirildi.\n\n");
			Sleep(2000);
			printf("Ana menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();	
		}
		if( oimenusecim == 2 )
		{
			system("cls");
			FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
                 char * no;
                 printf("Ogrencinin no giriniz: ");
                 scanf("%s",no);
                 while(!feof(ogrencilistesi))
				 {
                   bilgiler ogrencinin;
                   fscanf(ogrencilistesi,"%s %s %s %s %s %s",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                   if(strcmp(ogrencinin.no,no)==0)
				   {
                       printf("%s %s %s %s %s %s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                   }                            
                 }     
            fclose(ogrencilistesi);
		}
		if( oimenusecim == 3 )
		{
			
		}
		if( oimenusecim == 4 )
		{
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();
		}
	}	
	if( anamenusecim == 2 )
	{
		system("cls");
		printf("Ders Islemleri Menusu\n\n");
		printf("1) Ogrenci Ders Secimi Yapma\n");
		printf("2) Ogrenci Ders Secimi Silme\n");
		printf("3) Ogrenci Ders Notu Giris\n");
		printf("4) Ogrenci Ders Notu Goruntuleme\n");
		printf("5) Ana menuye don.\n\n");
		
		printf("Lutfen numarayi giriniz: ");
		scanf("%d" , &dimenusecim);
		if( dimenusecim == 1 )
		{
			
		}
		if( dimenusecim == 2 )
		{
			
		}
		if( dimenusecim == 3 )
		{
			
		}
		if( dimenusecim == 4 )
		{
			
		}
		if( dimenusecim == 5 )
		{
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();
		}
	}
	if( anamenusecim == 3 )
	{
		system("cls");
		printf("Raporlar Menusu\n\n");
		printf("1) Ogrenci Transkripti\n");
		printf("2) Tum Ogrencileri Listele\n");
		printf("3) Ana menuye don.\n\n");
		
		printf("Lutfen numarayi giriniz: ");
		scanf("%d" , &rmenusecim);
		if( rmenusecim == 1 )
		{
			
		}
		if( rmenusecim == 2 )
		{
			system("cls");
			printf("Ogrenci Listesi\n\n");
			printf("Ad\t Ikinci Ad\t Soyad\t No\t Dogum Tarihi\t Bolum\n\n");
			FILE *ogrencilistesi;
    		char ch;
    		ogrencilistesi = fopen("ogrenciler.txt", "r");
    		do
			{
    			ch = getc(ogrencilistesi);
    			printf("%c", ch);
    		} 
			while (ch != EOF);
			fclose(ogrencilistesi);
			Sleep(3000);
    		printf("\n\nIslem tamamlandi.", ch);
    		printf("\n\n30 saniye icinde ana menuye donulecek.\n");
    		Sleep(30000);
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();	
		}
		if( rmenusecim == 3 )
		{
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();
		}
	}
	if( anamenusecim == 4 )
	{
		char cikissecim;
		printf("\nProgramdan cikmak istediginize emin misiniz? (E/H)\n\n");
		printf("Cevabiniz: ");
		scanf(" %c" , &cikissecim);
		while (cikissecim == 'e' || cikissecim == 'E' || cikissecim == 'h' || cikissecim == 'H')
			{
				if (cikissecim == 'e' || cikissecim == 'E')
				{
					system("COLOR 0C");
					printf("\nCikis yapiliyor...");
					Sleep(1500);
					exit(1);
				}
				else	
				if (cikissecim == 'h' || cikissecim == 'H')
				{
					printf("\nProgramdan cikis islemi iptal edildi.\n\n");
					Sleep(2000);
					printf("Ana menuye geri donuyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				} 
				else
				{
					printf("Cevabýnýz sadece (E)vet yada (H)ayýr olabilir!");
				}
			}
	}
	else
	{
		system("COLOR 0C");
		printf("\aHatali giris yaptiniz!\n\n");
		Sleep(2000);
		printf("Islem geri aliniyor...");
		Sleep(3000);
		system("cls");
		main();
	}
	return 1;
}









