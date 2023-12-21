#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "diag_elem.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("\nMacierz A:\n");
	printToScreen(A);
	printf("Macierz B:\n");
	printToScreen(b);
	res = diag_elem(A,b);
	if(res == 0)
	{	
		printf("\nWybor elementu glownego\n");
		printf("\nMacierz A:\n");
		printToScreen(A);
		printf("Macierz B:\n");
		printToScreen(b);
	}
	if(res == 2)
	{
		fprintf(stderr, "blad nieprawidlowych rozmiarow macierzy\n");
		return 1;

	}

	res = eliminate(A,b);
	
	if(res==1)
	{
		fprintf(stderr, "Macierz osobliwa - dzielenie przez 0\n");
		return 1;
	}
	
	if(res==2)
	{
		fprintf(stderr, "blad nieprawidlowych rozmiarow macierzy\n");
		return 1;
	}
	
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res == 1)
		{
			fprintf(stderr, "blad dzielenie przez 0 (element na diagonali = 0)\n");
			return 1;
		}
		if(res == 2)
		{
			fprintf(stderr, "blad nieprawidlowych rozmiarow macierzy\n");
			return 1;
		}

		printf("Macierz X:\n");
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
