from collections import deque
# import doctest


def solve():
    n: int = int(input())
    road: list = [[] for i in range(n)]

    for i in range(n-1):
        (a, b) = map(int, input().split())
        # 添字に使う
        a = a - 1
        b = b - 1
        road[a].append(b)
        road[b].append(a)
    # 2回最長経路を探索する
    dist_1 = [-1 for i in range(n)]
    dist_1[0] = 0
    distance = 0

    que_1 = deque()
    que_1.append(0)
    farest_point: int = 0
    while que_1:
        now = que_1.pop()
        for next in road[now]:
            if dist_1[next] == -1:
                que_1.appendleft(next)
                dist_1[next] = dist_1[now]+1
                farest_point = next

    # print(dist_1)

    dist_2 = [-1 for i in range(n)]
    dist_2[farest_point] = 0
    distance2 = 0

    que_2 = deque()
    que_2.append(farest_point)
    while que_2:
        now = que_2.pop()
        for next in road[now]:
            if dist_2[next] == -1:
                que_2.appendleft(next)
                dist_2[next] = dist_2[now] + 1

    ans: int = 0
    for val in dist_2:
        ans = max(ans, val)
    # print(dist_2)
    print(ans+1)


solve()
