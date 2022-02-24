#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> arr;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int ans = 1;
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		string cloth, kind;
		for (int i = 0; i < n; i++) {
			cin >> cloth >> kind;
			arr[kind]++;
		}
		for (auto it = arr.begin(); it != arr.end(); it++) {
			ans = ans * (it->second + 1);
		}
		cout << ans-1 << '\n';
		arr.clear();
		ans = 1;
	}
}