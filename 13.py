import heapq

INF: int = 1e60


def djk(route: list, stt: int) -> list:
    """ダイクストラ法でsttからdstまでの最短距離を求める"""
    # 最短距離
    mindist: list = [INF for i in range(len(route))]
    # 優先度付きキュー ダイクストラは「コストで」ソートする
    hq: list = []

    # 初期化
    mindist[stt] = 0
    heapq.heappush(hq, (0, stt))

    while(len(hq) != 0):
        nownode = heapq.heappop(hq)
        for nextnode in route[nownode[1]]:
            if (nownode[0] + nextnode[1]) < mindist[nextnode[0]]:
                # より小さいコストでつける場合のみ記録する
                mindist[nextnode[0]] = nownode[0]+nextnode[1]
                heapq.heappush(hq, (mindist[nextnode[0]], nextnode[0]))

    # print(mindist)
    return mindist


m: int
n: int
(n, m) = map(int, input().split())

route: list = [[] for i in range(n)]
for i in range(m):
    a: int
    b: int
    c: int
    (a, b, c) = map(int, input().split())
    a -= 1
    b -= 1
    route[a].append((b, c))
    route[b].append((a, c))

# print(route)

# 0からの距離とn-1からの距離がわかって入ればよい
mindist_1 = djk(route, 0)
mindist_n = djk(route, n-1)

for k in range(n):
    print(mindist_1[k]+mindist_n[k])
