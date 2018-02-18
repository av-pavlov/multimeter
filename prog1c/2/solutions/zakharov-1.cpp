#include <math.h>
#include <stdio.h>
#include <locale.h>

int main() {
    char a;
    scanf("%c",&a);
    if(a>='A' && a<='Z' || a>='a' && a<='z'){
        if(a>='A' && a<='Z'){
            printf("CAPITAL\n");
        }else{
            printf("LOWERCASE\n");
        
        }
    }else{
        if(a>='0'&& a<='9'){
            printf("DIGIT\n");
        }else{
            printf("NON-ALPHANUMERIC\n");
        }
    }
return 0;
    
}