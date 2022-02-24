#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    
    int N; cin>>N;
    int ans = 0;
    vector<int> arr(N);

    // 배열에 입력 후 정렬
    FOR(i,N){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    
    // N의 최대값이 8이기 때문에 모든 경우의 수를 나열해도 8!으로 4만정도 모든 경우를 다 확인하여 최대값 찾기
    do{
        int sum = 0;
        FOR(i,N-1){
            sum+=abs(arr[i]-arr[i+1]);
        }
        ans = ans < sum ? sum : ans;
    }while(next_permutation(arr.begin(),arr.end()));

    cout<<ans<<'\n';
}