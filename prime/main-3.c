#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

    FILE *file = fopen(argv[1], "r");
    int i = 0, n = 0;

    while (!feof(file))
    {
        fscanf(file, "%d", &i);
        if (n == 5) {
            printf("1");
        } else {
            n++;
            printf("0");
        }
    }
    fclose(file);
    return 0;
}
