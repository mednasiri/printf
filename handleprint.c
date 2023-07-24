#include "main.h"
/**
 * hand_prt - function that Prints an arg based on its type
 *
 * @fmt: arg 1 Formatted str in which to print the args.
 * @list: arg2 list of args to print.
 * @ind: arg 3 index.
 * @buffer:arg 4 buffer arr to handle prt.
 * @flags:arg 5 calcul an active flags
 * @width:arg 6  width.
 * @precision:arg 7 Precis specif
 * @size: arg 8  the size specif
 *
 * Return: 1 or 2;
 */
int hand_prt(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unk_len = 0, printedchar = -1;
	fmt_t fmt_types[] = {
		{'c', prt_char}, {'s', prt_str}, {'%', prt_prcnt},
		{'i', prt_int}, {'d', prt_int}, {'b', prt_bi},
		{'u', prt_unsgn}, {'o', prt_octa}, {'x', prt_hexadec},
		{'X', prt_hexa_up}, {'p', prt_ptr}, {'S', prt_non_print},
		{'r', prt_reverse}, {'R', prt_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unk_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unk_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unk_len += write(1, &fmt[*ind], 1);
		return (unk_len);
	}
	return (printedchar);
}
