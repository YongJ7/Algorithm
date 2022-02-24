#include <iostream>
#include <algorithm>

using namespace std;
 
int n,arr[301];
int dp[301];
int main() 
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 처음 dp에 1,2,3층을 갈 수 있는 시작값을 넣어주고
    dp[0] = arr[0];
    dp[1] = max(arr[0]+arr[1],arr[1]);
    dp[2] = max(arr[0]+arr[2],arr[1]+arr[2]);
 
    // 3층부터 n층까지 각각의 최대값을 구해준다.
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-2]+arr[i], arr[i-1]+arr[i]+dp[i-3]);
    }
 
    cout << dp[n - 1] << '\n';
}