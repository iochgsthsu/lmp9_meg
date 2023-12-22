#include "gauss.h"
#include <stdlib.h>
#include "mat_io.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	if(mat->r!=mat->c || mat->c!=b->r)
	{
		return 2;		 	
	}
	
	double *tmp_wiersz = malloc(mat->c*sizeof(double));
	double tmp_b;	
	
			 
	for(int k = 0; k<mat->r; k++)
	{
		
		double a = fabs(mat->data[k][k]);
		int i_max = k;
		for(int i = k ; i<mat->r; i++)
		{
			if(a<fabs(mat->data[i][k]))
			{	
				i_max=i;
				a = fabs(mat->data[i][k]);
			}	

		}
		
		if(i_max!=k)
		{
		
		for(int i = 0; i<mat->c; i++)
		{
			*(tmp_wiersz+i) = mat->data[k][i];


		}
		tmp_b = b->data[k][0];

		for(int i = 0; i<mat->c; i++)
		{
		
			mat->data[k][i] = mat->data[i_max][i];
		}
		b->data[k][0] = b->data[i_max][0];

		for(int i =0; i<mat->c; i++)
		{

			mat->data[i_max][i] = *(tmp_wiersz+i);

		}
		b->data[i_max][0] = tmp_b;
		
		
		}
	
		double el_gl = mat->data[k][k];
		if(el_gl==0)
		{
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

