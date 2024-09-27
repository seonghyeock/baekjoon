#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans = 65; // �簢������ �ּ� ũ��
int cnt; // cctv�� ������ �� �ִ� ������ ��
int board[8][8];
int visited[8][8];
vector<pair<int, int>> cctv; // cctv�� ��ǥ

int cal(int x, int y, int d) {
	// �⺻ ���¸� �������� d�� ���� 1�� �����ϸ� �ݽð� �������� 90�� ȸ��

	int type = board[x][y];

	if (type == 1) {

	}
}

void dfs(int k) {
	// ��� cctv�� ������ ���
	if (k == cctv.size() - 1) {
		ans = min(ans, n * m - cnt);
		return;
	}

	int x = cctv[k].first;
	int y = cctv[k].second;
	for (int i = 0;i < 4;i++) {
		// ���� cctv�� ���⿡ ���� ���� ���ο� ���� ������ ��
		int newCnt = cal(x, y, i);

		cnt += newCnt;
		dfs(k + 1);
		cnt -= newCnt;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];

			// �Էµ� ���� cctv���
			if (board[i][j] > 0 && board[i][j] < 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0);
	cout << ans;
}