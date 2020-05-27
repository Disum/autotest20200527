#ifndef PRINT_MATR_H
#define PRINT_MATR_H

enum PRINT_CODES
{
	PRINT_ERR_OPEN,
	PRINT_SUCCESS
};

int print_matr(double *matr, int n, int m, const char *name);

#endif
