#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> alp(26);
vector<string> v;
int N,K,ans;

int Read()
{
    bool read = false;
    int cnt = 0;
    // 단어들이 들어있는 배열을 확인하며 읽을 수 있으면 cnt++ 없으면 지나간다
    for(int i=0;i<v.size();i++)
    {
        read = true;
        string now = v[i];
        for(int j=0;j<now.size();j++)
        {
            if(alp[now[j]-'a']==false){
                read = false;
                break;
            }
        }
        if(read) cnt++;
    }
    return cnt;
}
// DFS 모든 알파벳을 확인하여 num이 K-5개 일때 읽을 수 있는 단어 수 확인
void run(int idx,int num)
{
    if(num == K){
        int now = Read();
        ans = ans < now ? now : ans;
    }

    for(int i=idx;i<26;i++){
        if(alp[i]==true) continue;
        alp[i] = true;
        run(i,num+1);
        alp[i]=false;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    cin>>N>>K;
    // 시작과 끝 단어 5개를 먼저 저장
    alp['a'-'a'] = true;
    alp['t'-'a'] = true;
    alp['i'-'a'] = true;
    alp['c'-'a'] = true;
    alp['n'-'a'] = true;

    // K가 5보다 작으면 시작/끝 단어를 읽지 못하기 때문에 아무 단어도 읽지 못함 5이상이면 5를 빼준다
    if(K<5){
        cout<<0<<'\n';
        return 0;
    }
    K-=5;

    // 단어들 입력
    for(int i=0;i<N;i++)
    {
        string s; cin>>s;
        v.push_back(s);
    }
    run(0,0);

    cout<<ans<<'\n';
}