#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N; cin>>N;

    priority_queue<int> pq;

    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<'\n';
            else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
}