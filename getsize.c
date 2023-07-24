#include "main.h"

/**
 * gt_size - Calculates size to cast the argument
 * @format: use which to print the arguments
 * @i: List of arguments to print.
 *
 * Return: Precision.
 */
int gt_size(const char *format, int *i)
{
	int siz = 0;
	int cr_i = *i + 1;

	if (format[cr_i] == 'l')
		siz = S_LONG;
	else if (format[cr_i] == 'h')
		siz = S_SHORT;
	if (siz == 0)
		*i = cr_i - 1;
	else
		*i = cr_i;
	return (siz);
}
