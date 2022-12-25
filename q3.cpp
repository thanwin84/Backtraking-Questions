#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
int x_coordinates[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int y_coordinates[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int a[1001][1001];
int ans_map[1001][1001];
int step = 1, count = 0;
int minans = INT_MAX;
int minans_cnt;
int is_ans = 0;
int r_row, r_col, j_row, j_col;
int N, M, K;
void findSolution(int x, int y, int step, int turn, int dir) {
    if (x == j_row && y == j_col && step == N * M - K && turn <= minans) {
        if (turn < minans) {
            minans = turn;
            minans_cnt = 1;
            is_ans = 1;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    ans_map[i][j] = a[i][j];
                }
            }
        }
        else minans_cnt++;

        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + x_coordinates[i];
        int ny = y + y_coordinates[i];
        if (nx > 0 && nx <= N && ny > 0 && ny <= M && a[nx][ny] == 0) {
            // do
            a[nx][ny] = step + 1;
            // recurse
            if (dir != i) {
                if (turn + 1 <= minans) {
                    findSolution(nx, ny, step + 1, turn + 1, i);
                }
            }
            else  findSolution(nx, ny, step + 1, turn + 1, i);
            // undo
            a[nx][ny] = 0;
        }
    }
}


int main() {
    cin >> N;
    cin >> M;
    cin >> K;
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x;
        cin >> y;
        // mark closed cell with -1
        a[x][y] = -1;
    }
    cin >> r_row;
    cin >> r_col;
    cin >> j_row;
    cin >> j_col;

    a[r_row][r_col] = 1;
    findSolution(r_row, r_col, 1, -1, 8);
    if (is_ans) {
        cout << minans << endl;
        cout << minans_cnt << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cout << ans_map[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "not pobbile" << endl;
    }
    return 0;
};
