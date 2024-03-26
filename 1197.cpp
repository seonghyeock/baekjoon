#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> vec;
int v, e;
int parents[10001];

int Find(int x) {
	if (parents[x] == x)
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	parents[px] = py;	
}

int main() {
	// ũ�罺Į �˰��� ���
	cin >> v >> e;

	for (int i = 0;i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, { a,b } });
	}

	for (int i = 1;i <= v;i++) {
		parents[i] = i;
	}

	// ����ġ�� �������� ����
	sort(vec.begin(), vec.end());

	int ans = 0;
	int cnt = 0;
	for (int i = 0;i < vec.size();i++) {
		int w = vec[i].first;
		int cur = vec[i].second.first;
		int nxt = vec[i].second.second;

		// ����Ŭ�� �����ϴ��� Ȯ��
		if (Find(cur) == Find(nxt))
			continue;

		Union(cur, nxt);
		ans += w;
		cnt++;

		// ���� ��� ���� ������ ����Ǿ��ٸ� break
		if (cnt == vec.size() - 1)
			break;
	}

	cout << ans;
}