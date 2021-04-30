# 7問目
import bisect

n: int = int(input())
lessons: list = list(map(int, input().split()))
q: int = int(input())
students: list = [int(input()) for i in range(q)]

score: int = 0
lessons.sort()

# 2分探索をやる
ans: int = 0
for student in students:
    try:
        itr = bisect.bisect(lessons, student)
        ac = 0
        if itr >= 1:
            ac = itr - 1
        wa = itr
        if wa >= n:
            wa = n-1

        if abs(lessons[wa] - student) < abs(lessons[ac] - student):
            ans = int(abs(lessons[wa] - student))
        else:
            ans = int(abs(lessons[ac] - student))
    except IndexError:
        print("IndexError stu : ", student)
        # ans = int(abs(lessons[ac] - student))
        exit()

    print(ans)
    ans = 0
