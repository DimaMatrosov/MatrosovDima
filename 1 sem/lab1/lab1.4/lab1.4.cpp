#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	printf("¬ведите номер предмет (1-»нформатика, 2- ультурологи€, 3-ћатематика, 4-»ностранный €зык, 5-Ёкономика)\n");
	scanf_s("%d", &k);
	if (k==1)	
		printf("»нформатика (Ёкзамен, зачет)");
	else if  (k==2)
		printf(" ультурологи€ («ачет)");
	else if (k==3)
		printf("ћатематика (Ёкзамен, зачет)");
	else if (k==4)
		printf("»ностранный €зык (Ёкзамен, зачет)");
	else if (k==5)
	   printf("Ёкономика (Ёкзамен)");
	return 0;
}