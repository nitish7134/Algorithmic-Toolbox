#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL);
#define lli long long
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define fo(i, n) for (lli i = 0; i < n; i++)
#define foi(i, initial, n) for (lli i = initial; i < n; i++)
#define fori(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define endl "\n"
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;

int main()
{
    IOS;
    int n;
    cin >> n;
    int a[n];
    fo(i, n)
            cin >>
        a[i];
    sort(a, a + n);
    int check = a[0];
    int ctr = 1;
    fori(i, n - 1)
    {
        if (check == a[i])
        {
            ctr++;
            if (ctr > n / 2)
            {   
                cout << 1;
                return 0;
            }
        }
        else
        {
            ctr = 1;
            check = a[i];
        }
    }
    cout << 0;
    return 0;
}