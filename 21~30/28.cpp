/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
/* 領域加算は2次元いすも法 */
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
    std::vector<std::vector<int>> Isumo2d(10001, std::vector<int>(1001, 0));

    rep(i, N)
    {
        int rx, ry, lx, ly;
        std::cin >> rx >> ry >> lx >> ly;
        Isumo2d[rx][ry]++;
        Isumo2d[lx][ly]++;
        Isumo2d[rx][ly]--;
        Isumo2d[lx][ry]--;
    }

    rep(i, 1001)
    {
        rep(j, 1000)
        {
            Isumo2d[i][j + 1] += Isumo2d[i][j];
        }
    }

    rep(i, 1001)
    {
        rep(j, 1000)
        {
            Isumo2d[j + 1][i] += Isumo2d[j][i];
        }
    }

    // std::cout << "Isumo2d" << std::endl;
    // rep(i, 10)
    // {
    //     rep(j, 10)
    //     {
    //         std::cout << Isumo2d[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << "Isumo2d" << std::endl;

    std::vector<int> Ans(N + 1, 0);
    rep(i, 1001)
    {
        rep(j, 1001)
        {
            Ans[Isumo2d[i][j]]++;
        }
    }

    Ans.erase(Ans.begin());
    for (int ans : Ans)
    {
        std::cout << ans << std::endl;
    }

    return 0;
}