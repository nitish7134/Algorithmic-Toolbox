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
vi v(30);
bool s3[201][201][31];
int sum;
bool canDivideInThree(int n)
{
    sum /= 3;
    s3[0][0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            for (int k = 0; k <= sum; k++)
            {
                s3[i + 1][j][k] = s3[i][j][k];
                if (j >= v[i])
                {
                    s3[i + 1][j][k] = s3[i + 1][j][k] | s3[i][j - v[i]][k];
                }
                if (k >= v[i])
                {
                    s3[i + 1][j][k] = s3[i + 1][j][k] | s3[i][j][k - v[i]];
                }
            }
        }
    }
    return s3[n][sum][sum] ? 1 : 0;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    v.resize(n);
    inp(v, n);  
    sort(v.begin(),v.end());
    sum = accumulate(v.begin(), v.begin()+n+1, 0);
    if ((sum % 3) != 0 || n < 3)
    {
        cout << 0;
        return 0;
    }
    cout << canDivideInThree(n);
    return 0;
}