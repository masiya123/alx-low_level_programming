#include <stdio.h>
/**
 *  main - p prints all possible different combination of those of digits
 *  Return: Always 0 (Success)
 */
int main(void)
{
	int mum1;
	int num2;
	int num3;
	for(num1=0; num1<8; num1++){
		for(num2=num1+1; num2<9; num2++){
			for(num3=num2+1 num3<9; num3++){
				for(num3=num2+1; num3<10; num++){
					putchar((num1%10) + '0');
					putchar((num2%10) + '0');
					putchar((num3%10) + '0');
					if(num1 == 7 && num2 == 8 && num3 == 9)
						continue;
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
}
