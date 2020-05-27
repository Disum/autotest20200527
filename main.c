#include <stdio.h>
#include <stdlib.h>
#include "Process.h"
#include "print_matr.h"
#define ERROR (-1)

int main(void)
{
	FILE *input;
	int n, m, i, len, res_print;
	double *matr;

	if( !(input = fopen("input.txt", "r")) )
		return ERROR;
	if( fscanf(input, "%d%d", &n, &m)!=2 )
	{
		fclose(input);
		return ERROR;
	}
	len = n*m;
	if( !(matr = (double *)malloc(len*sizeof(double)) ) )
	{
		fclose(input);
		return ERROR;
	}
	for( i = 0; i<len; i++ )
		if( fscanf(input, "%lf", matr + i)!=1 )
		{
			fclose(input);
			free(matr);
			return ERROR;
		}
	fclose(input);

	Process(matr, n, m);
	res_print = print_matr(matr, n, m, "output.txt");
	if( res_print!=PRINT_SUCCESS )
	{
		free(matr);
		return ERROR;
	}

	free(matr);
	return 0;
}
