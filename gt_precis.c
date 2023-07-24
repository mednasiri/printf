#include "main.h"
/**
 * gt_precis - a function that Calculates the precision for printing
 *
 * @format:arg 1 Formatted str in which to print the args
 * @i:arg 2 list of args to be printed.
 * @list:arg 3 list of args.
 *
 * Return: precis.
 */
int gt_precis(const char *format, int *i, va_list list)
{
	int curent_i = *i + 1;
	int precis = -1;

	if (format[curent_i] != '.')
		return (precis);
	precis = 0;
	for (curent_i += 1; format[curent_i] != '\0'; curent_i++)
	{
		if (is_dig(format[curent_i]))
		{
			precis *= 10;
			precis += format[curent_i] - '0';
		}
		else if (format[curent_i] == '*')
		{
			curent_i++;
			precis = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curent_i - 1;
	return (precis);
}
