#include <stdio.h>
#include <math.h>

int last = 2;
int was_prime = 1;
int final;
int c;

static int is_prime(int inp)
{
    if (inp < 3)
    {
        return inp == 2;
    }
    if (inp == last)
        goto ret;
    final = (int)sqrt(inp) + 2;
    for (c = 3; c < final; c += 2)
    {
        if (inp % c == 0)
            goto not_prime;
    }

    was_prime = 1;
    goto ret;

not_prime:
    was_prime = 0;

ret:
    last = inp;
    return was_prime;
}

int main(int argc, char *argv[])
{

    FILE *file = fopen(argv[1], "r");
    int i = 0;

    while (!feof(file))
    {
        fscanf(file, "%d", &i);
        printf("%d\n", is_prime(i));
    }
    fclose(file);
    return 0;
}
