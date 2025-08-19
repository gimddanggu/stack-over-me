// 미로 탐색

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int miro[102][102];
    int vis[102][102] = { 0 };

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    int count = 0;

    // 미로 입력
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            miro[i][j] = line[j] - '0';
        }
    }
    pair<int, int> pos;
    queue<pair<int, int>> q;

    // 미로의 처음 시작은 항상 0, 0
    q.push({ 0,0 });
    count++;

    while (!q.empty()) {
        pos = q.front();
        q.pop();

        int cy = pos.first;
        int cx = pos.second;

        if (cy - 1 == n && cx - 1 == m) break;

        for (int d = 0; d < 4; d++) {
            int nx = dx[d] + cx;
            int ny = dy[d] + cy;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 범위가 넘어갔다면 넘어가기
            if (miro[ny][nx] != 1) continue;

            q.push({ ny, nx });
            vis[ny][nx] = 1;
            miro[ny][nx] = miro[cy][cx] + 1;

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << miro[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}


// 처음 코드의 오답 노트
//1. 인덱스 순서 뒤바뀜
//2. 범위 체크 뒤바뀜
//3. 종료조건 잘못됨
//4. 방문처리/거리배열 없음
//5. count는 정답거리가 아님