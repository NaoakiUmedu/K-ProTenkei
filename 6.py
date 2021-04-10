"""文字列の貪欲法で取るものは、その文字が次に出てくる位置の配列を作る"""
s: str = input()
k: int = int(input())

rstr: str = reversed(s)
appear_point = [[0 for i in range(len(s))] for i in range(26)]

# 位置を探索
# 計算量は26 * len(str)
cnt: int = len(s) - 1
for c in rstr:
    for i in range(26):
        if ord(c) == i + ord('a'):
            appear_point[i][cnt] = cnt
        else:
            if cnt <= len(s) - 2:
                appear_point[i][cnt] = appear_point[i][cnt+1]
            else:
                appear_point[i][cnt] = -1

    cnt -= 1

# print(appear_point)

ans: str = ''
current_pos = 0
for i in range(k):
    # print(ans)
    # 各文字が使えるかどうか判定
    for j in range(26):
        # print(i, j, current_pos)
        if appear_point[j][current_pos] == -1:
            # もう出てこない
            continue

        next_pos = appear_point[j][current_pos]
        # その文字を使った後、K 文字作れるか考える
        # 後の文字がなんでも、jが小さいものを今使った方が早いので
        # K文字選べることがわかっていればよい
        # その文字がnext_posめなら、next_pos+1 ~ len(s) -1 までは
        # 何らかの文字が入っている
        # 可能な長さ = (文字列長 - 次の位置) + 既に作った長さ
        max_possible_length = int(len(s) - next_pos) + i
        if max_possible_length >= k:
            ans += chr(j + ord('a'))
            current_pos = next_pos + 1
            break

print(ans)
