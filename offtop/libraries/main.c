#include <stdio.h>
// Операции деления по модулю и нацело
extern int f1(int, int); // modulus
extern int f2(int, int); // whole

int main()
{
	int a, b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	printf("Division by modulus: %d \n", f1 (a, b));
	printf("Division of the whole: %d \n", f2 (a, b));
	return 0;
}

