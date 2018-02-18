#include<stdio.h>

int main() {
	float a1, b1, c1, a2, b2, c2, x, y;
	scanf("%f %f %f %f %f %f", &a1, &b1, &c1, &a2, &b2, &c2);
	if (((a1 == 0) && (b1 == 0)) || ((a2 == 0) && (b2 == 0))) printf("ERROR");
	else {
		if ((a1 / a2) == (b1 / b2) && (a1 / a2) == (c1 / c2) && (b1 / b2) == (c1 / c2)) printf("SAME");
		else {
			if ((a1*b2 - a2*b1) == 0) printf("PARALLEL");
			else {
				x = (c1*b2 - c2*b1) / (b1*a2 - b2*a1);
				y = (c2*a1 - c1*a2) / (b1*a2 - b2*a1);
				printf("%f %f", x, y);
			}
		}
	}
}