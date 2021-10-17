import math
a, b, v = map(int, input().split())
d = math.ceil((v - a) / (a - b)) + 1
print(d)