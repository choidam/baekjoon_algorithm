/*
 백준 1987번
 [DFS/Backtracking] 알파벳
 */

#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C;
int ans;
char board[20][20];
int alphabet[26]; // A~Z

void dfs(int y, int x, int cnt) {
    
    ans = max(ans, cnt);
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;
        
        int k = (int)board[ny][nx] - 65;
        
        if (alphabet[k]) // 이미 방문한 알파벳인 경우
            continue;
        
        alphabet[k]++;
        dfs(ny, nx, cnt + 1);
        alphabet[k]--; // 백트래킹
    }
}

int main(void) {
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    alphabet[(int)board[0][0] - 65]++; // (0,0) 지점 방문 체크
    dfs(0, 0, 1);
    
    cout << ans << endl;
    
    return 0;
}
