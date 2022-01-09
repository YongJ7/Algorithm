#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	unordered_map<string, int> arr;
	int N, M, cnt = 0;
	cin >> N >> M;
	//scanf("%d,%d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr[s] = 0;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (arr.find(s) != arr.end()) cnt++;
	}
	cout << cnt;
	//printf("%d", cnt);
}