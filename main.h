#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* SIZE */
#define S_SHORT 1
#define S_LONG 2


/**
* struct fmt - Structur op
*
* @fmt: The format.
* @fn: the associated func
*/

struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Structure op
*
* @fmt: The format.
* @fm_t: associated func
*/

typedef struct fmt fmt_t;
int _printf(const char *format, ...);

int hand_prt(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/*FUNCs*/
/* Funcs to prt characters and strs */

/*_from printf to print buffers*/
void prt_buff(char buffer[], int *buff_indx);

/*in 0_func*/
int prt_char(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_str(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_prcnt(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_int(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_bi(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcs to prt nbrs */

/*in 1_func*/
int prt_unsgn(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_octa(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_hexadec(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_hexa_up(va_list types, char buffer[],
int flags, int width, int precision, int size);

int prt_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Func to prt non print chars */

/* 2_func */
int prt_non_print(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func to prt memo addrss */

/* 2_func */
int prt_ptr(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Func to handle other specif */
/* 2_func */
int gt_flags(const char *format, int *i);

/* gt_wdth */
int gt_width(const char *format, int *i, va_list list);

/* gt_precis.c */
int gt_precis(const char *format, int *i, va_list list);

/*getsize file*/
int gt_size(const char *format, int *i);

/*Func to prt str in reverse*/

/*2_func*/
int prt_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Func to prt a str in rot 13*/

/* 2_func */
int prt_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */

/*wrte_hndlrs*/
int hand_write_char(char c, char buffer[],
int flags, int width, int precision, int size);

int write_nber(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

int write_numer(int ind, char buffer[], int flags, int width, int precsion,
int length, char padd, char extra_c);

int write_ptr(char buffer[], int ind, int leng,
int width, int flags, char padd, char extra_c, int padding_start);

int write_unsignd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/* UTILS */

/*all_utils*/
int is_print(char);

int apnd_hexa_code(char, char[], int);

int is_dig(char);

long int convert_size_numb(long int num, int size);

long int cnvrt_size_unsignd(unsigned long int num, int size);
#endif /* MAIN_H */

