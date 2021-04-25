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
#include <set>
#include <unordered_set>

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
    for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<ll, ll>;

/*** CONST DEFINES ***/
const long long MOD = 998244353;
// const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const int INF32 = 1000000000;

/*** UTILITY CLASS ***/
/*** FUNCTIONS ***/
int main(void);
int slove(void);

/*** GLOVAL VALIABLES ***/
/*** EXECUTE ***/

int main(void)
{
#ifdef DEB
    std::cout << "test start \n";
    while (true)
#endif
    {
        slove();
    }

    return 0;
}

int slove(void)
{
#if 0
    //ファイルから読み込みたいとき
    std::ifstream in();
    std::cin.rdbuf(in.rdbuf());
#endif
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;

    // 次どこに出てくるかのリストを作る
    // NextPos[c][4] -> 次にCが出てくるインデックス
    std::vector<std::vector<int>> NextPos(26, std::vector<int>(S.size(), -1));
    for (int i = S.size() - 1; i >= 0; i--)
    {
        for (char c = 0; c < 26; c++)
        {
            if (c + 'a' == S[i])
            {
                NextPos[c][i] = i;
            }
            else
            {
                if (i == S.size() - 1)
                {
                    NextPos[c][i] = -1;
                }
                else
                {
                    NextPos[c][i] = NextPos[c][i + 1];
                }
            }
        }
    }

    int Length = 0;
    int NowPos = 0;
    std::string Ans("");
    while (Length < K)
    {
        for (char c = 0; c < 26; c++)
        {
            if (NextPos[c][NowPos] != -1)
            {
                if (S.size() - 1 - (NextPos[c][NowPos]) >= K - Length - 1)
                {
                    Ans += c + 'a';
                    NowPos = NextPos[c][NowPos] + 1;
                    break;
                }
            }
        }
        Length++;
    }

    std::cout << Ans << std::endl;

    return 0;
}