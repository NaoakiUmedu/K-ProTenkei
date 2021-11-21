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
//const long long MOD = 998244353;
// const long long MOD = 1000000007;
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
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> A(N, std::vector<int>(N));
	rep(i, N)
	{
		rep(j, N)
		{
			std::cin >> A[i][j];
			// printf("a\n");
		}
	}
	int M;
	std::cin >> M;
	std::vector<std::vector<bool>> Rumor(N, std::vector<bool>(N, false));
	rep(i, M)
	{
		int X, Y;
		std::cin >> X >> Y;
		X--;
		Y--;
		Rumor[X][Y] = true;
		Rumor[Y][X] = true;
		// printf("b\n");
	}

	std::vector<int> runner_list;
	rep(i, N)
	{
		runner_list.push_back(i);
	}

	const int NG = 1000 * 10 + 1;
	int min = NG;
	do
	{
		int time = 0;
		int pre = -1;
		int zone = 0;
		// std::vector<int> dbg;
		for (int runner : runner_list)
		{
			if (pre != -1)
			{
				if (Rumor[pre][runner])
				{
					time = NG;
					break;
				}
			}
			pre = runner;
			// dbg.push_back(runner);
			time += A[runner][zone];
			zone++;
		}
		// printf("Runner->");
		// for (int now : dbg)
		// {
		// 	printf("%d ", now);
		// }
		// printf("time->%d\n", time);
		min = std::min(time, min);
	} while (std::next_permutation(runner_list.begin(), runner_list.end()));

	if (min == NG)
	{
		min = -1;
	}
	std::cout << min << std::endl;

	return 0;
}