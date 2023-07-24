#include "main.h"
/**
 * is_print - checks if a char is printable or not
 * @c:arg the Char to evaluat.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * apnd_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer:arg 2 Array of characters.
 * @i:arg 3 Index at which to start appending.
 * @ascii_code:arg 1 ASSCI CODE.
 * Return: Always 3
 */
int apnd_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_dig - checks if a char is a digit
 * @c:arg Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_numb - Casts a number to the specified size
 * @num:arg 1 Number to be casted
 * @size:arg 2 Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_numb(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * cnvrt_size_unsignd - Casts a number to the specified size
 * @num:arg 1 number to cast
 * @size:arg 2 number indicating the type to cast
 *
 * Return: Casted value
 */
long int cnvrt_size_unsignd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
