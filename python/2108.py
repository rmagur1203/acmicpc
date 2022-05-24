from collections import Counter
import sys
n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()
print("*******************")
print(arr)
print(round(sum(arr) / n))
print(arr[int(n / 2)])
ct = Counter(arr)
if n >= 2 and ct.most_common(2)[0][1] == ct.most_common(2)[1][1]:
    print(ct.most_common(2)[1][0])
else:
    print(ct.most_common(1)[0][0])
print(abs(max(arr) - min(arr)))