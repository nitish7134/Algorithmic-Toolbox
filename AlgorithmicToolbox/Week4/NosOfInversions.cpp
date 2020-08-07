#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
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
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a,l,r) foi(i, l,r) cout << a[i] << " "

using namespace std;
int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m, ctr = 0;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            ctr+= (n1-i);
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return ctr;
}
int MergeSort(int a[], int l, int r)
{
    int ctr = 0;
    if (l < r)
    {
        int m = l + r;
        m /= 2;
        ctr += MergeSort(a, l, m);
        ctr += MergeSort(a, m + 1, r);
        ctr += merge(a, l, m, r);
    }
    return ctr;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    int a[n];
    inp(a, n);
    cout<<MergeSort(a, 0, n - 1);
    return 0;
}