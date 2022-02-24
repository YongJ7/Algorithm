#include <bits/stdc++.h>
using namespace std;

int N, M, a, b; // 문제수, 정보수, 먼저/나중 문제
int used[32001]; // 나중에 풀 문제
vector<int> arr[32001]; //먼저 풀 문제->나중에 풀 문제
priority_queue<int, vector<int>, greater<int>> pq; // 먼저 풀 문제 

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        used[b]++;
        arr[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (used[i] == 0) pq.push(i);
    }

    while (!pq.empty())
    {
        // 먼저 풀 문제를 출력
        int now = pq.top();
        pq.pop();

        cout << now << " ";

        // now에 해당하는 나중에 풀 문제들 중 먼저 풀어야할 문제가 남은게 없다면 pq에 넣는다
        for (int i = 0; i < arr[now].size(); i++){
            int newnow = arr[now][i];
            used[newnow]--;

            if (used[newnow] == 0) pq.push(newnow);
        }
    }
    
}