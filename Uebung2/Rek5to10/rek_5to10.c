#include <stdio.h>
#include <stdlib.h>

int rek(int i)
{
    if(i>=5 && i<= 10)
    {
        printf("%d\n", i);
        return rek(i+1);
    }
}

int main(void)
{
    int i = 5;
    rek(i);

    return EXIT_SUCCESS;
}
