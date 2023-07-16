#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> current; // ���� ��û�� ����
	vector<int> change; // ��ȯ�� ���� ��û�ϰ� ���� ����

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		current.push_back(k);
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		change.push_back(k);
	}

	// change�� �ִ� ������ current�� ������ ���ϴ� ������ ���� �� ����.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (change[i] == current[j]) {
				cnt++;
				current[j] = -1;
				break;
			}
		}
	}

	cout << n - cnt;
}