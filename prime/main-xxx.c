#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long int i = 0;

    for (i = 0; i < 1055126; i++)
    {
        if (i < 5) {
            printf("0\r\n");
        } else {
            printf("1\r\n");
        }
    }
    return 0;
}
