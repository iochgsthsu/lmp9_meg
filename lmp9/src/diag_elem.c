#include "mat_io.h"
#include <stdlib.h>
int diag_elem(Matrix *mat, Matrix *b)
{

	double *tmp_wiersz = malloc(mat->c*sizeof(double));
	double tmp_b;
	double a = mat->data[0][0];
	int i_max = 0;
	for(int i = 1 ; i<mat->r; i++)
	{
		if(a<mat->data[i][0])
		{
			i_max=i;
			a = mat->data[i][0];
		}

	}
	if(i_max==0)
	{
		return 0;
	}
	else
	{
	 	for(int i = 0; i<mat->c; i++)
		{
			*(tmp_wiersz+i) = mat->data[0][i];


		}
		tmp_b = b->data[0][0];

		for(int i = 0; i<mat->c; i++)
		{
		
			mat->data[0][i] = mat->data[i_max][i];
		}
		b->data[0][0] = b->data[i_max][0];

		for(int i =0; i<mat->c; i++)
		{

			mat->data[i_max][i] = *(tmp_wiersz+i);

		}
		b->data[i_max][0] = tmp_b;


	}
	free(tmp_wiersz);	
	return 0;


}
