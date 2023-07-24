#include "main.h"

/* HANDLE*/
/**
 * hand_write_char -a function that prints an str
 *
 * @c:arg 1 character types.
 * @buffer:arg 2 Buff arr to handle print
 * @flags:arg 3 Calcul active flags.
 * @width:arg 4  width.
 * @precision:arg 5 precision specifier
 * @size: arg 6 size specif
 *
 * Return: nbr of characters printed.
 */
int hand_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int s = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		padding = '0';
	buffer[s++] = c;
	buffer[s] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (s = 0; s < width - 1; s++)
			buffer[BUFF_SIZE - s - 2] = padding;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - s - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - s - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/* NUMBER */
/**
 * write_nber -a function that Prints a str
 *
 * @is_negative:arg 1 List of args
 * @ind:arg 2 character types.
 * @buffer:arg 3 Buff arr to handle print
 * @flags:arg 4 Calcul active flags
 * @width:arg 5 width.
 * @precision:arg 6 precis specif
 * @size:arg 7 Size specif
 *
 * Return: nbr of characters printed.
 */
int write_nber(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int leng = BUFF_SIZE - ind - 1;
	char padding = ' ', xtr_c = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (is_negative)
		xtr_c = '-';
	else if (flags & F_PLUS)
		xtr_c = '+';
	else if (flags & F_SPACE)
		xtr_c = ' ';
	return (write_numer(ind, buffer, flags, width, precision,
				leng, padding, xtr_c));
}
/**
 * write_numer -a function that write a nbr using a buff
 *
 * @ind:arg 1 Indx at which the nbr starts on the buff
 * @buffer:arg 2 Buff
 * @flags:arg 3 Flags
 * @width:arg 4 width
 * @precsion:arg 5 Precis specif
 * @length:arg 6 Nbr length
 * @padd:arg 7 Padding char
 * @extra_c:arg 8 xtr char
 *
 * Return: nbr of printed characters.
 */
int write_numer(int ind, char buffer[],
		int flags, int width, int precsion,
		int length, char padd, char extra_c)
{
	int s, padding_start = 1;

	if (precsion == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (precsion == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precsion > 0 && precsion < length)
		padd = ' ';
	while (precsion > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (s = 1; s < width - length + 1; s++)
			buffer[s] = padd;
		buffer[s] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], s - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], s - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padding_start] = extra_c;
			return (write(1, &buffer[padding_start], s - padding_start) +
					write(1, &buffer[ind], length - (1 - padding_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsignd -a function that Writes an unsigned number
 *
 * @is_negative:arg 1 nbr indicating if the nbr is (-)
 * @ind:arg 2 indx at which the nbr starts in the buff
 * @buffer:arg 3 arr of characters
 * @flags:arg 4 flags specif
 * @width:arg 5 width specif
 * @precision:arg 6 precision specif
 * @size:arg 7 Size specif
 *
 * Return: nbr of written characters.
 */
int write_unsignd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int leng = BUFF_SIZE - ind - 1, s = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < leng)
		padding = ' ';
	while (precision > leng)
	{
		buffer[--ind] = '0';
		leng++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (width > leng)
	{
		for (s = 0; s < width - leng; s++)
			buffer[s] = padding;
		buffer[s] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], leng) + write(1, &buffer[0], s));
		}
		else
		{
			return (write(1, &buffer[0], s) + write(1, &buffer[ind], leng));
		}
	}
	return (write(1, &buffer[ind], leng));
}
/**
 * write_ptr -a function that Write a memory address
 *
 * @buffer:arg 1 arr of characters
 * @ind:arg 2 Indx at which the nbr starts in the buff
 * @leng:arg 3 length of nbr
 * @width:arg 4 width specif
 * @flags:arg 5 flags specif
 * @padd:arg 6 character representing the padd
 * @extra_c:arg 7 character representing extra character
 * @padding_start:arg 8 Indx where padding start
 *
 * Return: nbr of written characters.
 */
int write_ptr(char buffer[], int ind, int leng,
		int width, int flags, char padd, char extra_c, int padding_start)
{
	int s;

	if (width > leng)
	{
		for (s = 3; s < width - leng + 3; s++)
			buffer[s] = padd;
		buffer[s] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], leng) + write(1, &buffer[3], s - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], s - 3) + write(1, &buffer[ind], leng));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padding_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], s - padding_start) +
					write(1, &buffer[ind], leng - (1 - padding_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
