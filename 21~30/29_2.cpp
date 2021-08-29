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
	// その2 座標圧縮をやる
	// Ex 
	// [in]
	// 7 3
	// 2 3
	// 6 7
	// 2 4
	//
	// [Done] := 座標圧縮したブロックの範囲
	// 0|1
	// 3|4
	// 0|2
    // 
	// [Height] := 座標圧縮した箇所の高さ
	// 2 3 4 6 7
	// |1|0|0|0|
	// |1|0|0|1|
	// |2|2|0|1|
	
	
	int W, N;
	std::cin >> W >> N;
	std::vector<P> Block(N);
	rep(i, N)
	{
		std::cin >> Block[i].first >> Block[i].second;
		Block[i].first--;	// ブロックの端はHeightの右端の線になる
	}
	
	std::vector<int> Compression;	// 圧縮済み配列
	rep(i, N)
	{
		Compression.push_back(Block[i].first);
		Compression.push_back(Block[i].second);
	}
	std::sort(Compression.begin(), Compression.end());
	Compression.erase(std::unique(Compression.begin(), Compression.end()), Compression.end());
	std::vector<P> Done;
	for(P now : Block)
	{
		P Won;
		Won.first = std::lower_bound(Compression.begin(), Compression.end(), now.first) - Compression.begin();
		Won.second = std::lower_bound(Compression.begin(), Compression.end(), now.second) - Compression.begin();
		Done.push_back(Won);
	}
	
	// std::cout << "=== DBG ===" << std::endl;
	// std::cout << "[Done]" << std::endl;
	// for(P now : Done)
	// {
	// 	std::cout << now.first << "|" << now.second << std::endl;
	// }
	// std::cout << "=== DBG ===" << std::endl;
	
	
	std::vector<int> Height(Compression.size() - 1);
	std::vector<int> Ans;
	// std::cout << "=== DBG ===" << std::endl;
	// std::cout << "[Height]" << std::endl;
	rep(i, N)
	{
		int h = *(std::max_element(Height.begin() + Done[i].first, Height.begin() + Done[i].second));
		h++;
		std::fill(Height.begin() + Done[i].first, Height.begin() + Done[i].second, h);
		Ans.push_back(h);
		
		//*** DBG
		// std::cout << "|";
		// for(int now : Height)
		// {
		// 	std::cout << now << "|";
		// }
		// std::cout << std::endl;
		// //*** DBG
		
	}
	//std::cout << "=== DBG ===" << std::endl;
	
	for(int now : Ans)
	{
		std::cout << now << std::endl;
	}
	
	return 0;
}
