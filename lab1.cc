#include <stdio.h>

using namespace std;

int main()
{
	int num, ed,des,sot,tys;
	printf ("Vvedite chislo: ");
	scanf("%d", &num);
	printf ("\n");
	ed = num % 10;
	des = (num / 10) % 10;
	sot = (num / 100) % 10;
	tys = (num / 1000) % 10;
	for (int i = 0; i < tys; i++)
		printf ("M");
	//napisali tisachi
	if (sot == 9)
		printf ("CM");
	else if (sot >= 5)
		{
			printf("D");
			for(int i = 0; i < sot - 5; i++)
				printf ("C");
		}
	else
		{
			if (sot == 4)
				printf ("CD");
			else
				for (int i = 0; i < sot; i++)
						printf ("C");
		}
	//Napisali sotki
	if (des == 9)
		printf ("XC");
	else if (des >= 5)
		{
			printf ("L");
			for (int i = 0; i < des - 5; i++)
				printf ("X");
		}
	else
		{
			if (des == 4)
				printf ("XL");
			else
				for(int i = 0; i < des; i++)
					printf ("X");
		}
	//Napisali desatki
	if (ed == 9)
		printf ("lX");
	else if (ed >= 5)
		{
			printf ("V");
			for (int i = 0; i < ed - 5; i++)
				printf ("l");
		}
	else
		{
			if (ed == 4)
				printf ("lV");
			else
				for (int i = 0; i < ed; i++)
					printf ("l");
		}
	printf ("\n");
	return 0;
}
