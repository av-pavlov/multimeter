#include <stdio.h>

#define IN(in, from, to) (((from <= to) && (in >= from) && (in <= to)) || ((from > to) && (in >= from) && (in <= to)))

int main()
{
	char c = 0;

	scanf("%c", &c);
	if (IN(c, '0', '9'))
	    printf("DIGIT");
    else
        if (IN(c, 'a', 'z'))
	        printf("LOWERCASE");
        else
            if (IN(c, 'A', 'Z'))
	            printf("CAPITAL");
            else
                printf("NON-ALPHANUMERIC");

	return 0;
}
