#include <iostream>

int main(void)
{
    long long A, B, C, N;
    std::cin >> N;
    std::cin >> A >> B >> C;
    long long ans = 10000;
    for (long long i = 0; i <= 9999; i++)
    {
        for (long long j = 0; i + j <= 9999; j++)
        {
            if ((N - (i * A) - (j * B)) % C == 0)
            {
                long long k = ((N - (i * A) - (j * B)) / C);
                if (k > 9999 || k < 0)
                {
                    continue;
                }
                // printf("[%lld:%lld:%lld]", i, j, k);
                // printf("%lld\n", A * i + B * j + C * k);
                ans = std::min(ans, (i + j + k));
            }
        }
    }
    std::cout << ans << std::endl;
}