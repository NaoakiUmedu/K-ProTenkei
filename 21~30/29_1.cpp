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
const long long MOD = 998244353;
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
	int W, N;
	std::cin >> W >> N;
	std::vector<int> Height(W);
	std::vector<int> Out;
	rep(i, N)
	{
		int L, R;
		std::cin >> L >> R;
		L--;
		R--;
		int Max = 0;
		for(int j = L; j <= R; j++)
		{
			Max = std::max(Max, Height[j]);
		}
		Max++;
		for(int j = L; j <= R; j++)
		{
			Height[j] = Max;
		}
		Out.push_back(Max);
	}
	
	//std::cout << "=============================" << std::endl;
	//for(int now : Height)
	//{
	//	std::cout << now;
	//}
	//std::cout << std::endl;
	//std::cout << "=============================" << std::endl;
	
	for(int now : Out)
	{
		std::cout << now << std::endl;
	}

	return 0;
}
