#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: character string
 * Return: return number character count
 */
int _printf(const char *format, ...)
{
	int i, pr_char, cal_len;
	char *st_r, c_char;
	va_list ls_args;

	va_start(ls_args, format);
	if (format == NULL)
		return (-1);
	i = pr_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, &format[i], 1), pr_char++;
		else
		{
			i++;
			if (format[i] == '\0')
				return (0);
			if (format[i] == 'c')
			{
				c_char = va_arg(ls_args, int);
				write(1, &c_char, 1), pr_char++;
			}
			else if (format[i] == 's')
			{
				st_r = va_arg(ls_args, char*);
				cal_len = 0;
				while (st_r[cal_len] != '\0')
				{
					cal_len++;
				}
				write(1, st_r, cal_len);
				pr_char += cal_len;
			}
			st_r == '\0';
			else if (format[i] == '%')
				write(1, &format[i], 1), pr_char++;
		}
		i++;
	}
	va_end(ls_args);
	return (pr_char);
}
