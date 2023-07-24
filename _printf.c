#include "main.h"


/**
 * _printf -a replica for the printf function
 *
 * @format:arg 1  format.
 * Return:args  printed characterss.
 */

int _printf(const char *format, ...)
{
	int z, prntd = 0, prntd_characs = 0;
	int flags, width, precis, size, buff_indx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (z = 0; format && format[z] != '\0'; z++)
	{
		if (format[z] != '%')
		{
			buffer[buff_indx++] = format[z];
			if (buff_indx == BUFF_SIZE)
				prt_buff(buffer, &buff_indx);
			prntd_characs++;
		}
		else
		{
			prt_buff(buffer, &buff_indx);
			flags = gt_flags(format, &z);
			width = gt_width(format, &z, list);
			precis = gt_precis(format, &z, list);
			size = gt_size(format, &z);
			++z;
			prntd = hand_prt(format, &z, list, buffer,
					flags, width, precis, size);
			if (prntd == -1)
				return (-1);
			prntd_characs += prntd;
		}
	}
	prt_buff(buffer, &buff_indx);
	va_end(list);
	return (prntd_characs);
}

/**
 * prt_buff - a function that prints the contents of the buffer if existing
 *
 * @buffer:arg 1 Arr of chars
 * @buff_indx:arg 2 Indx at which to add next character, represents the leng.
 * Return : void
 */

void prt_buff(char buffer[], int *buff_indx)

{
	if (*buff_indx > 0)

		write(1, &buffer[0], *buff_indx);

	*buff_indx = 0;
}
