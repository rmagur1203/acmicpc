# tie() = tuple<>...
```cpp
int v1, v2, v3;
tuple<int, int, int> item = {0, 1, 2};
tie(v1, v2, v3) = item;
```

tie를 통해 튜플을 변수에 나눠서 넣어줄 수 있다.