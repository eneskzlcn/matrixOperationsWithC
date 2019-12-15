#include <stdio.h>
#include <stdlib.h>
#include "matrixOps.h"

/*
*@file main.c
*@description Programin amaci, tamami kullanicidan alinan parametreler ile heap memory bolgesinde cok boyutlu bir array olusturma ve bu array uzerinde
kullanicidan alinan donus yonu,sayisi parametreleriyle secilen yonde secilen miktarda bu cok boyutlu arrayi dondurmektir.
*@assignment Odev-1
*@date 01.12.2019 Tamamen bittigi tarih
*@author Nazif Enes Kýzýlcin    nazifenes.kizilcin@stu.fsm.edu.tr
*/

int main(int argc, char *argv[]) {
	//Komut satiri kullanimi icin gerekli kodlar...
	int k = 0;
	int satirSayisi = 3;
	int sutunSayisi = 4;
	int donusYonu = 0;
	int adimSayisi = 0;
	int randomElemanlarinUstSiniri = 20;
	int**matrix = matrixOlustur(satirSayisi,sutunSayisi,randomElemanlarinUstSiniri);//random olarak olusturdum hafýzada bir yerde olsun.
	int argumanSayisiSayac =0; //arguman sayisi kontrolu...s
	if(argc == 6){
		satirSayisi = atoi(*(argv+1));
		sutunSayisi = atoi(*(argv+2));
		donusYonu = atoi(*(argv+3));
		adimSayisi = atoi(*(argv+5));
		randomElemanlarinUstSiniri = atoi(*(argv+4));
		
	}
	else
	{
		printf("\n6 dan fazla yada az arguman girdiniz.Bu yuzden matrixiniz olusturulmadi.Menuye yonlendiriliyorsunuz.");
		argumanSayisiSayac++;
    }
	if(argumanSayisiSayac == 0){		
		if(satirSayisi>=2 && sutunSayisi>=2 &&(donusYonu == -1 || donusYonu == 1) && adimSayisi>=0 && randomElemanlarinUstSiniri >=4){
			free(matrix);
			matrix=matrixOlustur(satirSayisi,sutunSayisi,randomElemanlarinUstSiniri);
			printf("ILK MATRIX\n\n");
		 	matrixEkranaBastir(matrix,satirSayisi,sutunSayisi);
		 	if(donusYonu == -1){
		 		matrix = matrixSagaDondur(matrix,adimSayisi,satirSayisi,sutunSayisi);
		 	}
		 	else{
		 		matrix = matrixSolaDondur(matrix,adimSayisi,satirSayisi,sutunSayisi);
		 	}
		 	printf("\n\n\nMATRIX %d YONUNDE %d ADET DONDURULMUS HALI \n\n",donusYonu,adimSayisi);
		 	matrixEkranaBastir(matrix,satirSayisi,sutunSayisi);
			}
			else{
				printf("Argumanlari yanlis girdiniz matrix olusturulamadi.(satir,sutun>= 2,donusYonu = -1,1,randomSayiUstSinir>4 ,adimSayisi>=0 olmali)\n");
				printf("\nAna menuye donuluyor\n\n\n");
				free(matrix); //ilk basta random olusturgum array eger argumanlarla tekrar olusturulmazsa menuye yansimasin diye bellekten siliyorum...
				satirSayisi = 0;
				sutunSayisi = 0;
				randomElemanlarinUstSiniri=0;
			}
		}
			else{
				printf("\nProgramin ismi disindaki argumanlar tamsayi olmalidir.Ve programin ismi dahil toplam 6 arguman olmalidir.\n");
				}  
	donusYonu=0;   //Program menu kisminin baslangici......
	adimSayisi=0;
	int menuSecenegi = 0;
	int kontrolDonusYonu = 0;//Donus yonunun -1 yada 1 den baska deger almamasini kontrol amacli
	int i,j=0;
	int kontrolAdimSayisi = 0;
	int girisDogruMu=0;//Kullanici menu icin 1,2,3,4,5 disinda bir sey girmis mi kontrol amacli...
	char araString[10];//String to int donusumlerinde kullanicidan input alabilmek adina olusturdum.Tekrar tekrar olusturmama gerek yok...Her inputta bunu kullaniyorum.
	while(menuSecenegi != 5){
		printf("\n1. Uygulamayi Calistir \n");
		printf("2. Matrix Olustur \n");
		printf("3. Donus Yonu \n");
		printf("4. Adim Sayisi \n");
		printf("5. Exit \n");
		scanf("%s",araString);
		int kontrolSatirSayisi = satirSayisi; // yukarýda olusturdugumuz matrixin freelenip freelenmedigini kotnrol amacli olusturdum.
		menuSecenegi=atoi(araString);
		if(menuSecenegi == 0){
			printf("\nGecerli bir sayi girmediniz ana menuye tekrar yonlendiriliyorsunuz\n");
		}
		if(menuSecenegi == 1){ // burada öncelikle bir donusYonu kontrolu yapmamiz gerek
			if(donusYonu == 0){
				printf("\nAna menuye donuluyor.Lutfen uygulamayi calistirmak icin gecerli bir donus yonu secin\n");
				continue;
			}
			else if(satirSayisi==0){//Satir sayisindan kontrol edebiliriz matrix var mi yok mu.
				printf("\n Menuden 2 yi secerek gecerli bir matrix olusturun \n");
			}
			else{
				printf(" ILK MATRIX      \n\n");
				matrixEkranaBastir(matrix,satirSayisi,sutunSayisi);
				if(donusYonu == -1){
					matrix = matrixSagaDondur(matrix,adimSayisi,satirSayisi,sutunSayisi);
				}
				else{
					matrix = matrixSolaDondur(matrix,adimSayisi,satirSayisi,sutunSayisi);
				}
				printf("\n\n\n MATRIX %d YONUNDE %d ADET DONDURULMUS HALI\n\n",donusYonu,adimSayisi);
				matrixEkranaBastir(matrix,satirSayisi,sutunSayisi);
			}
		}
		if(menuSecenegi == 2){
			printf("Olusturmak istediginiz matrix icin satir sayisi girin =");
			
			scanf("%s",araString);
			satirSayisi = atoi(araString);
			if(satirSayisi<2){
				satirSayisi = 0;
				printf("\nGirdiginiz satir sayisi ikiden buyuk bir sayi olmalidir.Ana menuye yonlendiriliyorsunuz \n");
				continue;
			 }
			printf("Olusturmak istediginiz matrix icin sutun sayisi girin =");
			scanf("%s",araString);
			sutunSayisi = atoi(araString);
			if(sutunSayisi<2){
				sutunSayisi = 0;
				printf("Girdiginiz sutun sayisi ikiden buyuk bir sayi olmalidir \n");
				continue;
			}
			printf("\nOlusturmak istediginiz matrix random elamanlarin ust sinirini yazin(minimum 4 olmali).(0'dan kaca kadar olsun') =");
			scanf("%s",araString);
			randomElemanlarinUstSiniri = atoi(araString);
			if(randomElemanlarinUstSiniri < 4){
				randomElemanlarinUstSiniri=0;
				printf("Random elemanlarin ust siniri 3 ten buyuk olmali\n");
				continue;				
			}
			if(kontrolSatirSayisi != 0){//matrix zaten freeyse tekrar free etmek hata olusturu...
				free(matrix);
			}
			matrix = matrixOlustur(satirSayisi,sutunSayisi,randomElemanlarinUstSiniri);
			printf("\nMatrixiniz olusturuldu\n");
			continue;
		}
		if(menuSecenegi == 3){
			printf("Lutfen dondurmek istediginiz yonu seciniz(-1 yada 1 olmali)(Menu icin 5 girin)");
			scanf("%s",araString);
			kontrolDonusYonu = atoi(araString);
			if((kontrolDonusYonu == 1) || (kontrolDonusYonu == -1)){
				donusYonu = kontrolDonusYonu;
				printf("\nDonus yonunuz %d olarak belirlendi.Ana menuye yonlendiriliyorsunuz.\n",donusYonu);
				continue;
			}
			else if(kontrolDonusYonu==5){
					kontrolDonusYonu =0;
					break;
			}
			else{
				printf("\n Girdiginiz donus yonu gecerli degil. Ana menuye yonlendiriliyorsunuz.\n");
				continue;
			}
		}	 
	    if(menuSecenegi == 4){
			printf("Olusturdugunuz matrixi kac adim dondurmek istediginizi giriniz\n");
			scanf("%s",araString);
			kontrolAdimSayisi = atoi(araString);
			if(kontrolAdimSayisi<=0){
				printf("\n Girdiginiz adim sayisi gecerli degil.Ana menuye yonlendiriliyorsunuz\n");
				continue;
			}
			else{
				adimSayisi = kontrolAdimSayisi;
				printf("\n Adim sayiniz %d olarak belirlendi.\n",adimSayisi);
				continue;	
			}	
		}
		if(menuSecenegi == 5){
			free(matrix);
			break;
		}									
	}	
		return 0;
	}
	
	
	
	
	


