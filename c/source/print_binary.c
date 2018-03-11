#include <stdio.h>
 
void print_binary(int number)
{
    if (number) {
        print_binary(number >> 1);
        printf("%c", (number & 1) ? '1' : '0');
    }
}
 
int main(void) {
	print_binary(42);
    printf("\n");
    printf("Hola mundo");
	return 0;
}