all:	matrixOps

matrixOps:main.o	matrixOps.o
	gcc	main.o	matrixOps.o	-o	matrixOps

main.o:main.c
	gcc	-c	main.c

matrixOps.o:	matrixOps.c	matrixOps.h
	gcc	-c	matrixOps.c

clean:	
	del .*o	matrixOps.exe
				
