#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int N, M, cnt, ans;                                                    // 주차 공간 수, 차량 수, 주차장에 들어간 차량 수, 총 금액
int car[2001];                                                         // 차량 무게
queue<int> wait;                                                       // 기다리는 차량 번호
pair<int, int> parking[2001];                                          // 각 차량의 주차장 자리/금액
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> price; // 주차장 자리/단위 무게당 요금

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) // 주차장 순번에 맞게 단위 무게당 요금 입력
    {
        int p;
        cin >> p;
        price.push({i, p});
    }

    for (int i = 1; i <= M; i++) // 차량의 무게 입력
    {
        cin >> car[i];
    }

    for (int i = 0; i < 2 * M; i++)
    {
        int now_car; // 현재 들어오는 또는 나가는 차량
        cin >> now_car;

        if (now_car > 0) // 차량이 들어오는 경우
        {
            if (cnt == N) //주차장이 만차인 경우 대기자 명단에 넣는다
            {
                wait.push(now_car);
            }
            else
            {
                parking[now_car] = {price.top()};
                price.pop();
                cnt++;
            }
        }

        else // 차량이 나가는 경우
        {
            ans += (car[-now_car] * parking[-now_car].second); // 차량이 나올 때 금액을 정산 한다
            price.push({parking[-now_car]});
            cnt--;

            if (!wait.empty()) // 기다리는 차량이 있으면 주차한다.
            {
                parking[wait.front()] = {price.top()};
                wait.pop();
                price.pop();
                cnt++;
            }
        }
    }

    cout << ans;
}
