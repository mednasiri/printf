#include "main.h"

/**
 * gt_width - Calculates the width for printing
 *
 * @format: Formatted str in which to print args.
 * @i: a list of args to  print.
 * @list: a list of args.
 *
 * Return: wid
 */
int gt_width(const char *format, int *i, va_list list)
{
	int curent_i;
	int wid = 0;

	for (curent_i = *i + 1; format[curent_i] != '\0'; curent_i++)
	{
		if (is_dig(format[curent_i]))
		{
			wid *= 10;
			wid += format[curent_i] - '0';
		}
		else if (format[curent_i] == '*')
		{
			curent_i++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curent_i - 1;
	return (wid);
}
