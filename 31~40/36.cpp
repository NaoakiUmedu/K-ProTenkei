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
#include <tuple>
#include <fstream>
#include <numeric>

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
	for (ll i = 0; i < n; i++)

using ll = long long;
using P = std::pair<ll, ll>;

/*** CONST DEFINES ***/
// const long long MOD = 998244353;
//  const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const ll INF32 = 1000000000;

/*** UTILITY CLASS ***/
struct Poll
{
	ll x;
	ll y;
};
/*** FUNCTIONS ***/

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/
int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in("./in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif
	ll N, Q;
	std::cin >> N >> Q;
	std::vector<Poll> Origin(N);
	std::vector<Poll> Converted(N);
	std::vector<ll> Big4(4);
	rep(i, N)
	{
		std::cin >> Origin[i].x >> Origin[i].y;
		// xかyのどちらかがマンハッタン距離を示すように加工する
		Converted[i].x = Origin[i].x - Origin[i].y;
		Converted[i].y = Origin[i].x + Origin[i].y;
		Big4[0] = std::max(Big4[0], Converted[i].x);
		Big4[1] = std::max(Big4[1], Converted[i].y);
		Big4[2] = std::min(Big4[2], Converted[i].x);
		Big4[3] = std::min(Big4[3], Converted[i].y);
	}

	rep(j, Q)
	{
		ll q;
		std::cin >> q;
		q--;
		ll max_dist = 0;
		max_dist = std::max(max_dist, std::abs(Converted[q].x - Big4[0]));
		max_dist = std::max(max_dist, std::abs(Converted[q].y - Big4[1]));
		max_dist = std::max(max_dist, std::abs(Converted[q].x - Big4[2]));
		max_dist = std::max(max_dist, std::abs(Converted[q].y - Big4[3]));
		std::cout << max_dist << std::endl;
	}
	return 0;
}