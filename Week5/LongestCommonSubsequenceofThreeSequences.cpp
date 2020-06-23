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
#define fon(i, n) for (ll i = 0; i <= n; i++)
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
int LCS[101][101][101];
int main()
{
    IOS;
    int n;
    vi a, b, c;
    cin >> n;
    a.resize(n);
    inp(a, n);
    cin >> n;
    b.resize(n);
    inp(b, n);
    cin >> n;
    c.resize(n);
    inp(c, n);

    fon(i, a.size())
    {
        fon(j, b.size())
        {
            fon(k, c.size())
            {
                if (i == 0 || j == 0 || k==0)
                    LCS[i][j][k] = 0;
                else if (a[i - 1] == b[j - 1] && c[k-1] == a[i-1])
                {
                    LCS[i][j][k] = LCS[i - 1][j - 1][k-1] + 1;
                }
                else
                    LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]),LCS[i][j][k-1]);
            }
        }
    }
    cout<<LCS[a.size()][b.size()][c.size()]<<endl;
    return 0;
}