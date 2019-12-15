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
*@author Nazif Enes Kýzýlcin    nazifenes.kizilcin@stu.fsm.edu.tr
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
	
	/*Olusturdugum bu algoritmada matrix[0][1] elemanýndan baslayýp saga dogru her bir elemanýn degerini matrix[0][0]
	daki elamanýnkiyle swaplayarak devam ediyorum.Bu sekilde tamamlandýgýnda matrix bir tur saga donmus oluyor.
	ilk basta iki for ile çözmek en üstten sað en alttaki elamana kadar olan L þeklindeki kýsmý bir, diger kýsmý bir 
	olarak fakat sýnýrlarda ve artýþ azalýþý kontrol etmekte çok güclük çektim.Bu yüzden her bir kenar icin bir for
	kullandým.*/
	int t = 0;
	for(t=0;t<adimSayisi;t++){//Asagýdaki dongulerde matriximiz 1 kez saga donuyor.Bu for sayesinde girilen adimSayisi kadar dondurmus oluyoruz.						
	int arasayi = 0;
	int i = 0;
	for(i=1;i<sutunSayisi;i++){//*(*(matrix)+1) elamanýndan baslayýp satir bitene kadar **matrix ile swap...
		arasayi = *(*(matrix)+ i);
		*(*(matrix)+i) = *(*(matrix));
		*(*(matrix)) = arasayi;
		
	}
	for(i=1;i<satirSayisi;i++){ //Sag alt kosedeki elamanýn bir altýndakinden baþlýyoruz en köþe bir önceki tur degisti...
		arasayi = *(*(matrix+i)+sutunSayisi-1);
		*(*(matrix+i)+sutunSayisi-1)=*(*(matrix));
		*(*(matrix)) = arasayi;
	}
	for(i=sutunSayisi-2;i>=0;i--){//burda sað alt kösedeki elemanýn bir solundakinden baþlayýp sol alt köseye kadar gidiyoruz.....
		arasayi= *(*(matrix+satirSayisi-1)+i);
		*(*(matrix+satirSayisi-1)+i) = *(*(matrix));
		*(*(matrix)) = arasayi;
	}
	for(i=satirSayisi-2;i>0;i--){//en sol alt kösedeki elemanýn bir üstünden baslýyoruz fakat en son **matrix e geldigimizden
													//bu donme isleminin baslangýcý oldugundan onu almýyoruz 1 tur az donuyoruz
		arasayi = *(*(matrix+i));
		*(*(matrix +i)) = *(*(matrix));
		*(*(matrix)) = arasayi;
	}
	
}
	return matrix;
}

int** matrixSolaDondur(int** matrix,int adimSayisi,int satirSayisi,int sutunSayisi){
	/*Burada da yukarýda yaptýgýmýz islemlerden farklý olarak.Bu sefer ayný islemi ters yonde yaptýk. Bu degistirme
	isleminde baslangýc noktasý olarak aldýgýmýz **matrix elemaný ama bu olmak zorunda degil herhangi bir indisteki
	elemaný baslangýc noktasý alýp o nokta etrafýnda dondurme islemini gerceklestirebilirz saga ve sola donus algoritma
	larýnda.Ben kolaylýk olsun diye 0 indisindeki elemaný sectim...*/
	int t = 0;
	for(t=0;t<adimSayisi;t++){
		int arasayi = 0;
		int i = 0;
		for(i=1;i<satirSayisi;i++){//sol en ust kosedeki elemanýn bir altýndakinden baslayip sol en alt koseye kadar degisim...
			arasayi = *(*(matrix+i));
			*(*(matrix+i)) = *(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=1;i<sutunSayisi;i++){//sol en alt kosedeki elemanýn bir sagindakinden sag en alt kosedeki elamana kadar degisim...
			arasayi = *(*(matrix+satirSayisi-1)+i);
			*(*(matrix+satirSayisi-1)+i)=*(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=satirSayisi-2;i>=0;i--){ // sag en alt kosedekinden bir ustteki elemandan sag en ust kosedeki elemana kadar degisim...
			arasayi= *(*(matrix+i)+sutunSayisi-1);
			*(*(matrix+i)+sutunSayisi-1) = *(*(matrix));
			*(*(matrix)) = arasayi;
		}
		for(i=sutunSayisi-2;i>0;i--){ //sag en ustteki elemanýn bir solundaki elemandan sol en ustteki elemana kadar degisim...
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
