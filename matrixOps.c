#ifndef  MATRIXOPS_H
#define  MATRIXOPS_H
#include <time.h>
#include "matrixOps.h"
#include <stdlib.h>
#include <stdio.h>

/*
*@file matrixOps.c
*@description Programin amaci, tamami kullanicidan alinan parametreler ile heap memory bolgesinde cok boyutlu bir array olusturma ve bu array uzerinde
kullanicidan alinan donus yonu,sayisi parametreleriyle secilen yonde secilen miktarda bu cok boyutlu arrayi dondurmektir.
*@assignment Odev-1
*@date 01.12.2019 Tamamen bittigi tarih
*@author Nazif Enes K�z�lcin    nazifenes.kizilcin@stu.fsm.edu.tr
*/
int** matrixOlustur(int satirSayisi,int sutunSayisi,int randomElemanlarinUstSiniri){
	srand(time(NULL));
	int **matrix = (int **)malloc(sizeof(int *) * satirSayisi);//int turune isaret eden pointerlari tutan bir dizi icin yer ayiriyoruz.Bu pointerlarin
	int i = 0;												//her biri bir dizinin taban adresini olusturacak yani her bir satir kendi basina bir array
	int j = 0;												//olacak ve biz bu adresler sayesinde bir dimentional array elde etmis oluyoruz...			
    for (i=0; i<satirSayisi; i++) {
         *(matrix+i) = (int *)malloc(sizeof(int)*sutunSayisi); //her bir satir bir array demistik ve bu adreslere gidip satir sayisi kadar eleman
		}														//icin yer ayiriyoruz.Her bir satir yani diger bir deyisle her bir array icin
	for(i=0;i<satirSayisi;i++){									//sutun sayisi kadar int gelecegini soyleyip bunlar icin yer istiyoruz heapten...		
		for(j=0;j<sutunSayisi;j++){
			*(*(matrix+i)+j) = rand()%randomElemanlarinUstSiniri; //olusturdugumuz dimentional arraya pointer aritmetigiyle deger random deger atama...
		}
	}
	return matrix;
}

int** matrixSagaDondur(int ** matrix,int adimSayisi,int satirSayisi,int sutunSayisi){
	
	/*Olusturdugum bu algoritmada matrix[0][1] eleman�ndan baslay�p saga dogru her bir eleman�n degerini matrix[0][0]
	daki elaman�nkiyle swaplayarak devam ediyorum.Bu sekilde tamamland�g�nda matrix bir tur saga donmus oluyor.
	ilk basta iki for ile ��zmek en �stten sa� en alttaki elamana kadar olan L �eklindeki k�sm� bir, diger k�sm� bir 
	olarak fakat s�n�rlarda ve art�� azal��� kontrol etmekte �ok g�cl�k �ektim.Bu y�zden her bir kenar icin bir for
	kulland�m.*/
	int t = 0;
	for(t=0;t<adimSayisi;t++){//Asag�daki dongulerde matriximiz 1 kez saga donuyor.Bu for sayesinde girilen adimSayisi kadar dondurmus oluyoruz.						
	int arasayi = 0;
	int i = 0;
	for(i=1;i<sutunSayisi;i++){//*(*(matrix)+1) elaman�ndan baslay�p satir bitene kadar **matrix ile swap...
		arasayi = *(*(matrix)+ i);
		*(*(matrix)+i) = *(*(matrix));
		*(*(matrix)) = arasayi;
		
	}
	for(i=1;i<satirSayisi;i++){ //Sag alt kosedeki elaman�n bir alt�ndakinden ba�l�yoruz en k��e bir �nceki tur degisti...
		arasayi = *(*(matrix+i)+sutunSayisi-1);
		*(*(matrix+i)+sutunSayisi-1)=*(*(matrix));
		*(*(matrix)) = arasayi;
	}
	for(i=sutunSayisi-2;i>=0;i--){//burda sa� alt k�sedeki eleman�n bir solundakinden ba�lay�p sol alt k�seye kadar gidiyoruz.....
		arasayi= *(*(matrix+satirSayisi-1)+i);
		*(*(matrix+satirSayisi-1)+i) = *(*(matrix));
		*(*(matrix)) = arasayi;
	}
	for(i=satirSayisi-2;i>0;i--){//en sol alt k�sedeki eleman�n bir �st�nden basl�yoruz fakat en son **matrix e geldigimizden
													//bu donme isleminin baslang�c� oldugundan onu alm�yoruz 1 tur az donuyoruz
		arasayi = *(*(matrix+i));
		*(*(matrix +i)) = *(*(matrix));
		*(*(matrix)) = arasayi;
	}
	
}
	return matrix;
}

int** matrixSolaDondur(int** matrix,int adimSayisi,int satirSayisi,int sutunSayisi){
	/*Burada da yukar�da yapt�g�m�z islemlerden farkl� olarak.Bu sefer ayn� islemi ters yonde yapt�k. Bu degistirme
	isleminde baslang�c noktas� olarak ald�g�m�z **matrix eleman� ama bu olmak zorunda degil herhangi bir indisteki
	eleman� baslang�c noktas� al�p o nokta etraf�nda dondurme islemini gerceklestirebilirz saga ve sola donus algoritma
	lar�nda.Ben kolayl�k olsun diye 0 indisindeki eleman� sectim...*/
	int t = 0;
	for(t=0;t<adimSayisi;t++){
		int arasayi = 0;
		int i = 0;
		for(i=1;i<satirSayisi;i++){//sol en ust kosedeki eleman�n bir alt�ndakinden baslayip sol en alt koseye kadar degisim...
			arasayi = *(*(matrix+i));
			*(*(matrix+i)) = *(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=1;i<sutunSayisi;i++){//sol en alt kosedeki eleman�n bir sagindakinden sag en alt kosedeki elamana kadar degisim...
			arasayi = *(*(matrix+satirSayisi-1)+i);
			*(*(matrix+satirSayisi-1)+i)=*(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=satirSayisi-2;i>=0;i--){ // sag en alt kosedekinden bir ustteki elemandan sag en ust kosedeki elemana kadar degisim...
			arasayi= *(*(matrix+i)+sutunSayisi-1);
			*(*(matrix+i)+sutunSayisi-1) = *(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=sutunSayisi-2;i>0;i--){ //sag en ustteki eleman�n bir solundaki elemandan sol en ustteki elemana kadar degisim...
			arasayi = *(*(matrix)+i);
			*(*(matrix)+i) = *(*(matrix));
			*(*(matrix)) = arasayi;
		}
	}	
	return matrix;
}

void matrixEkranaBastir(int**matrix,int satirSayisi,int sutunSayisi){
	int i,j = 0;
	for(i = 0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d \t",*(*(matrix+i)+j));
		}
		printf("\n");
	}
	printf("\n\n");
}	





#endif
