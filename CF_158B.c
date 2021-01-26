/**
 * @file CF_158B.c
 * @author Ly Duc Trung (lyductrungmoney@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2021-01-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int main()
{
    /* 
    x1 is the number of group 1 person
    x2 is the number of group 2 people
    x3 is the number of group 3 people
    x4 is the number of group 4 people
    */

    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int total, temp, S = 0;

    scanf("%d", &total);

    for (int i = 0; i < total; i++)
    {
        scanf("%d", &temp);
        if (temp == 1)
            x1 = x1 + 1;
        if (temp == 2)
            x2 = x2 + 1;
        if (temp == 3)
            x3 = x3 + 1;
        if (temp == 4)
            x4 = x4 + 1;
    }

    S = x4 + x3;

    if (x1 <= x3)
        x1 = 0;
    else
        x1 = x1 - x3;

    if (x2 % 2 == 1)
        x1 = x1 - 2;

    S = S + (x2 + 1) / 2;
    S = S + (x1 + 3) / 4;

    printf("%d", S);

    return 0;
}