def run():
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    count = 0
    for i in range(n):
        cx, cy, r = map(int, input().split())
        r2 = r**2
        d1 = ((cx - x1) ** 2) + ((cy - y1) ** 2)
        d2 = ((cx - x2) ** 2) + ((cy - y2) ** 2)
        if (r2 >= d1 and r2 < d2) or (r2 < d1 and r2 >= d2):
            count += 1
    return count

for i in range(int(input())):
    print(run())