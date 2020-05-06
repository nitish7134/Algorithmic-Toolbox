#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
/*
pair<int, int> getMin(map<int, int> mymap) 
{
  pair<int, int> min = *min_element(mymap.begin(), mymap.end(),
            [](const auto& l, const auto& r) { return l.second < r.second; });
  return min; 
}

int main()
{
    int n;
    cin >> n;
    V<int> ans;
    map<int, int> a;
    bool isDone[n] = {false};

    loop(i, 0, n)
    {
        int temp,temp1;
        cin >> temp >> temp1;
        a.insert({temp, temp1});
    }

    pair<int, int> goAt = getMin(a);
    ans.push_back(goAt.second);
    cerr << goAt.second;

    while (a.size() > 0)
    {
        auto temp = a.begin();
        if (temp->second >= goAt.second && temp->first<=goAt.second)
        {
            a.erase(a.begin());
        }

        else
        {
            goAt = getMin(a);
            cerr << goAt.second;
            ans.push_back(goAt.second);
        }
    }
    cout << ans.size() << endl;
    loop(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    return 0;
}*/

struct Segment
{
    int start, end;
};

bool myfunction(Segment i, Segment j) { return (i.end < j.end); }

vector<int> optimal_points(vector<Segment> &segments)
{
    vector<int> points;
    sort(segments.begin(), segments.end(), myfunction);
    int current = segments[0].end;
    points.push_back(current);
    for (int i = 0; i < segments.size(); i++)
    {
        if (current < segments[i].start || current > segments[i].end)
        {
            current = segments[i].end;
            points.push_back(current);
        }
    }
    return points;
}

int main()
{
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i)
    {
        cout << points[i] << " ";
    }
}