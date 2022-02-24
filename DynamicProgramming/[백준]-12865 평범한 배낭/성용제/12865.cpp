#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> arr(101); 
int dp[101][100001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    // 입력
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};  // 무게, 가치
    }

    // 모든 물건을 넣어보며 넣을 수 있는 최대값을 찾아준다.
    for (int i = 1; i <= N; i++)
    {
        int p = arr[i].second;
        int w = arr[i].first;

        for (int j = 1; j <= K; j++)
        {
            if (j - w >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + p);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
}
