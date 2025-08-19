// �̷� Ž��

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

    // �̷� �Է�
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            miro[i][j] = line[j] - '0';
        }
    }
    pair<int, int> pos;
    queue<pair<int, int>> q;

    // �̷��� ó�� ������ �׻� 0, 0
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

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // ������ �Ѿ�ٸ� �Ѿ��
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


// ó�� �ڵ��� ���� ��Ʈ
//1. �ε��� ���� �ڹٲ�
//2. ���� üũ �ڹٲ�
//3. �������� �߸���
//4. �湮ó��/�Ÿ��迭 ����
//5. count�� ����Ÿ��� �ƴ�