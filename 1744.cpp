#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// ������ ũ�Ⱑ 1�� ��� �Է¹��� ���� �״�� ����Ѵ�.
	if (n == 1) {
		cout << v[0];
		return 0;
	}

	sort(v.begin(), v.end());

	long long ans = 0;
	int pos = 0; // ó������ ����� ���� �ε���

	// ���� ���� �Ǵ� 0�� �κ��� �����Ѵ�. ���� ������ ���´�.
	for (int i = 1;i < n;i++) {
		if (v[i] > 0) {
			pos = i;
			// �迭�� ��� ���� ����� ���� i - 1�� ° ���� ó������ ����̴�.
			if (v[i - 1] > 0)
				pos = i - 1;
			break;
		}

		// ���� �� ���� ���� �� �̹� ���� ���� ���� �ʾƾ� �Ѵ�.
		bool cond1 = v[i - 1] == -1001 || v[i] == -1001;
		if (!cond1) {
			ans += v[i - 1] * v[i];
			// ���� ���� -1001�� ���� �ٲپ� ǥ���Ѵ�.
			v[i - 1] = -1001;
			v[i] = -1001;
		}

		// ������ ���� ������ ���� ��� ���信 ���Ѵ�.
		if (i == n - 1 && v[i] != -1001)
			ans += v[i];
	}

	// ����� �κ��� �����Ѵ�. ū ������ ���´�.
	for (int i = n - 1;i >= pos;i--) {
		// i�� 0�� ��� �ε��� ���� �߻�, ���� ó���Ѵ�.
		if (i == 0) {
			if (v[i + 1] == -1001 && v[i] != -1001)
				ans += v[i];
			else if (v[i] != -1001 && v[i + 1] != -1001)
				ans += v[i] * v[i + 1];
			break;
		}
		// (1, n), (����, ���), (0, ���), �̹� ���� ���� ���� �ʴ´�.
		bool cond1 = v[i - 1] == 1 && v[i] > 0;
		bool cond2 = v[i] > 0 && v[i - 1] <= 0;
		bool cond3 = v[i] == -1001 || v[i - 1] == -1001;
		if (!cond1 && !cond2 && !cond3) {
			ans += v[i - 1] * v[i];
			// ���� ���� -1001�� ���� �ٲپ� ǥ���Ѵ�.
			v[i - 1] = -1001;
			v[i] = -1001;
		}
		else {
			// (1, n)�� ��� ���� �� ��° ���� ���Ѵ�.
			if (cond1) {
				ans += v[i];
				v[i] = -1001;
			}
		}

		// ������ ���� ����� ���� ��� ���信 ���Ѵ�.
		if (i == pos && v[i] != -1001)
			ans += v[i];
	}

	// ������ ���� ���� �Ǵ� 0�� ���� ��� ���信 ���Ѵ�.
	if (pos - 1 >= 0 && v[pos - 1] != -1001)
		ans += v[pos - 1];

	cout << ans;
}