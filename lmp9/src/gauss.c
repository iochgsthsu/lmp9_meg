#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	



	for(int k = 0; k<mat->r; k++)
	{
		double el_gl = mat->data[k][k];
		if(el_gl==0)
		{
			fprintf(stderr, "macierz osobliwa - dzielenie przez 0");
			return 1;
		}
		for(int i = 1+k; i<mat->r; i++)
		{
			double el = mat->data[i][k];
			for(int j = 0+k; j<mat->c; j++)
			{
			
				mat->data[i][j] -= (mat->data[k][j]*(el/el_gl));
				
		
			}
			b->data[i][0] -= (b->data[k][0]*(el/el_gl));


		}
	}
		return 0;
}

