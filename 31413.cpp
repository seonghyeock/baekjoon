#include <iostream>
#include <algorithm>

using namespace std;

int v[1000]; // ����Ȱ�� ������
int dp[1000][1000]; // dp[i][j]: i�ϱ����� �ִ� ������, ���� j�� ��

int main() {
	int n, m, a, d; // n: ���� �ϼ�, m: �ʿ��� ������, a: ���� ������, d: ���� �� ����� �ϴ� ��
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> a >> d;

	dp[0][0] = v[0];
	dp[0][1] = a;

	int ans = 1001;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// ����Ȱ���� �ϴ� ���
			if (dp[i - 1][j] > dp[i - 1][j - 1]) {
				dp[i][j] = dp[i - 1][j] + v[i];
			}
			// ������ �ϴ� ���
			else {
				dp[i][j] = dp[i - 1][j - 1] + a;
				for (int k = 1; k <= d; k++) {
					dp[i + k][j] = dp[i][j];
				}
			}

			if (dp[i][j] >= m)
				ans = min(ans, j);
		}
	}

	if (ans != 1001)
		cout << ans;
	else
		cout << -1;
}