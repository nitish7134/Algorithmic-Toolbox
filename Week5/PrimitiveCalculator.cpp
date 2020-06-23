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
#define INT_MAX_ 1000000

using namespace std;

vi minAns(1000000, INT_MAX_);
vi ansList;
int calMin(int n)
{
    if (n <= 0)
        return 0;
    if (minAns[n] == INT_MAX_)
    {
        if (!(n % 3))
            minAns[n] = calMin(n / 3);
        if (!(n % 2))
            minAns[n] = min(calMin(n / 2), minAns[n]);
        minAns[n] = 1 + min(minAns[n], calMin(n - 1));
    }
    return minAns[n];
}

void findSol(int n)
{
    while (n != 1)
    {
        ansList.push_back(n);
        int ctr[3] = {INT_MAX_, INT_MAX_, INT_MAX_};

        if (n % 3 == 0)
        {
            ctr[2] = calMin(n / 3);
        }
        if (n % 2 == 0)
        {
            ctr[1] = calMin(n/2);
        }

            ctr[0]=calMin(n-1);

        int temp = min_element(ctr, ctr + 3) - ctr;
        switch (temp)
        {
        case 0:
            n -= 1;
            break;
        case 1:
            n /= 2;
            break;
        case 2:
            n /= 3;
            break;
        }
    }
}

int main()
{
    minAns[1] = 0;
    minAns[2] = 1;
    minAns[3] = 1;
    minAns[4] = 2;
    IOS;
    int n;
    cin >> n;
    cout << calMin(n) << endl;
    findSol(n);
    if (minAns[n]){
        cout << 1 << " ";
    }
    reverse(ansList.begin(),ansList.end());
    printvec(ansList);

    return 0;
}