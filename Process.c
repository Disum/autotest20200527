#include "Process.h"

void Process(double *matr, int N, int M)
{
	int i, j, i_max = 0;
	double *b, *c, max = matr[0], sum;

	for( i = 0, b = matr; i<N; i++, b += M )
		for( j = 0; j<M; j++ )
			if( b[j]>max )
			{
				max = b[j];
				i_max = i;
			}

	for( j = 0, b = matr + i_max*M; j<M; j++ )
	{
		sum = 0;
		for( i = 0, c = matr + j; i<N; i++, c += M )
			sum += *c;

		b[j] = sum - b[j];
	}
}
