"1本の長いものを切れ目に沿って分割する時、一番短くなるピースを最大にする問題"
N, sL = input().split()  # map(int, input().split())
L = int(sL)
K = int(input())
A = list(map(int, input().split()))

# 切れるかチェックするときの便宜のため、おしりも切り込みということにする
A.append(L)

# 答えの長さで2分探索する
# 答えの範囲は1～1*10^5
# 答えはある一点を境にOKとNGがわかれるので、二分探索すればよい
# 探索にかかる時間は最大10^5 (ans=1のとき)
# よって計算量はlogN * N
ans = 0
right = L
left = 0
while(int(right/2) >= 1):
    half = left + int((right - left) / 2)
    # 全てのピースをhalf以上に分けられるか検討する
    cnt = 0
    pre = 0
    for a in A:
        if (a-pre) >= half:
            # 一度切れる
            cnt += 1
            pre = a

    if cnt >= K+1:
        # print(right, left, half, "OK")
        # OKのとき、ながい方にずらす
        if abs(right-half) == 1:
            ans = half
            break
        else:
            right = right
            left = half

    else:
        # print(right, left, half, "NG")
        # NGのとき、短い方にずらす
        right = half
        left = left

print(ans)
