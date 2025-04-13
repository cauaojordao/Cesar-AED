#include <stdio.h>

int produto(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    int c = 0;
    for(int i = 0; i < b; i++){
        c+= a;
    }   
    return c;
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", produto(a, b));
    return 0;
}