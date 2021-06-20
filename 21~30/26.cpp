/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
/* 26 : 木は2色にDFSで塗分ければ必ずどちらかはN/2以上になる */
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
enum COLOR
{
    CL_NONE = 0,
    CL_RED,
    CL_BLUE
};

/*** EXECUTE ***/

void Dfs(
    const std::vector<std::vector<int>> &Graph,
    const int Pos,
    const COLOR PreCl,
    std::vector<COLOR> &NodeColor)
{
    COLOR NextCl = CL_RED;
    if (PreCl == CL_RED)
    {
        NextCl = CL_BLUE;
    }

    for (int Next : Graph[Pos])
    {
        if (NodeColor[Next] == CL_NONE)
        {
            NodeColor[Next] = NextCl;
            Dfs(Graph, Next, NextCl, NodeColor);
        }
    }
}

int main(void)
{
#if 0
    //ファイルから読み込みたいとき
    std::ifstream in();
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> Graph(N);
    rep(i, N - 1)
    {
        int A, B;
        std::cin >> A >> B;
        A--;
        B--;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    std::vector<COLOR> NodeColor(N, CL_NONE);

    rep(i, N)
    {
        if (NodeColor[i] == CL_NONE)
        {
            NodeColor[i] = CL_RED;
            Dfs(Graph, i, CL_RED, NodeColor);
        }
    }

    int Cnt = 0;
    for (COLOR Cl : NodeColor)
    {
        if (Cl == CL_RED)
        {
            Cnt++;
        }
        else
        {
            Cnt--;
        }
    }

    COLOR AnsCl = CL_RED;
    if (Cnt < 0)
    {
        AnsCl = CL_BLUE;
    }

    int Cnt2 = 0;
    rep(i, N)
    {
        if (Cnt2 >= (N / 2))
        {
            break;
        }
        if (NodeColor[i] == AnsCl)
        {
            Cnt2++;
            std::cout << (i + 1) << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}