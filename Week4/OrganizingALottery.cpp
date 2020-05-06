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
#define inp(a, n) fo(i, n) cin >> a[i]
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;

int pointcnt[5000] = {0};

struct seg
{
    int a;
    int b;
};
bool compareA(const seg &a, const seg &b)
{
    return a.a < b.a;
}
vector<int> Fast_count_segments(vector<seg> segs, vector<int> points)
{
    vector<int> cnt(points.size(), 0);
    int maxL = segs.size() - 1;
    fo(i, points.size())
    {
        fo(j, segs.size())
        {

            cnt[i] += (points[i] >= segs[j].a && points[i] <= segs[j].b);

            if (points[i] < segs[j].a)
                break;
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<seg> segs(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> segs[i].a >> segs[i].b;
    }
    sort(segs.begin(), segs.end(), compareA);
    vector<int> points(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> points[i];
    }
    vector<int> cnt = Fast_count_segments(segs, points);
    for (size_t i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << ' ';
    }
}