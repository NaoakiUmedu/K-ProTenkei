/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < n; i++)

//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

struct UnionFind
{
    // 配列 value = 子なら親の番号、親ならグループのサイズ(判定のため-1 * size()の形で保持)
    // 例えば、size=8の親が保持するのは-8
    std::vector<int> d;
    // コンストラクタ サイズを初期化する
    UnionFind(int n = 0) : d(n, -1) {}
    // find インデックスxの要素の根っこ(=所属グループ)をみつける
    int find(int x)
    {
        if (d[x] < 0)
        {
            // 子ではなく親
            // 自身を返す(再帰の端っこ)
            return x;
        }
        // 親ではないので探しに行く
        return d[x] = find(d[x]);
    }
    // Unite 貰った2要素を追加してくっつけていく
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y); // 両方の根っこを扱う
        if (x == y)
            return false; // おんなじのはつながらない(同じ要素じゃん)
        if (d[x] > d[y])
            std::swap(x, y); // 小さい方につなげる
        d[x] += d[y];        // 連結のサイズを合算する
        d[y] = x;            // yの親をxの親に更新する
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; } //  サイズは-で持っている
};

int main(void)
{
#if 0
    //ファイルから読み込みたいとき
    std::ifstream in();
    std::cin.rdbuf(in.rdbuf());
#endif
    int H, W;
    std::cin >> H >> W;
    int Q;
    std::cin >> Q;

    UnionFind RedSq((H * 10000) + W); // 最大の別れ方は各マスごと
    std::vector<std::vector<bool>> IsRed(H, std::vector<bool>(W, false));

    const int mvx[4] = {0, 0, -1, 1};
    const int mvy[4] = {-1, 1, 0, 0};

    // 連接判定はUnion Find木を使う
    rep(i, Q)
    {
        int T = 0;
        std::cin >> T;
        if (T == 1)
        {
            int x, y;
            std::cin >> x >> y;
            x--;
            y--;
            IsRed[x][y] = true;
            // もし周りが赤かったら、くっつける
            rep(i, 4)
            {
                if (x + mvx[i] < 0 || x + mvx[i] >= H)
                {
                    continue;
                }
                if (y + mvy[i] < 0 || y + mvy[i] >= W)
                {
                    continue;
                }

                if (IsRed[x + mvx[i]][y + mvy[i]] == true)
                {
                    // hash = [x軸位置]*10000+[y軸位置]
                    int hash1 = x * 10000 + y;
                    int hash2 = (x + mvx[i]) * 10000 + y + mvy[i];
                    RedSq.unite(hash1, hash2);
                }
            }
        }
        else
        {
            int ax, ay, bx, by;
            std::cin >> ax >> ay >> bx >> by;
            ax--;
            ay--;
            bx--;
            by--;
            int hash1 = ax * 10000 + ay;
            int hash2 = bx * 10000 + by;

            bool Result = RedSq.same(hash1, hash2);
            if (IsRed[ax][ay] == false || IsRed[bx][by] == false)
            {
                Result = false;
            }
            if (Result == true)
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
    }

    return 0;
}