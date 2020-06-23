#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL)
#define ll long long
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define foi(i, initial, n) for (ll i = initial; i < n; i++)
#define fori(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;

vi minCoin(1000, -1);

int nosCoin(int n)
{
    if (n <= 0)
        return 0;
    if (minCoin[n] == -1)
    {
        minCoin[n] = 1 + (min(nosCoin(n - 1), min(nosCoin(n - 3), nosCoin(n - 4))));
    }
    return minCoin[n];
}

int main()
{
    IOS;
    minCoin[0] = 0;
    minCoin[1] = 1;
    minCoin[2] = 2;
    minCoin[3] = 1;
    minCoin[4] = 1;
    int n;
    cin >> n;
    cout << nosCoin(n);
    return 0;
}