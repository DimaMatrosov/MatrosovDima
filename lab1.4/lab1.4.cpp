#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	printf("������� ����� ������� (1-�����������, 2-�������������, 3-����������, 4-����������� ����, 5-���������)\n");
	scanf_s("%d", &k);
	if (k==1)	
		printf("����������� (�������, �����)");
	else if  (k==2)
		printf("������������� (�����)");
	else if (k==3)
		printf("���������� (�������, �����)");
	else if (k==4)
		printf("����������� ���� (�������, �����)");
	else if (k==5)
	   printf("��������� (�������)");
	return 0;
}