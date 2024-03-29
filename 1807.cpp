#include <iostream>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

// �� k�� ���̸� ����
ll len(ll k) {
	return (ll)log10(k) + 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1) {
		ll n;
		cin >> n;
		if (n == 0)
			break;

		ll l = 1;
		ll r = 1e15;

		n--; // �ε��� ����
		while (1) {
			ll m = (l + r) >> 1;

			// A[N]���� N�� 4�� ����� A[N]�� ���̴� N�� ���̿� �����ϴ�.
			// N�� 4�� ����� �ƴϸ� A[N]�� ���̴� N�� ���� + 1�̴�.
			ll N = 1; // m�� �����ϴ� ��(A[N])�� N�� ��
			ll s = 0; // m�� �����ϴ� ���� ù ��° ������ �ε���
			while (s + len(N) < m) {
				cout << s << "�� �����ε����� N: " << N << "\n";
				if (N % 4 == 0) {
					s += len(N);
				}
				else {
					s += len(N) + 1;
				}
				N++;
			}
			ll e = N % 4 == 0 ? s + len(N) : s + len(N) - 1; // m�� �����ϴ� ���� ������ ������ �ε���

			if (s <= n && n <= e) {
				if (N % 4 != 0 && n == e) {
					// N�� ���� �ڸ��� * 10 + x�� 4�� ����� �Ǵ� x ã��
					int num = N % (int)pow(10, len(N));
					for (int i = 0;i < 10;i++) {
						if ((num + i) % 4 == 0) {
							cout << i << "\n";
						}
					}
				}
				else {
					cout << to_string(N)[n - s] << "\n";
				}
			}
			else if (n < s) {
				r = m - 1;
			}
			else if (e < n) {
				l = m + 1;
			}
		}
	}
}