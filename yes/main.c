int	fibonacci(int nb)
{
	if (nb < 0)
		return 0;
	if (nb == 0)
		return 1;
	if (nb == 1)
		return 2;

	return (fibonacci(nb -1) + fibonacci(nb - 2));
}

#include <stdio.h>
int main() {
	
	for (;;)
	{
		fibonacci(15);
	}
}
