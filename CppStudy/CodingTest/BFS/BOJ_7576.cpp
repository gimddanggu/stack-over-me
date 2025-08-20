// 토마토

#include <iostream>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& garden);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    int day = 0;
    // 배열을 너무 크게 만들면 스탬 메모리 초과로 인해
    // 입력 받기 전에 프로그램이 비정상 종료된다
    // 방법1. 전역변수로 선언
    // 방법2. vector 사용
    /*int garden[10][10];
    int vis[10][10];*/

    vector<vector<int>> garden(n, vector<int>(m));
    //vector<vector<int>> vis(n, vector<int>(m));

    queue<pair<int, int>> q;

    //// 토마토 채우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }

    cout << bfs(garden);
   

    return 0;
}

int bfs(vector<vector<int>>& garden) {

    int n = garden.size();
    int m = garden[0].size();

    queue<pair<int, int>> q;

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (garden[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> pos = q.front(); q.pop();
        int cy = pos.first;
        int cx = pos.second;

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            //if (vis[ny][nx] == 1 || garden[ny][nx] == 0) continue;
            if (garden[ny][nx] != 0) continue;

            q.push({ ny, nx });
            garden[ny][nx] = garden[cy][cx] + 1;

        }
    }
    //// 디버그용 출력
    //for (auto& row : garden) {
    //    for (auto& ele : row) {
    //        cout << ele << " ";
    //    }
    //    cout << '\n';
    //}

    // 최대값 찾기
    int maxVal = 0;
    /*for (auto& row : garden) {
        int rowMax = *max_element(row.begin(), row.end());
        maxVal = max(maxVal, rowMax);
    }*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (garden[i][j] == 0) return -1;
            maxVal = max(maxVal, garden[i][j]);
        }
    }
    // 삼항 연산자 익숙하지 않네..
    return (maxVal > 1) ? (maxVal - 1) : 0;
}

// 실수
// - bfs 함수 안에서 q를 새로 생성했으므로 큐가 비어있다.
// - 좌표 뒤 섞임
// - 방문/거리 처리 중복
// - 경계/통과 조건
// - 최대값 계산/정답 규칙
// - 초깃값 실수
// - 문제를 잘못이해하고 있었음 어느 위치에서 시작해서 빨리 익느냐가 아니라 
// 모두 익는데 얼마나 걸리는지 묻는 문제였다.

// 문제 이해를 잘 못하고있었던 거 같다.
// 처음 큐에 익은 토마토를 다 넣어버리면 양쪽에서 같이 진행되기 때문에 섞이면 어떡하지 ?
// 하는 고민이 있었는데 문제에서 한쪽에서 토마토가 익기 시작한다는 조건 자체가 없었다..
// 멀티레벨이라는 뜻을 잘 이해하지 못했었는데 이 문제로 어느 정도 느낌을 잡았다.