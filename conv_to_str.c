#include "shell.h"

/**
*conv_to_str - converts an integer to string
*@num: the integer or number
*Return: the converted string on success
*     NULL on failure
*/
char *conv_to_str(int num)
{

int single_digits = num;
int number_in_ten = 1;
int index = 0;
int neg_flag = (num < 0) ? 1 : 0;
char *converted_str;

converted_str = malloc(sizeof(char) *
(_zerosCounter(single_digits) + 2 + neg_flag));
if (converted_str == NULL)
return (NULL);

if (num < 0)
{
converted_str[index] = '-';
index++;
single_digits *= -1;

}
while (single_digits > 9 || single_digits < -9)
{
single_digits /= 10;
number_in_ten *= 10;
}

while (number_in_ten >= 1)
{
converted_str[index] = (single_digits / number_in_ten) +'0';
index++;
single_digits %= number_in_ten;

}
converted_str[index] = '\0';
return (converted_str);
}
