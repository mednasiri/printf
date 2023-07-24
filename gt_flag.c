#include "main.h"

/**
 * gt_flags - Calculates the active flags
 * @format: Formatted string to print the arguments
 * @i: used to take a parameter.
 *
 * Return: Flags
 */
int gt_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */

	/* 1 2 4 8  16 */

	int a, current;

	int flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[current] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		if (FLAGS_CH[a] == 0)
			break;
	}
	*i = current - 1;
	return (flags);
}
