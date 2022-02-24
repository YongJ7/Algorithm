#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q1; // 내림차순 
priority_queue<int> q2;  // 오름차순

int mid; // 가운데 값
int cnt1, cnt2; // 가운데 값보다 큰값,작은값
int N;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	int a; cin >> a;
	mid = a;
	cout << mid << '\n';

	for (int i = 1;i < N;i++) {
        cin >> a;
		// 현재 들어온 값을 확인
		if (a > mid) {
			q1.push(a);
			cnt1++;
		}
		if (a <= mid) {
			q2.push(a);
			cnt2++;
		}

		// mid 값의 변경 과정
		if ((cnt1 > cnt2) && ((cnt1 - cnt2) != 1)) {
			q2.push(mid);
			mid = q1.top();
			q1.pop();
			cnt2++;
			cnt1--;
		}
		if (cnt2 > cnt1) {
			q1.push(mid);
			mid = q2.top();
			q2.pop();
			cnt1++;
			cnt2--;
		}
		cout << mid << '\n';
	}
	return 0;
}