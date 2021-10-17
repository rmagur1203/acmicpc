import sys
import heapq

mn = []
mx = []
n = int(sys.stdin.readline())

for _ in range(n):
    k = int(sys.stdin.readline())

    if len(mn) == len(mx):
        heapq.heappush(mx, (-k, k))
    else:
        heapq.heappush(mn, (k, k))

    if mn and mn[0][1] < mx[0][1]:
        tmn = heapq.heappop(mn)[1]
        tmx = heapq.heappop(mx)[1]
        heapq.heappush(mx, (-tmn, tmn))
        heapq.heappush(mn, (tmx, tmx))
    
    print(mx[0][1])