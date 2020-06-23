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

int ED[101][101];
int edit_distance(string a, string b)
{
    fo(l, a.length()+1)
    {
        ED[l][0] = l;
    }
    fo(l, b.length()+1)
    {
        ED[0][l] = l;
    }
    fori(i, a.length())
    {
        fori(j,b.length())
        {
            int diff = (a[i - 1] == b[j - 1]) ? 0 : 1;
            ED[i][j] = min(ED[i][j - 1] + 1, min(ED[i - 1][j] + 1, ED[i - 1][j - 1] + diff));
        }
    }

    return ED[a.length()][b.length()];
}

int main()
{
    IOS;
    string a, b;
    cin >> a;
    cin >> b;
    fo(i, a.length()+1)
        fo(j, b.length()+1)
            ED[i][j] = INT_MAX;
    cout << edit_distance(a, b) << endl;
    // fo(i, a.length()+1)
    // {
    //     fo(j, b.length()+1)
    //             cout
    //         << ED[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}