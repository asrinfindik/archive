/*
Program: Öðrenci Ýþleri Otomasyon Sistemi
Hazýrlayan & Kodlayan: Berkay Asrýn FINDIK
Site: www.asrinfindik.net
Bismillahirahmanirrahim
Hello World!
*/

//#include <a_samp> HERÞEYÝN BAÞLADIÐI YER :')

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
	char isim[100];
	char disim[100];
	char soyisim[100];
	char no[100];
	char dtarihi[100];
	char bolum[100];
}ogrencinin;

struct ders
{
	char kodu[100];
	char adi[100];
	char notu[100];
}dersin;

int main(void)
{
	char c;
	int anamenusecim;
	int oimenusecim;
	int dimenusecim;
	int rmenusecim;
	system("COLOR 0F");
	printf("Ogrenci isleri otomasyonuna hos geldiniz. \n\n");
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
			printf("Yeni Ogrenci Kayit Menusu\n\n");
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
            fprintf(ogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
			fclose(ogrencilistesi);
			Sleep(2000);
			printf("\aKayit basari ile gerceklestirildi.\n\n");
			Sleep(2000);
			printf("Ana menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();	
		}
		if( oimenusecim == 2 )
		{ 
			system("cls");
            char no[30];
            printf("Ogrenci Kayit Guncelleme Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",no);
            int kontrol;
			FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
			FILE *yogrencilistesi = fopen("yogrenciler.txt","w");
            kontrol = 0;
		   	while(!feof(ogrencilistesi))
			{
                fscanf(ogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                if(strcmp(ogrencinin.no,no)==0)
				{
					kontrol++;
					printf("\n\nGuncelleme ekrani hazirlaniyor...\n\n");
					Sleep(2000);
					printf("Ogrencinin adini giriniz: ");
            		scanf("%s",ogrencinin.isim);
            		printf("Ogrencinin ikinci adiniz giriniz: ");
            		scanf("%s",ogrencinin.disim);
            		printf("Ogrencinin soyadini giriniz: ");
            		scanf("%s",ogrencinin.soyisim);
            		printf("Ogrencinin no giriniz: ");
            		scanf("%s",ogrencinin.no);
            		printf("Ogrencinin dogum yili giriniz: ");
           			scanf("%s",ogrencinin.dtarihi);
            		printf("Ogrencinin bolumunu giriniz: ");
            		scanf("%s",ogrencinin.bolum);
            		printf("\n\nOgrenci bilgileri guncelleniyor...\n\n");
            		fprintf(yogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                }
				else
				{
					fprintf(yogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);	
				}                   
            }
            fclose(yogrencilistesi);
            fclose(ogrencilistesi);
			remove("ogrenciler.txt");
			Sleep(1000);
			rename("yogrenciler.txt","ogrenciler.txt");
			Sleep(1000);
			
			if(kontrol==0)
            {
				printf("\a\n\nOgrenci bulunamadi.\n\n");
				fclose(yogrencilistesi);
            	fclose(ogrencilistesi);
            	remove("yogrenciler.txt");
    			Sleep(2000);
				printf("\nAna menuye geri yonlendiriliyorsunuz...");
				Sleep(1500);
				system("cls");
				main();    
			}
			
    		printf("\a\n\nIslem tamamlandi.");
    		Sleep(2000);
			printf("\n\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();
		}
		if( oimenusecim == 3 )
		{
			system("cls");
			char ogrencisilmesecim;
            char no[30];
            printf("Ogrenci Silme Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",no);
            int kontrol;
			printf("\nOgrenci kaydini silmek istediginize emin misiniz? (E/H)\n\n");
			printf("Cevabiniz: ");
			scanf(" %c" , &ogrencisilmesecim);
			kontrol = 0;
			while (ogrencisilmesecim == 'e' || ogrencisilmesecim == 'E' || ogrencisilmesecim == 'h' || ogrencisilmesecim == 'H')
			{
				if (ogrencisilmesecim == 'e' || ogrencisilmesecim == 'E')
				{
					kontrol++;
					printf("\n\nOgrenci siliniyor...");
					FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
					FILE *yogrencilistesi = fopen("yogrenciler.txt","w");
            		while(!feof(ogrencilistesi))
            		{
            			fscanf(ogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                		if(strcmp(ogrencinin.no,no)==0)
                		{
                			
			 			}
			 			else
			 			{
			 				fprintf(yogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
						}
					}
					fclose(ogrencilistesi);
					fclose(yogrencilistesi);
					remove("ogrenciler.txt");
					Sleep(1000);
					rename("yogrenciler.txt","ogrenciler.txt");
					Sleep(1000);
    				
    				if(kontrol==0)
            		{
						printf("\a\n\nOgrenci bulunamadi.\n\n");
						fclose(yogrencilistesi);
            			fclose(ogrencilistesi);
            			remove("yogrenciler.txt");
    					Sleep(2000);
						printf("\nAna menuye geri yonlendiriliyorsunuz...");
						Sleep(1500);
						system("cls");
						main();    
					}
					
					printf("\a\n\nIslem tamamlandi.");
    				Sleep(2000);
					printf("\n\nAna menuye geri yonlendiriliyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
				else if (ogrencisilmesecim == 'h' || ogrencisilmesecim == 'H')
				{
					printf("\a\nIslem iptal edildi.\n\n");
					Sleep(2000);
					printf("Ana menuye geri donuyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
				else
				{
					printf("\a\nYanlis islem yapildi.\n\n");
					Sleep(2000);
					printf("Ana menuye geri donuyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
			}
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
		printf("3) Ogrenci Ders Notu Girme\n");
		printf("4) Ogrenci Ders Notu Goruntuleme\n");
		printf("5) Ana menuye don.\n\n");
		
		printf("Lutfen numarayi giriniz: ");
		scanf("%d" , &dimenusecim);
		if( dimenusecim == 1 )
		{
			system("cls");
            char no[30];
            printf("Ogrenci Ders Secimi Yapma Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",no);
            int kontrol;
			FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
			kontrol = 0;
            while(!feof(ogrencilistesi))
			{
                fscanf(ogrencilistesi,"%s\t%s\t%s\t%s\t%s\t%s\n",ogrencinin.isim,ogrencinin.disim,ogrencinin.soyisim,ogrencinin.no,ogrencinin.dtarihi,ogrencinin.bolum);
                if(strcmp(ogrencinin.no,no)==0)
				{
					kontrol++;
					printf("\nDersin kodunu giriniz: ");
            		scanf("%s",dersin.kodu);
            		printf("Dersin adini giriniz: ");
            		scanf("%s",dersin.adi);
            		printf("\n\nKayit ediliyor...\n\n");
					FILE *derslistesi = fopen("ogrenci_dersler.txt","a");
            		fprintf(derslistesi,"%s\t%s\t%s\n",ogrencinin.no,dersin.kodu,dersin.adi);
            		fclose(derslistesi);		
                }
            }
        fclose(ogrencilistesi);
		
		if(kontrol==0)
		{
			printf("\a\n\nOgrenci bulunamadi.\n\n");
    		Sleep(2000);
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();  
		}
		
		Sleep(2000);
		printf("\aKayit basari ile gerceklestirildi.\n\n");
		Sleep(2000);
		printf("Ana menuye geri yonlendiriliyorsunuz...");
		Sleep(1500);
		system("cls");
		main();
		}
		if( dimenusecim == 2 )
		{
			system("cls");
			char oderssilmesecim;
            char ogrencino[30];
            char derskodu[30];
            printf("Ogrenci Ders Secimi Silme Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",ogrencino);
            printf("Silmek istediginiz ders kodunu giriniz: ");
            scanf("%s",derskodu);
            int ogrencikontrol;
            int derskontrol;
			printf("\nOgrencinin ders secimi kaydini silmek istediginize emin misiniz? (E/H)\n\n");
			printf("Cevabiniz: ");
			scanf(" %c" , &oderssilmesecim);
			ogrencikontrol = 0;
			derskontrol = 0;
			while (oderssilmesecim == 'e' || oderssilmesecim == 'E' || oderssilmesecim == 'h' || oderssilmesecim == 'H')
			{
				if (oderssilmesecim == 'e' || oderssilmesecim == 'E')
				{
					ogrencikontrol++;
					derskontrol++;
					printf("\n\nOgrencinin ders secimi siliniyor...");
					FILE *derslistesi = fopen("ogrenci_dersler.txt","r");
					FILE *yderslistesi = fopen("yogrenci_dersler.txt","w");
            		while(!feof(derslistesi))
            		{
            			fscanf(derslistesi,"%s\t%s\t%s\n",ogrencinin.no,dersin.kodu,dersin.adi);
                		if(strcmp(ogrencinin.no,ogrencino)==0 && strcmp(dersin.kodu,derskodu)==0)
                		{
                			
			 			}
			 			/*else if(strcmp(ogrencinin.no,ogrencino)!=0 || strcmp(dersin.kodu,derskodu)!=0)
                		{
                			printf("Ogrenci veya ders bulunamadi.");
			 				Sleep(2000);
							printf("\nAna menuye geri yonlendiriliyorsunuz...");
							Sleep(1500);
							system("cls");
							main();
						}
			 			else if(strcmp(ogrencinin.no,ogrencino)==0)
			 			{
			 				printf("Ders bulunamadi.");
			 				Sleep(2000);
							printf("\nAna menuye geri yonlendiriliyorsunuz...");
							Sleep(1500);
							system("cls");
							main();
						}
						else if(strcmp(dersin.kodu,derskodu)==0)
			 			{
			 				printf("Ogrenci bulunamadi.");
			 				Sleep(2000);
							printf("\nAna menuye geri yonlendiriliyorsunuz...");
							Sleep(1500);
							system("cls");
							main();
						}*/
			 			else
			 			{
			 				fprintf(yderslistesi,"%s\t%s\t%s\n",ogrencinin.no,dersin.kodu,dersin.adi);
						}
					}
					fclose(derslistesi);
					fclose(yderslistesi);
					remove("ogrenci_dersler.txt");
					Sleep(1000);
					rename("yogrenci_dersler.txt","ogrenci_dersler.txt");
					Sleep(1000);
    				
    				if(ogrencikontrol==0 && derskontrol==0)
            		{
						printf("\a\n\nOgrenci ve ders bulunamadi.\n\n");
						fclose(yderslistesi);
            			fclose(derslistesi);
            			remove("yogrenci_dersler.txt");
    					Sleep(2000);
						printf("\nAna menuye geri yonlendiriliyorsunuz...");
						Sleep(1500);
						system("cls");
						main();    
					}
					
					printf("\a\n\nIslem tamamlandi.");
    				Sleep(2000);
					printf("\nAna menuye geri yonlendiriliyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
				else if (oderssilmesecim == 'h' || oderssilmesecim == 'H')
				{
					printf("\a\nIslem iptal edildi.\n\n");
					Sleep(2000);
					printf("Ana menuye geri donuyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
				else
				{
					printf("\a\nYanlis islem yapildi.\n\n");
					Sleep(2000);
					printf("Ana menuye geri donuyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}
			}
		}
		if( dimenusecim == 3 )
		{
			system("cls");
            char ogrencino[30];
            char derskodu[30];
            char dersnotu[30];
            printf("Ogrenci Ders Notu Girme Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",ogrencino);
            printf("Ders kodunu giriniz: ");
            scanf("%s",derskodu);
            int ogrencikontrol;
            int derskontrol;
			FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
			FILE *derslistesi = fopen("ogrenci_dersler.txt","r");
			ogrencikontrol = 0;
			derskontrol = 0;
            while(!feof(derslistesi))
			{
                fscanf(derslistesi,"%s\t%s\t%s\n",ogrencinin.no,dersin.kodu,dersin.adi);
                if(strcmp(ogrencinin.no,ogrencino)==0 && strcmp(dersin.kodu,derskodu)==0)
				{
					ogrencikontrol++;
					derskontrol++;
					printf("Ogrencinin notunu giriniz: ");
            		scanf("%s",dersin.notu);
            		printf("\n\nKayit ediliyor...\n\n");
					FILE *dersnotlarilistesi = fopen("ogrenci_ders_notlari.txt","a");
            		fprintf(dersnotlarilistesi,"%s\t%s\t%s\n",ogrencinin.no,dersin.kodu,dersin.notu);
            		fclose(dersnotlarilistesi);		
                }
            }
        fclose(derslistesi);
        fclose(ogrencilistesi);
		
		if(ogrencikontrol==0 && derskontrol==0)
		{
			printf("\a\n\nOgrenci ve ders bulunamadi.\n\n");
    		Sleep(2000);
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();  
		}
		
		Sleep(2000);
		printf("\aKayit basari ile gerceklestirildi.\n\n");
		Sleep(2000);
		printf("Ana menuye geri yonlendiriliyorsunuz...");
		Sleep(1500);
		system("cls");
		main();
		}
		if( dimenusecim == 4 )
		{
			system("cls");
            char ogrencino[30];
            char derskodu[30];
            char dersnotu[30];
            printf("Ogrenci Ders Notu Gorme Menusu\n\n");
            printf("Ogrencinin no giriniz: ");
            scanf("%s",ogrencino);
            printf("Ders kodunu giriniz: ");
            scanf("%s",derskodu);
            int ogrencikontrol;
            int derskontrol;
			FILE *ogrencilistesi = fopen("ogrenciler.txt","r");
			FILE *derslistesi = fopen("ogrenci_dersler.txt","r");
			FILE *dersnotlarilistesi = fopen("ogrenci_ders_notlari.txt","r");
			ogrencikontrol = 0;
			derskontrol = 0;
            printf("No\tDers Kodu\tDers Notu\n\n");
			while(!feof(derslistesi))
			{
                fscanf(derslistesi,"%s\t%s\t\t%s\n",ogrencinin.no,dersin.kodu,dersin.notu);
                if(strcmp(ogrencinin.no,ogrencino)==0 && strcmp(dersin.kodu,derskodu)==0)
				{
					ogrencikontrol++;
					derskontrol++;
					printf("%s\t%s\t\t%s\n",ogrencinin.no,dersin.kodu,dersin.notu);	
                }
                /*else if(strcmp(ogrencinin.no,ogrencino)!=0 || strcmp(dersin.kodu,derskodu)!=0)
                {
                	printf("Ogrenci veya ders bulunamadi.");
			 		Sleep(2000);
					printf("\nAna menuye geri yonlendiriliyorsunuz...");
					Sleep(1500);
					system("cls");
					main();
				}*/
            }
        fclose(dersnotlarilistesi);
        fclose(derslistesi);
        fclose(ogrencilistesi);
		
		if(ogrencikontrol==0 && derskontrol==0)
		{
			printf("\a\n\nOgrenci ve ders bulunamadi.\n\n");
    		Sleep(2000);
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();  
		}
		
		Sleep(2000);
		printf("\aKayit basari ile gerceklestirildi.\n\n");
		Sleep(2000);
		printf("Ana menuye geri yonlendiriliyorsunuz...");
		Sleep(1500);
		system("cls");
		main();
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
			system("cls");
			printf("Ogrenci Transkript Menusu\n\n");
			printf("Ogrenci Notlari\n\n");
			printf("Ogrenci No\t\tDers Kodu\tDers Notu\n\n");
			FILE *ogrencidersnotlari = fopen("ogrenci_ders_notlari.txt", "r");
    		char ch;
    		do
			{
    			ch = getc(ogrencidersnotlari);
    			printf("%c", ch);
    		} 
			while (ch != EOF);
			fclose(ogrencidersnotlari);
			Sleep(3000);
    		printf("\a\n\nIslem tamamlandi.");
    		Sleep(2000);
    		printf("\n\n30 saniye icinde ana menuye donulecek.\n");
    		Sleep(30000);
			printf("\nAna menuye geri yonlendiriliyorsunuz...");
			Sleep(1500);
			system("cls");
			main();	
		}
		if( rmenusecim == 2 )
		{
			system("cls");
			printf("Kayitli Ogrenciler Menusu\n\n");
			printf("Ogrenci Listesi\n\n");
			printf("Ad\tIkinci Ad\tSoyad\tNo\tDogum Yili\tBolum\n\n");
			FILE *ogrencilistesi = fopen("ogrenciler.txt", "r");
    		char ch;
    		do
			{
    			ch = getc(ogrencilistesi);
    			printf("%c", ch);
    		} 
			while (ch != EOF);
			fclose(ogrencilistesi);
			Sleep(3000);
    		printf("\a\n\nIslem tamamlandi.");
    		Sleep(2000);
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
					printf("\a\nProgramdan cikis islemi iptal edildi.\n\n");
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
		Sleep(1500);
		system("cls");
		main();
	}
	return 1;
}









