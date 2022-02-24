#include <bits/stdc++.h>
using namespace std;
int n, k, r;
vector<int> arr;
int main()
{
	cin >> n >> k;
    // 처음 사람들이 앉아있는 순서를 배열에 담는다.
	for (int i = 1; i <= n; i++) {
        arr.push_back(i);
	}

    int idx = 0;
    cout<<"<";
    while(1)
    {
        idx = (idx + k - 1) % arr.size();  // 각 실행마다 제거할 인덱스 확인 갱신
        cout<<arr[idx];  // 제거 
        arr.erase(arr.begin()+idx); // 배열에서 삭제
        if(arr.empty()){  
            cout<<">";
            break;
        }
        else cout<<", ";

    }

}