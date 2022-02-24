#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>> arr;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> N;
    // 값과 처음 인덱스 값 저장
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end());
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        ans = ans < arr[i].second - i ? arr[i].second - i : ans;
    }
    // 정렬 전 후 인덱스 값의 차이가 최대인 인덱스 확인
    cout << ans + 1 << '\n'; // 버블 소트에서는 첫 인덱스가 1이기 때문에 +1을 해준다
}