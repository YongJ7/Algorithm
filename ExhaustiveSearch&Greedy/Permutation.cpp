#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    vector<int> v{1,2,3,4};
    //string v = "1234";

    // 전체 출력
    do{
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<'\n';
    }while(next_permutation(v.begin(),v.end()));

    vector<int> bit{1,1,0,0};

    // 특정 개수 출력
    do{
        for(int i=0;i<v.size();i++){
            if(bit[i]==1) cout<<v[i]<<" ";
        }
        cout<<'\n';
    }while(prev_permutation(bit.begin(),bit.end()));
}