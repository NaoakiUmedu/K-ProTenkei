a: int
b: int
c: int
(a, b, c) = map(int, input().split())

c_b: int = 1
for i in range(b):
    c_b *= c

# print(a, c_b)
if a < c_b:
    print("Yes")
else:
    print("No")
