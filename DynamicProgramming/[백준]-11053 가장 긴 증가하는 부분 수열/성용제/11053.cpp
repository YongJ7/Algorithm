#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001
int arr[MAX], dp[MAX]; // 원래 배열 / 각 인덱스 마다 증가하는 개수 
int N, ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    // 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    // 각 인덱스 마다 확인 전 인덱스를 모두 확인하여 자기 보다 작은 숫자 확인
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans;
}
