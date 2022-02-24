#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;
vector<pair<int, int>> second_line(1000001);

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    // 먼저 전체 역을 순서대로 입력 받는다.
    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;
        arr.push_back(now);
    }

    // 각 역에 대하여 <전 역, 다음 역> 순으로 배열에 넣어준다.
    if (N == 1)
        second_line[arr[0]] = {0, 0};
    else
    {
        second_line[arr[0]] = {arr[N - 1], arr[1]};
        for (int i = 1; i < N - 1; i++)
        {
            second_line[arr[i]] = {arr[i - 1], arr[i + 1]};
        }
        second_line[arr[N - 1]] = {arr[N - 2], arr[0]};
    }

    // 각 쿼리 마다 명령 실행
    string INST;
    for (int t = 0; t < M; t++)
    {
        cin >> INST;
        // 다음 역 출력 후 그 사이에 역 삽입
        if (INST == "BN")
        {
            int i, j, next;
            cin >> i >> j;
            next = second_line[i].second; // 다음 역
            cout << next << '\n';

            second_line[j] = {i, next};  // 새로운 역 생성 앞 뒤 연결
            second_line[i].second = j;   // 현재 역의 다음 역을 새로운 역으로 변경
            second_line[next].first = j; // 다음 역의 전 역을 새로운 역으로 변경
        }
        // 전 역 출력 후 그 사이에 역 삽입
        else if (INST == "BP")
        {
            int i, j, before;
            cin >> i >> j;
            before = second_line[i].first; // 전 역
            cout << before << '\n';

            second_line[j] = {before, i};   // 새로운 역 생성 앞 뒤 연결
            second_line[i].first = j;       // 현재 역의 전 역을 새로운 역으로 변경
            second_line[before].second = j; // 전 역의 다음 역을 새로운 역으로 변경
        }
        // 다음 역 출력 후 폐쇠
        else if (INST == "CN")
        {
            int i;
            cin >> i;
            auto next = second_line[second_line[i].second]; // 다음 역
            cout << second_line[i].second << '\n';

            second_line[next.first].second = next.second; // 현재 역의 다음 역을 다다음 역으로 변경
            second_line[next.second].first = next.first;  // 다다음 역의 전 역을 현재 역으로 변경
        }
        // 전 역 출력 후 폐쇠
        else if (INST == "CP")
        {
            int i;
            cin >> i;
            auto before = second_line[second_line[i].first]; // 전 역
            cout << second_line[i].first << '\n';

            second_line[before.first].second = before.second; // 전전 역의 다음 역을 현재 역으로 변경
            second_line[before.second].first = before.first;  // 현재 역의 전 역을 전전 역으로 변경
        }
    }
}