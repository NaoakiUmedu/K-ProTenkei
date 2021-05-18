#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int N;
	std::cin >> N;
	std::vector<int> St(N);
	std::vector<int> Sc(N);
	for(int i = 0; i < N; i++)
	{
		std::cin >> St[i];
	}
	for(int i = 0; i < N; i++)
	{
		std::cin >> Sc[i];
	}
	std::sort(St.begin(), St.end());
	std::sort(Sc.begin(), Sc.end());

	long long Ans = 0;
	for(int i = 0; i < N; i++)
	{
		Ans += static_cast<long long>(std::abs(St[i] - Sc[i]));
	}

	std::cout << Ans << std::endl;
	return 0;
}
