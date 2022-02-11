/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <cstring>
#include <cstdint>
#include <tuple>
#include <fstream>
#include <numeric>

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
	for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<int, int>;

/*** CONST DEFINES ***/
// const long long MOD = 998244353;
//  const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const int INF32 = 1000000000;

/*** UTILITY CLASS ***/

/*** FUNCTIONS ***/

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/

int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in();
	std::cin.rdbuf(in.rdbuf());
#endif
	int N, K;
	std::cin >> N >> K;
	std::vector<int> a(N);
	rep(i, N)
	{
		std::cin >> a[i];
	}

	std::map<int, int> numbers;
	int head = 0;
	int tail = 0;
	int max = 0;
	while (head < N)
	{
		const int now = a[head];
		const int pre_kind = numbers.size();
		if ((numbers.find(now) == numbers.end()) && (pre_kind + 1 > K))
		{
			while (true)
			{
				const int tail_num = a[tail];
				numbers[tail_num]--;
				tail++;
				if (numbers[tail_num] == 0)
				{
					// std::cout << tail_num << "is erased" << std::endl;
					numbers.erase(tail_num);
					break;
				}
			}
		}
		else
		{
		}
		numbers[now]++;
		max = std::max(max, head - tail);
		// std::cout << tail << ":" << head << std::endl;
		head++;
		// for (auto p : numbers)
		// {
		// 	std::cout << "[" << p.first << ":" << p.second << "] ";
		// }
		// std::cout << std::endl;
	}
	std::cout << max + 1 << std::endl;
	return 0;
}
