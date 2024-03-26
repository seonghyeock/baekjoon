#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, l; // ġŲ�� ��, �ü��� ����
	cin >> n >> l;

	vector<double> d; // ġŲ�� �Ÿ�
	vector<double> w; // ġŲ�� ����
	for (double i = 0; i < n; i++) {
		double x;
		cin >> x;
		d.push_back(x);
	}
	for (double i = 0; i < n; i++) {
		double x;
		cin >> x;
		w.push_back(x);
	}

	double mid = l / 2;
	double left = 0;
	double right = 0;

	for (int i = 0; i < n; i++) {
		if (mid > d[i]) {
			left += (mid - d[i]) * w[i];
		}
		else if (mid < d[i]) {
			right += (d[i] - mid) * w[i];
		}
	}

	while (left != right) {
		if (left < right) {
		}
		else {
		}

		for (int i = 0; i < n; i++) {
			if (mid > d[i]) {
				left += (mid - d[i]) * w[i];
			}
			else if (mid < d[i]) {
				right += (d[i] - mid) * w[i];
			}
		}
	}

	cout << mid;
}