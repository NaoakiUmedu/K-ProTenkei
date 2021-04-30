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
int main(void);
int slove(void);

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/

int main(void)
{
#ifdef DEB
    std::cout << "test start";
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

    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    std::vector<int> Tate(H);
    std::vector<int> Yoko(W);
    rep(i, H)
    {
        rep(j, W)
        {
            std::cin >> A[i][j];
            Yoko[j] += A[i][j];
        }
    }

    rep(j, W)
    {
        rep(i, H)
        {
            Tate[i] += A[i][j];
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            std::cout << Tate[i] + Yoko[j] - A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}