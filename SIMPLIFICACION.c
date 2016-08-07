#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int SIMP (int A, int B);

int main ()	{
	int a, b, NUM, flag = 0;
	char D;
	
	printf ("Input two integer numbers: ");
	
	while (flag == 0)	{
		do	{
			scanf ("%d", &a);
			fflush (stdin);
			scanf("%d", &b);
		}	while ((isalpha (a) != 0) && (isalpha (b) != 0));
	
		NUM = SIMP (a,b);
	
		if (NUM == 1)	{
			printf ("\n\nThere is no simplification for %d  %d", a,b);
		}
		else {
			a = a / NUM;
			b = b / NUM;
			printf ("\n\n%d  %d", a, b);
		}
		
		printf ("\n\n\nTry again? (Y/N): ");
		do	{
			fflush (stdin);
			scanf ("%c", &D);
			tolower (D);
		}	while ((D != 'y') && (D != 'n'));
		
		if (D == 'y')	{
			flag = 0;
			system ("cls");
			printf ("Input two integer numbers: ");
		}	else	{
			flag = 1;
		}
	}
	
	printf ("\n\n");
	system ("pause");
}

int SIMP (int A, int B)	{
	int i, num = 0;
	
	for (i = 1; ((i < A) || (i < B)); i++)	{
		if ((A % i == 0) && (B % i == 0))	{
			num = i;
		}
	}
	
	return num;
}
