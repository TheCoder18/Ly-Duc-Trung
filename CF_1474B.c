/**
 * @file CF_1474B.c
 * @author Ly Duc Trung (lyductrungmoney@gmail.com)
 * @brief 
 * How to solve this problem ?
 * - The first divisor always is 1.
 * - Therefore, "difference between any two divisors of a is at least d"
 * means the next divisor is greater than or equal (1+d).
 * - To ensure that there is no divisor between 1 and (1+d), (1+d) has to
 * be a prime number, then the next divisor must be prime number and greater
 * than 2*(1+d).
 * - Then we just need to multiply just-found prime numbers to have result.
 * @version 1.0
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIMIT 30000

void create_prime_list(int array[])
{
    int index = 0;
    for (int number = 1; number < LIMIT; number++)
    {
        bool isprime = true;
        for (int temp = 2; temp < number; temp++)
        {
            if ((number % temp == 0) && (temp < number))
            {
                isprime = false;
                break;
            }
        }

        if (isprime == true)
        {
            array[index] = number;
            index = index + 1;
        }
    }
}

int main()
{
    int prime[LIMIT];

    create_prime_list(prime);

    int count, index, sub_index;
    scanf("%d", &count);

    int *diff = (int *)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        index = 0;
        scanf("%d", &diff[i]);
        while (1)
        {
            if (prime[index] > diff[i])
                break;
            index = index + 1;
        }

        sub_index = index + 1;

        while (1)
        {
            if (prime[sub_index] >= (prime[index] + diff[i]))
                break;
            sub_index = sub_index + 1;
        }
        diff[i] = prime[index] * prime[sub_index];
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", diff[i]);
    }
    return 0;
}