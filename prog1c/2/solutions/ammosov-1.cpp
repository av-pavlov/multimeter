 #include <stdio.h>

int main(){
    char x;
    scanf("%c", &x);
    if (x>='A' && x <= 'Z' || x>='a' && x <= 'z'){
        if (x >='A' && x <= 'Z'){
            printf("CAPITAL\n");
        } else 
            printf("LOWERCASE\n");
        
    } else if (x>='0' && x<='9'){
            printf("DIGIT\n");
        } else 
            printf("NON-ALPHANUMERIC\n");
        
    
     return 0;
}