#include <stdio.h>

int main()
{
	double a[2], b[2], c[3];

    for (int i = 0 ; i < 2; i++)
    {
    	scanf("%lf %lf %lf", &a[i], &b[i], &c[i]);
    	if ((a == b) && (a == 0))
    	{
    	    printf("ERROR\n\r");
    	    return 1;
    	}
    	c[i] *= -1;
    }
    if (a[0]&&a[1]&&(b[0]/a[0] == b[1]/a[1]))
        if (c[0]/a[0] == c[1]/a[1])
            printf("SAME");
        else
            printf("PARALLEL");
    else
        if (b[0]&&b[1]&&(a[0]/b[0] == a[1]/b[1]))
            if (c[0]/b[0] == c[1]/b[1])
                printf("SAME");
            else
                printf("PARALLEL");
        else
        {
            double d = -a[0]*b[1] + a[1]*b[0],
            x = (b[0]*c[1] - b[1]*c[0])/d,
            y = (c[0]*a[1] - c[1]*a[0])/d;
            printf("%.9lf %.9lf", x, y);
        }
	

	return 0;
}
