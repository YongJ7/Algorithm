#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

struct ball{
    int idx,color,weight;
};

bool comp(ball a,ball b)
{
    if(a.weight == b.weight) return a.color < b.color;
    return a.weight < b.weight;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    int N; cin>>N;
    vector<ball> arr; // 입력 (인덱스,색,크기)
    int sum = 0; // 총 합
    int colsum[200001]; // 색깔 별 합
    int ans[200001]; // 정답

    FOR(i,N)
    {
        int c,w; cin>>c>>w;
        arr.push_back({i,c,w});
    }

    sort(arr.begin(),arr.end(),comp);

    for(int i=0,j=0;i<N;i++)
    {
        // i 번째 공에 대해 i의 크기보다 작은 공들을 모두 더함
        for(;arr[i].weight>arr[j].weight; j++){
            sum += arr[j].weight; // 전체 합
            colsum[arr[j].color]+=arr[j].weight; // 색깔별 합
        }
        ans[arr[i].idx] = sum - colsum[arr[i].color]; // 전체에서 같은 색의 공들의 합을 빼준다
    }
    
    FOR(i,N)
    {
        cout<<ans[i]<<'\n';
    }
}