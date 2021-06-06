/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
/** 強連結成分: 有向グラフにおいて、互いに行き来が可能な頂点の集合
 ↑の数を数えることで、お互いに行き来が可能な頂点の組み合わせの数を計算出来る */
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
void dfs1(
    const std::vector<std::vector<int>> &Route,
    const int Pos,
    std::vector<bool> &Seen,
    std::vector<int> &DfsedPoint)
{
    // printf("dfs1[%d]\n", Pos);

    Seen[Pos] = true;
    for (int next : Route[Pos])
    {
        if (Seen[next] == false)
        {
            dfs1(Route, next, Seen, DfsedPoint);
        }
    }
    DfsedPoint.push_back(Pos); // ダブらないようにSeenをtrueにしてから自分の位置を記録
}

void dfs2(
    const std::vector<std::vector<int>> &Route,
    const int Pos,
    std::vector<bool> &Seen,
    ll &Cnt)
{
    // printf("DFS2[%d]\n", Pos);
    Seen[Pos] = true;
    Cnt++;
    for (int next : Route[Pos])
    {
        if (Seen[next] == false)
        {
            dfs2(Route, next, Seen, Cnt);
        }
    }
}

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
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> Route(N);    // 有向グラフ
    std::vector<std::vector<int>> RevRoute(N); // 逆向きのグラフ
    rep(i, M)
    {
        int A, B;
        std::cin >> A >> B;
        A--;
        B--;
        Route[A].push_back(B);
        RevRoute[B].push_back(A);
    }

    // Step1 dfsですべての点を探索する(1度では行けないところがある可能性がある)
    std::vector<int> DfsedPoint; // dfsした順に点を記録するメモ
    {
        std::vector<bool> Seen(N, false);
        rep(i, N)
        {
            if (Seen[i] == false)
            {
                dfs1(Route, i, Seen, DfsedPoint);
            }
        }
    }

    // Step2 さっきたどった順番と逆にdfsする
    // 逆順なので、奥の方の片道しかないノードは先にfalseになってしまうので
    // 強連結成分だけをdfsできる
    std::reverse(DfsedPoint.begin(), DfsedPoint.end());
    ll Ans = 0;
    {
        std::vector<bool> Seen(N, false);
        for (int stt : DfsedPoint)
        {
            if (Seen[stt] == false)
            {
                // printf("===stt[%d]===\n", stt);

                ll Cnt = 0;
                dfs2(RevRoute, stt, Seen, Cnt);
                Ans += (Cnt) * (Cnt - 1LL) / 2LL;
            }
        }
    }

    std::cout << Ans << std::endl;

    return 0;
}
