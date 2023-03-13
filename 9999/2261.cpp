#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int N;
int minx, miny, maxx, maxy;

pair<int, int> find(int x, int y, int dx, int dy) {
    while (x >= minx && x <= maxx && y >= miny && y <= maxy) {
        x += dx;
        y += dy;
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    
}