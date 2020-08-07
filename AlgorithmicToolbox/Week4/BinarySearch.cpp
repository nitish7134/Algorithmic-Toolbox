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

int BinarySearch(int a[], int v, int l, int r)
{
    if (l == r)
        return -1;
    int mid = l + r;
    mid /= 2;
    if (a[mid] == v)
        return mid;
    if (a[mid] < v)
        l = mid + 1;
    else
    {
        r = mid;
    }
    return BinarySearch(a, v, l, r);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    int a[n];
    fo(i, n)
            cin >>
        a[i];
    int k;
    cin >> k;
    fo(i, k)
    {
        int l;
        cin >> l;
        cout << BinarySearch(a, l, 0, n) << " ";
    }
    return 0;
}