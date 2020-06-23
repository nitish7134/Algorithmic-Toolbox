//Unsolved
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
#define printvec(a)                      \
    fo(i, a.size()) cout << a[i] << " "; \
    cout << endl
using namespace std;

int LCS[101][101];
int main()
{
    IOS;
    int n, m;
    cin >> n;
    vi a, b;
    a.resize(n);
    inp(a, n);
    cin>>m;
    b.resize(m);
    inp(b, m);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    cout << LCS[n][m];

    return 0;
}