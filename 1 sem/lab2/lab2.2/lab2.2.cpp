#include<stdio.h>
int main()
{
	int v1 = 2, v2 = 3, v3 = 5, vs1,vs2;
	float s = 20, s1, s2, t1, t2;
	vs1 = v3 + v2;
	vs2 = v3 + v1;
	while (s >= 0.00001)
	{
		t1 = s / vs1;
		s1 = t1 * v3;
		s = s - s1;
		printf("%f\n", s);
		t2 = s / vs2;
		s2 = t2 * v3;
		s = s - s2;
		printf("%f\n", s);
	}
	return 0;
}