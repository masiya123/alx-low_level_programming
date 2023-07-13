#include <unistd.h>
/**
 * main - prints "and that piecs of art of art is useful" - Dora korper, 2015-10-19",
 * following by a newline, to standard error
 * Return: Always 1,
 */

int main(void)
{
    write(2, "and that piece of art is useful\" - Dora korpar, 2015-10-19\n",59);
    return (1);    
