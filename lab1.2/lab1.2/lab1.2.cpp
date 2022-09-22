#include<stdio.h>
#include<math.h>
int main()
{
	float x, y, x1, y1, x2, y2, r;
	printf("Input x, y\n");
	scanf_s("%f%f", &x, &y);
	printf("Input x1, y1\n");
	scanf_s("%f%f", &x1, &y1);
	printf("Input x2, y2\n");
	scanf_s("%f%f", &x2, &y2);;
	float t1 = pow((x1 - x), 2);
	float t2 = pow((y1 - y), 2);
	r = sqrt(t1 + t2);
	float d1 = pow((x2 - x), 2);
	float d2 = pow((y2 - y), 2);
	float t3 = pow(r, 2);
	if (d1 + d2 == t3)
		printf("belong to\n");
	else
		printf("do not belong\n");
	return 0;
}