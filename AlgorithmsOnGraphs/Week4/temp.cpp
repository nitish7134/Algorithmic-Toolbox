#include <bits/stdc++.h>
#define ll long long
#define MAX 1000003
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define input(a)                       \
    for (int i = 0; i < a.size(); i++) \
        cin >> a[i];
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vii vector<pair<int, int>>
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

void solve()
{
    ll n, d, m;

    cin >> n >> m >> d;
    vi a(m);

    input(a);
    sort(all(a));

    bool flag = true;

    for (int i = 1; i < m; i++)
    {
        // if(i==0) continue;
        if (a[i] - a[i - 1] > d)
        {
            flag = false;
            break;
        }
    }

    a.push_back(n + 1   );

    if (!flag)
    {
        cout << "-1";
        return;
    }   

    int curr_pos = 0;
    int counter = 0;
    while (curr_pos < n + 1)
    {
        int temp = curr_pos;
        curr_pos = lower_bound(a.begin(), a.end(), max(curr_pos + d,n+1)) - a.begin();
        if(curr_pos == temp)
            {flag=false;break;}
        counter++;
    }
    if (!flag)
    {
        cout << "-1";
        return;
    }
    cout << counter;
}

int main()
{
    IOS;
    solve();

    return 0;
}