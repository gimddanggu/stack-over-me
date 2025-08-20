// �丶��

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
    // �迭�� �ʹ� ũ�� ����� ���� �޸� �ʰ��� ����
    // �Է� �ޱ� ���� ���α׷��� ������ ����ȴ�
    // ���1. ���������� ����
    // ���2. vector ���
    /*int garden[10][10];
    int vis[10][10];*/

    vector<vector<int>> garden(n, vector<int>(m));
    //vector<vector<int>> vis(n, vector<int>(m));

    queue<pair<int, int>> q;

    //// �丶�� ä���
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
    //// ����׿� ���
    //for (auto& row : garden) {
    //    for (auto& ele : row) {
    //        cout << ele << " ";
    //    }
    //    cout << '\n';
    //}

    // �ִ밪 ã��
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
    // ���� ������ �ͼ����� �ʳ�..
    return (maxVal > 1) ? (maxVal - 1) : 0;
}

// �Ǽ�
// - bfs �Լ� �ȿ��� q�� ���� ���������Ƿ� ť�� ����ִ�.
// - ��ǥ �� ����
// - �湮/�Ÿ� ó�� �ߺ�
// - ���/��� ����
// - �ִ밪 ���/���� ��Ģ
// - �ʱ갪 �Ǽ�
// - ������ �߸������ϰ� �־��� ��� ��ġ���� �����ؼ� ���� �ʹ��İ� �ƴ϶� 
// ��� �ʹµ� �󸶳� �ɸ����� ���� ��������.

// ���� ���ظ� �� ���ϰ��־��� �� ����.
// ó�� ť�� ���� �丶�並 �� �־������ ���ʿ��� ���� ����Ǳ� ������ ���̸� ����� ?
// �ϴ� ����� �־��µ� �������� ���ʿ��� �丶�䰡 �ͱ� �����Ѵٴ� ���� ��ü�� ������..
// ��Ƽ�����̶�� ���� �� �������� ���߾��µ� �� ������ ��� ���� ������ ��Ҵ�.