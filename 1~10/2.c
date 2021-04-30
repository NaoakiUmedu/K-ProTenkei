#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 諦めてbit全探索してどうぞ */
int check(const char *str, size_t N)
{
    int mae = 0;
    int usihro = 0;
    for (int itr = 0; itr < N; itr++)
    {
        if (str[itr] == '(')
        {
            mae++;
        }
        else
        {
            usihro++;
        }

        if (usihro > mae)
        {
            return -1;
        }
    }

    if (mae != usihro)
    {
        return -1;
    }

    return 0;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    const unsigned int MaxBit = 1 << N;
    for (int flag = 0; flag < MaxBit; flag++)
    {
        char str[N + 1];
        memset(str, '\n', sizeof(str));
        for (int i = 0; i < N; i++)
        {
            if (flag & (1 << i))
            {
                str[i] = '(';
            }
            else
            {
                str[i] = ')';
            }
        }

        if (check(str, N) == 0)
        {
            printf("%s", str);
        }
    }
    return 0;
}