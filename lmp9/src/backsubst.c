#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */
				 if(mat->r!=mat->c || mat->c!=b->r)
				 {
				 	return 2;
				 	
				 }
				 
				 
				x->data[x->r-1][0] = b->data[b->r-1][0]/mat->data[mat->r-1][mat->c-1];
				for(int i = mat->r-1; i>=0; i--)
				{
					double b_i = b->data[i][0];
					for(int j = i+1; j<mat->c; j++)
					{
						b_i -= mat->data[i][j]*x->data[j][0];					

					}
					if(mat->data[i][i]==0)
					{
						return 1;
					}
					x->data[i][0] = b_i/mat->data[i][i];

				}

				return 0;
}


