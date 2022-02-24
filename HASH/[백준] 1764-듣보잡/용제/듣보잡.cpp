#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
unordered_map<string, int> p;
vector<string> v;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        string s;
        cin >> s;
        p[s]++;
        if (p[s] > 1)
        {
            v.push_back(s);
            cnt++;
        }
    }
    sort(v.begin(),v.end());
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << v[i] << '\n';
}