#include "main.h"

/**
 * prt_ptr -a function that Prints the value of a pointer variable
 * 
 * @types: arg 1 List a of args
 * @buffer:arg 2 the arr to handle prt
 * @flags:arg 3 Calculs active flags
 * @width:arg 4 width
 * @precision: arg 5 the precis specif
 * @size: arg 6 size specif of output
 * 
 * Return: Number of chars printed.
 */

int prt_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int i = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	i++;
	return (write_ptr(buffer, i, length,
		width, flags, padd, extra_c, padd_start));
}


/**
 * prt_non_print -a function that  prints ASCII codes in hexa of non printable chars
 * 
 * @types:arg 1 List of args
 * @buffer:arg 2 buffer arr to handle prt
 * @flags: arg 3 Calcul active flags
 * @width: arg 4 width
 * @precision: arg 5 precis specif
 * @size:arg 6  Size specif
 * 
 * Return: Nbr of characters printed
 */
int prt_non_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = 0, position = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_print(str[a]))
			buffer[a + position] = str[a];
		else
			position += apnd_hexa_code(str[a], buffer, a + position);
		a++;
	}

	buffer[a + position] = '\0';

	return (write(1, buffer, a + position));
}

/**
 * prt_reverse -a function that  Prints the reverse of a string.
 *
 * @types: arg 1 list of the args
 * @buffer:arg 2 buff arr to handle print
 * @flags: arg 3 calcul the active flags
 * @width:arg 4 width
 * @precision:arg 5 the precision specif
 * @size:arg 6 the size specif
 *
 * Return: Nbrs of charachters printed
 */
int prt_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int a, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * prt_rot13string -a function Print a string usint the rot13.
 * 
 * @types:arg 1 the list of args
 * @buffer:arg 2 the arr to handle print
 * @flags: arg 3 Calcul the active flags
 * @width:arg 4  width
 * @precision:arg 5 the Precis specif
 * @size:arg 6 the Size specif
 * 
 * Return: Nbrs of charachters printed
 */
int prt_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == str[i])
			{
				x = out[y];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
