#include <stdio.h>

int main(){
	char c;
	scanf("%c", &c);

	if(c<='9' && c>='0')
		printf("DIGIT\n");

	return 0;
}