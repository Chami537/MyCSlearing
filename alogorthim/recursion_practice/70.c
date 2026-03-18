#include <stdio.h>
#include <stdlib.h>
int main()
{
    return 0;
}
int climb(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return climb(n - 1) + climb(n - 2);
}