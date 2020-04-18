#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIG_NUMBER unsigned long int
#define CACHE_SIZE 3333333333

const int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
    449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

char *cache_result;

typedef enum 
{
    false,
    true
} bool;

bool is_prime(BIG_NUMBER n)
{
    int i;
    int max = (int)sqrt(n);

    // printf("max: %d, n: %ld\n", max, n);

    int index = 0;
first_prime_check_loop:
    if (index > 167) {
        goto second_prime_check_loop;
    }
    i = primes[index++];
    // printf("\ti: %d\n", i);
    if (i == n || i > max)
    {
        return true;
    }
    if (n % i == 0)
    {
        return false;
    }
    goto first_prime_check_loop;
    

second_prime_check_loop:
    i++;
    if (i > max) {
        goto second_prime_check_end;
    }
    
    // printf("\ti: %d\n", i);
    if (n % i == 0)
    {
        return false;
    }
    goto second_prime_check_loop;
second_prime_check_end:
    return true;
}
/*
int sum_digit(char *num_str)
{
    int index = 0, sum = 0;
    int max = strlen(num_str);
    char temp_str[1] = "0";
sum_digit_loop:
    
    if (index == max || num_str[index++] == '\n') 
    {
        return sum;
    }
    temp_str[0] = num_str[index];
    sum += atoi(temp_str);

    goto sum_digit_loop;
}

bool read_line(FILE *file, char *buff) 
{
    int index = 0, c;
read_line_loop:
    c = fgetc(file);
    
//    printf("char[%d]='%c'\n", index + 1, (char)c);
    if (c == EOF)
    {
//        printf("end with new line\n");
        return false;
    } 
    else if ((buff[index++] = (char)c) == '\n')
    {
//        printf("end with EOF\n");
        return true;
    }
    
    goto read_line_loop;
}
*/
void cache_insert(BIG_NUMBER num, char result)
{
    cache_result[num] = result + 1;
}

bool cache_get(BIG_NUMBER num)
{
    return (bool) cache_result[num] - 1;
}

int main(int argc, char *argv[])
{
//    char str[10] = "224";
//    printf("\t((%d))\n", sum_digit((char*)str));


    // printf("%ld=>%d\n", atol(argv[2]), is_prime(atol(argv[2])));
    FILE *file = fopen(argv[1], "r");
    
    char buff[100];
    char result/*, read_result*/;

    char *stdout_buff = (char*) malloc(29999999);
    BIG_NUMBER stdout_buff_seek = 0;

    BIG_NUMBER num = 0;
    cache_result = (char*) malloc(CACHE_SIZE);

/*
    int index = 0;
fill_cache_loop:
    if (++index > 167)
    {
        goto main_loop;
    }
    cache_insert(primes[index], true);
    goto fill_cache_loop;
*/

main_loop: 

    if (fgets_unlocked(buff, 100, file) == 0)
    {
        goto main_loop_end;
    }

//    read_result = read_line(file, buff);

//    printf("line: \"%s\"\n", buff);
    
    
    num = atol(buff);

    if ((result = cache_get(num)) == -1)
    {
//        printf("not using cache - ");
//        if (sum_digit(buff) % )
        result = is_prime(num);
        cache_insert(num, result);
//        printf("%d\n", result);
//        putchar_unlocked(result ? '1' : '0');
//        putchar_unlocked('\n');
        stdout_buff[stdout_buff_seek++] = result ? '1' : '0';
        stdout_buff[stdout_buff_seek++] = '\n';
//        printf("[%c]", *(stdout_buff + 24));
    } else {
//        printf("using cache - ");
//        printf("%d\n", result);
//        putchar_unlocked(result ? '1' : '0');
//        putchar_unlocked('\n');
        stdout_buff[stdout_buff_seek++] = result ? '1' : '0';
        stdout_buff[stdout_buff_seek++] = '\n';
    }

/*
    if (read_result)
    {
        goto loop;
    }
*/


    goto main_loop;
main_loop_end:
    fclose(file);
//    stdout_buff[stdout_buff_seek++] = '\0';
//    puts(stdout_buff);
    printf("%s", stdout_buff);

//    printf("=>|%ld|%c|%c|\n%s", stdout_buff_seek, stdout_buff[0], stdout_buff[54], stdout_buff);
/*
    BIG_NUMBER stdout_buff_index = 0;
print_loop:
    if (stdout_buff_index++ != stdout_buff_seek)
    {
        goto print_loop_end;
    }
    putchar_unlocked(stdout_buff[stdout_buff_index] ? '1' : '0');
    putchar_unlocked('\n');
*/
    // printf("-----\n2 => %d, 9 => %d, 11 => %d, 30 => %d", cache_get(cache_result, 2), cache_get(cache_result, 9), cache_get(cache_result, 11), cache_get(cache_result, 30));
//print_loop_end:
    return 0;
}
