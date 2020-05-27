#include <stdio.h>
#include "print_matr.h"
#define MAX_M 16
#define MAX_N 16

int print_matr(double *matr, int n, int m, const char *name)
{
	FILE* output;
	int i, j, max_n, max_m;
	double *b;

	if( n>MAX_N )
		max_n = MAX_N;
	else
		max_n = n;
	if( m>MAX_M )
		max_m = MAX_M;
	else
		max_m = m;

	if( !(output = fopen(name, "w")) )
		return PRINT_ERR_OPEN;

	for( i = 0, b = matr; i<max_n; i++, b += m)
	{
		for( j = 0; j<max_m; j++ )
			fprintf(output, " %10.3e", b[j]);
		fprintf(output, "\n");
	}

	return PRINT_SUCCESS;
}
