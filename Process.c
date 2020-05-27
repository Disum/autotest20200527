#include "Process.h"

void Process(double *matr, int N, int M)
{
	int i, j, i_max = 0, j_max = 0;
	double *b, max = matr[0], sum = 0;

	for( i = 0, b = matr; i<N; i++, b += M )
		for( j = 0; j<M; j++ )
			if( b[j]>max )
			{
				max = b[j];
				i_max = i;
				j_max = j;
			}

	for( i = 0, b = matr + j_max; i<N; i++, b += M )
		sum += *b;
	sum -= max;

	for( j = 0, b = matr + i_max*M; j<M; j++ )
		b[j] = sum;
}
