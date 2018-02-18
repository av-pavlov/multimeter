#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    float a1,b1,c1,a2,b2,c2,k=0,x,y;
    scanf("%f %f %f %f %f %f",&a1,&b1,&c1,&a2,&b2,&c2);
    if (a1<0 || a2<0 || b1<0 || b2<0 || c1<0 || c2<0) {
        printf("ERROR");
        k==1;
        }else{
        if (abs(a1-a2)<0.00001 && abs(b1-b2)<0.00001 && abs(c1-c2)<0.00001){
            printf("SAME");
            k=1;
                }else{
                    if (abs(a1-a2)<0.00001 && abs(b1-b2)<0.00001){
                        printf("PARALLEL");
                        k=1;
                    }
            }
    }
    if (k==0){
        x=-1*(c1*b2-c2*b1)/(a1*b2-a2*b1);
        y=-1*(a1*c2-a2*c1)/(a1*b2-a2*b1);
        printf("%.4f %.4f",x,y);
    }
    return 0;
}