import heapq
import sys
heap = []
n = int(sys.stdin.readline())
for _ in range(n):
    heapq.heappush(heap, int(sys.stdin.readline()))
for _ in range(n):
    print(heapq.heappop(heap))