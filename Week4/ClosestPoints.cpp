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
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a) fo(i, a.size()) cout << a[i] << " "
#define BruteForceMax 3
using namespace std;

struct cod
{
    float x, y;
};
bool CompareX(cod a, cod b) { return a.x < b.x; }
bool CompareY(cod a, cod b) { return a.y < b.y; }

float Dist(cod p1, cod p2) { return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); }
float bruteForce(cod P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (Dist(P[i], P[j]) < min)
                min = Dist(P[i], P[j]);
    return min;
}

float minDist(cod coord[], int l, int r)
{
    if (r-l <= BruteForceMax)
        return bruteForce(coord, r-l);
    int mid = l + r;
    mid /= 2;
    float minD = min(minDist(coord, mid + 1, r), minDist(coord, l, mid));

    vector<cod> nearby;
    for (int i = l; i< r ; i++)
    {
        if(i == mid)
            continue;
        if(abs(coord[i].x - coord[mid].x) < minD){
            float temp = Dist(coord[i],coord[mid]);
            nearby.push_back(coord[i]);
            if(temp<minD)
                minD = temp;
        }
    }
    sort(nearby.begin(),nearby.end(),CompareY);
    fo(i,nearby.size()){
        if(i==mid)
            continue;
        foi(j,i+1,nearby.size()){
            if(j==mid)
                continue;
            if(abs(nearby[i].y-nearby[j].y)<minD){
                float temp = Dist(coord[i],coord[j]);
                if(temp<minD)
                minD = temp;
            }
        }
    }

    return minD;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    cod coord[n];
    fo(i, n)
            cin >>
        coord[i].x >> coord[i].y;
    sort(coord, coord + n, CompareX);
    cout << fixed;
    cout << setprecision(6) << minDist(coord, 0, n) << endl;
    return 0;
}