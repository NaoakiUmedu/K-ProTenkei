/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
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
    double T, L, X, Y;
    std::cin >> T;
    std::cin >> L >> X >> Y;

    int Q;
    std::cin >> Q;
    rep(i, Q)
    {
        double E;
        std::cin >> E;

        // 観覧車の位置
        double a = 0.0;
        double b = -1 * (L / 2) * sin(E / T * 2 * M_PI);
        double c = (L / 2) - ((L / 2) * cos(E / T * 2 * M_PI));
        // printf("[%f:%f:%f]", a, b, c);

        // ちょくだいぞうとの距離
        double A = sqrt((X * X) + ((Y - b) * (Y - b)));
        double B = c;

        double ans_rad = atan2(B, A);
        double ans_deg = 360 * (ans_rad / (2 * M_PI));
        printf("%.12f\n", ans_deg);
    }

    return 0;
}