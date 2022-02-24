#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int N,M; cin>>N>>M;
    int ans = 1000000;
    vector<pair<int,int>> CH; // 치킨집 주소 저장
    vector<pair<int,int>> home; // 집 주소 저장

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int a; cin>>a;
            if(a==1) home.push_back({i,j});
            else if(a==2) CH.push_back({i,j});
        }
    }

    // M개의 치킨집만 선택하기 위한 비트배열
    vector<int> bit(CH.size()); 
    fill(bit.begin(),bit.end(),0);
    for(int i=0;i<M;i++) bit[i]=1;

    // N개 중 M개만 선택 
    do{
        int min_sum = 0;
        // 모든 집을 확인하며 M개 선택된 치킨집 중 가장 가까운 거리 더하기
        for(int i=0;i<home.size();i++){
            int min_now = 1001;
            for(int j=0;j<CH.size();j++){
                if(bit[j]==1){
                    min_now = min(min_now,abs(home[i].first-CH[j].first)+abs(home[i].second-CH[j].second));
                }
            }
            min_sum+=min_now;
        }
        ans = min(ans,min_sum);
    }while(prev_permutation(bit.begin(),bit.end()));
    
    cout<<ans<<'\n';
}