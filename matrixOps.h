#ifndef	MATRIXOPS_H
#define	MATRIXOPS_H	
/*
*@file matrixOps.h
*@description Programin amaci, tamami kullanicidan alinan parametreler ile heap memory bolgesinde cok boyutlu bir array olusturma ve bu array uzerinde
kullanicidan alinan donus yonu,sayisi parametreleriyle secilen yonde secilen miktarda bu cok boyutlu arrayi dondurmektir.
*@assignment Odev-1
*@date 01.12.2019 Tamamen bittigi tarih
*@author Nazif Enes Kýzýlcin    nazifenes.kizilcin@stu.fsm.edu.tr
*/
int **matrixOlustur(int,int,int);
int **matrixSagaDondur(int**,int,int,int);
int **matrixSolaDondur(int**,int,int,int);
void matrixEkranaBastir(int**,int,int);

   

#endif
