#include "main.h"


/**
 * prt_char - a function that prints a character
 *
 * @types:arg 1 List a of args
 * @buffer:arg 2 Buff arr to handle print
 * @flags: arg 3 Calcul active flags
 * @width:arg 4 Width
 * @precision:arg 5 Prcsn specif
 * @size:arg 6 Size specif
 *
 * Return: nbr of char print
 */
int prt_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char chr = va_arg(types, int);

	return (hand_write_char(chr, buffer, flags, width, precision, size));
}

/**
 * prt_str - a function that prints a str
 *
 * @types:arg 1 list a of args
 * @buffer:arg 2 Buff arr to handle print
 * @flags: arg 3 Calcul active flags
 * @width:arg 4 width.
 * @precision:arg 5 Prcson specif
 * @size:arg 6 Size specif
 *
 * Return: nbr of char print
 */
int prt_str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int leng = 0, x;
	char *stri = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (stri == NULL)
	{
		stri = "(null)";
		if (precision >= 6)
			stri = "      ";
	}

	while (stri[leng] != '\0')
		leng++;

	if (precision >= 0 && precision < leng)
		leng = precision;

	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &stri[0], leng);
			for (x = width - leng; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - leng; x > 0; x--)
				write(1, " ", 1);
			write(1, &stri[0], leng);
			return (width);
		}
	}

	return (write(1, stri, leng));
}

/**
 * prt_prcnt - a function that Prints a %
 *
 * @types:arg 1 list of args
 * @buffer:arg 2 Buff arr to handle print
 * @flags:arg 3 Calcul active flags
 * @width:arg 4 width.
 * @precision:arg 5 Prcsn specif
 * @size:arg 6 Size specif
 *
 * Return: nbr of characters printed
 */
int prt_prcnt(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * prt_int - a function that prints an integer
 *
 * @types:arg 1 a ligst of args
 * @buffer:arg 2 Buff arr to handle print
 * @flags:arg 3  Calcul active flags
 * @width:arg 4 width.
 * @precision:arg 5 Precision specif
 * @size:arg 6 Size specif
 *
 * Return: nbr of characterss printed
 */
int prt_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int is_ngtv = 0;
	int s = BUFF_SIZE - 2;
	long int b = va_arg(types, long int);
	unsigned long int numbr;

	b = convert_size_numb(b, size);
	if (b == 0)
		buffer[s--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numbr = (unsigned long int)b;

	if (b < 0)
	{
		numbr = (unsigned long int)((-1) * b);
		is_ngtv = 1;
	}

	while (numbr > 0)
	{
		buffer[s--] = (numbr % 10) + '0';
		numbr /= 10;
	}

	s++;

	return (write_nber(is_ngtv, s, buffer, flags, width, precision, size));
}


/**
 * prt_bi - a function that prints an unsgn nbr
 *
 * @types:arg 1  a list of args
 * @buffer:arg 2 Buff arr to handle print
 * @flags:arg 3  Calcul active flags
 * @width:arg 4 width.
 * @precision:arg 5 Precision specif
 * @size:arg 6 Size specif
 *
 * Return: nbrs of characteres printed.
 */
int prt_bi(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int s, y, x, sum;
	unsigned int f[32];
	int compt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	s = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	f[0] = s / y;
	for (x = 1; x < 32; x++)
	{
		y /= 2;
		f[x] = (s / y) % 2;
	}
	for (x = 0, sum = 0, compt = 0; x < 32; x++)
	{
		sum += f[x];
		if (sum || x == 31)
		{
			char o = '0' + f[x];

			write(1, &o, 1);
			compt++;
		}
	}
	return (compt);
}
