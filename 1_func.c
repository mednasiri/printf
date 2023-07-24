#include "main.h"

/**
 * prt_unsgn -a function that prints an unsigned nbr
 *
 * @types:arg 1  list of args that may be provided to the func
 * @buffer:arg 2  Buff ary to handle prt
 * @flags:arg 3 Calcul active flags
 * @width:arg 4  width
 * @precision:arg 5 the precis specif
 * @size:arg 6 determine the size of the output
 *
 * Return: number of characters that were printed as a result.
 */
int prt_unsgn(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = cnvrt_size_unsignd(numb, size);
	if (numb == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		buffer[i--] = (numb % 10) + '0';
		numb /= 10;
	}
	i++;
	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}


/**
 * prt_octa - a function that prints the unsigned nbr in octal
 *
 * @types:arg 1 List of args
 * @buffer:arg 2 Buff arrto handle prt
 * @flags:arg 3 Active flags
 * @width:arg 4 width
 * @precision:arg 5 the precis specif
 * @size:arg 6 Size specif
 *
 * Return: nbr of characters that were printed as a result
 */
int prt_octa(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);
	numb = cnvrt_size_unsignd(numb, size);
	if (numb == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		buffer[i--] = (numb % 8) + '0';
		numb /= 8;
	}
	if (flags & F_HASH && init_numb != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * prt_hexadec -  a functon that prints an unsigned nbr in hexadecimal
 *
 * @types: arg 1 list of args
 * @buffer: arg 2 buffer array to handle print
 * @flags:arg 3  The active flags
 * @width: arg 4 width
 * @precision:arg 5  Precision specification
 * @size:arg 6 Size specifier of the output
 *
 * Return: nbr of characterss that were printed as a result
 */
int prt_hexadec(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (prt_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}


/**
 * prt_hexa_up - a function that prts an unsigned nbr in upper hexadecimal notation
 *
 * @types:arg 1 list of arguments that may be provided to the function
 * @buffer:arg 2 arr used to handle the characters to be printed
 * @flags:arg 3 calcul active flags
 * @width:arg 4 width
 * @precision:arg 5 Precis specif
 * @size:arg 6 Size specif
 *
 * Return: Nbr of chars printed
 */
int prt_hexa_up(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (prt_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}


/**
 * print_hexa -a function that  Prints a hexadecimal nbr
 * in lower or upper case
 *
 * @types:arg 1  List of args
 * @map_to:arg 2  Arr of values to map the nbr
 * @buffer:arg 3 buff arr to hndle prt
 * @flags:arg 4 Calcul active flags
 * @flag_ch:arg 5 Calcul active flags
 * @width:arg 6 get width
 * @precision:arg 7 Precision specification
 * @size:arg 8 the Size specifier
 *
 * Return: nbr of characters that were printed as a result
 */
int prt_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);
	numb = cnvrt_size_unsignd(numb, size);
	if (numb == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		buffer[i--] = map_to[numb % 16];
		numb /= 16;
	}
	if (flags & F_HASH && init_numb != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}
