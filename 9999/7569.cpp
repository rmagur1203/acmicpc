#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int arr[101][101][101];
bool visited[101][101][101];
int main()
{
    int M, N, H;
    cin >> M >> N >> H;

    queue<tuple<int, int, int, int>> q;

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> arr[z][y][x];
                if (arr[z][y][x] == 1)
                    q.push({x, y, z, 0});
            }
        }
    }

    int mxdate = 0;
    while(!q.empty()){
        int x, y, z, day;
        tie(x, y, z, day) = q.front();
        q.pop();

        mxdate = max(mxdate, day);
        int dx[] = {0, 0, 0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0, 0, 0};
        int dz[] = {0, 0, 1, -1, 0, 0};

        for (int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && !visited[nz][ny][nx] && arr[nz][ny][nx] == 0){
                visited[nz][ny][nx] = true;
                arr[nz][ny][nx] = 1;
                q.push({nx, ny, nz, day + 1});
            }
        }
    }

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (arr[z][y][x] == 0)
                    return cout << "-1", 0;
            }
        }
    }
    cout << mxdate;
}