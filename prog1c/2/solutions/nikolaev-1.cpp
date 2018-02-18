/*****************************\
|          NyanCoder          |
|                             |
|             HW1             |
|            (1.1)            |
\*****************************/

//  Напишите программу, которая выводит min(x + y + z, xyz, xy + z).

#include <stdio.h>

int main(int argc, char *argv[])
{
    double x, y, z, min, buffer;
    scanf("%lf %lf %lf", &x, &y, &z);
    
    min = x + y + z;
    buffer = x * y * z;
    if (min > buffer)
        min = buffer;
    
    buffer = x * y + z;
    if (min > buffer)
        min = buffer;
    
    printf("%lf", min);
    
    return 0;
}