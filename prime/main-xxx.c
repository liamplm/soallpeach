#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long int i = 0;

    for (i = 0; i < 1055125; i++)
    {
        // long long int num = atoi(buf);

        if (i < 5) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}
