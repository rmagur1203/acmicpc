import math
for _ in range(int(input())):
    H, W, N = map(int, input().split())
    x = math.ceil(N / H)
    y = N % H
    if y == 0:
        y = H
    print(f'{y}{str(x).zfill(2)}')