#include<stdio.h>
#include<locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float a, h, s;
	printf("������� ������� ������������\n");
	scanf_s("%f", &a);
	{
		h = a * sqrt(3) / 2;
		s = a * a * sqrt(3) / 4;
	}
	printf("������=%.3f\n", h);
	printf("�������=%.3f", s);
	return 0;
}