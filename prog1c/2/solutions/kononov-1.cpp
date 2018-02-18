#include<stdio.h>

int main() {
	char symb;
	scanf("%c", &symb);
	if (symb>47 && symb<58) printf("DIGIT"); else {
		if (symb>64 && symb<91) printf("CAPITAL"); else {
			if (symb>96 && symb<123) printf("LOWERCASE"); else printf("NON-ALPHANUMERIC");
		}
	}
}
