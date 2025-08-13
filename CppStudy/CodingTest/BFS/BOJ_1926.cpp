// BFS 문제
#include <iostream>
#include <queue>
//#include <utility>
using namespace std;

int board[502][502];
int vis[502][502];

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	// board 값 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int mx = 0;	 // 그림의 최대값
	int num = 0; // 그림의 수
	
	queue<pair<int, int>> q;

	//한 영역을 찾기 위한
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << "start\n"; debug
			//이미 방문했으면 건너뜀
			if (board[i][j] == 0 || vis[i][j]) continue;
			//방문 안 했으면 push
			q.push({ i, j });
			vis[i][j] = 1; // 방문처리

			int cx = 1;
			while (!q.empty()) {
				//queue<pair<int, int>> qq; // 굳이 큐를 2개 만들 필요가 없었다
				pair<int, int> cur;
				//cur.first, cur.second = q.front();
				cur = q.front(); // 나눠주기(?) 가능
				q.pop();
				// 시작 영역을 찾았을 때 연결된 구역 찾기 시작
				for (int a = 0; a < 4; a++) {
					int nx = cur.first + dx[a];
					int ny = cur.second + dy[a];
					// 사각형 영역 벗어나면 건너뜀
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					// 이미 방문한 곳이면 건너 뜀
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					q.push({ nx, ny });
					vis[nx][ny] = 1;
					cx += 1;	//여기서 카운트 하면 처음 시작 점을 카운트 안함
					// 처음을 1로 하던지 아니면 cur 설정할 때 +1 하던지
				}
			}
			//cout << cx << '\n'; debug
			if (cx > mx) mx = cx; // mx = max(mx, cx);
			num += 1;
		}
	}

	cout << num << '\n' << mx;

	return 0;
}