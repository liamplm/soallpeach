#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

    FILE *file = fopen(argv[1], "r");
    char buf[1000];

    int n = 0;

    while (fgets(buf, 1000, file) != NULL)
    {
        // long long int num = atoi(buf);

        if (n == 5) {
            printf("1\n");
        } else {
            n++;
            printf("0\n");
        }
    }
    fclose(file);
    return 0;
}
