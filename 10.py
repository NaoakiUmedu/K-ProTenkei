# 10問目
n: int = int(input())
ruisekiwa1: list = [0 for i in range(n+2)]
ruisekiwa2: list = [0 for i in range(n+2)]

for i in range(n):
    c: int
    p: int
    c, p = map(int, input().split())

    if c == 1:
        ruisekiwa1[i+1] += p
    else:
        ruisekiwa2[i+1] += p
    ruisekiwa1[i+2] = ruisekiwa1[i+1]
    ruisekiwa2[i+2] = ruisekiwa2[i+1]

#print(ruisekiwa1)
#print(ruisekiwa2)

q: int = int(input())
for i in range(q):
    l, r = map(int, input().split())
    a1: int = ruisekiwa1[r] - ruisekiwa1[l-1]
    a2: int = ruisekiwa2[r] - ruisekiwa2[l-1]
    print(a1, a2)


