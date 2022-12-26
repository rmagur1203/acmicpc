#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

/**
 * 2239. 스도쿠
 * https://www.acmicpc.net/problem/2239
 * 
 * 1. 9x9 스도쿠를 입력받는다.
 * 2. 1~9까지의 숫자를 하나씩 넣어보면서 가능한지 확인한다.
 * 3. 가능하다면 다음 칸으로 넘어가고, 불가능하다면 다른 숫자를 넣어본다.
 * 4. 모든 칸에 숫자를 넣었다면 출력하고 종료한다.
 * 5. 모든 칸에 숫자를 넣지 못했다면 종료한다.
 * 
 * 분류: 백트래킹
*/

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

int calc(int y, int x){
    return (y / 3) * 3 + (x / 3);
}

void print(){
    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++){
            cout << sudoku[y][x];
        }
        cout << endl;
    }
}

void fill(int y, int x){
    if (y == 9){
        print();
        exit(0);
    }

    if (sudoku[y][x] != 0){
        if (x == 8){
            fill(y + 1, 0);
        } else {
            fill(y, x + 1);
        }
    } else {
        for (int n = 1; n <= 9; n++){
            if (!row[y][n] && !col[x][n] && !square[calc(y, x)][n]){
                sudoku[y][x] = n;
                row[y][n] = true;
                col[x][n] = true;
                square[(y / 3) * 3 + (x / 3)][n] = true;

                if (x == 8){
                    fill(y + 1, 0);
                } else {
                    fill(y, x + 1);
                }

                sudoku[y][x] = 0;
                row[y][n] = false;
                col[x][n] = false;
                square[(y / 3) * 3 + (x / 3)][n] = false;
            }
        }
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    for (int y = 0; y < 9; y++){
        char line[10];
        cin >> line;
        for (int x = 0; x < 9; x++){
            int n = line[x] - '0';
            sudoku[y][x] = n;
            row[y][n] = true;
            col[x][n] = true;
            square[calc(y, x)][n] = true;
        }
    }

    fill(0, 0);

    cout << -1 << endl;
}