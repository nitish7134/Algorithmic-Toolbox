#include <bits/stdc++.h>
#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);                   \
  cerr.tie(NULL)
#define ll long long
#define test \
  int t;     \
  cin >> t;  \
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
#define printvec(a) fo(i, a.size()) cerr << a[i] << " "

using namespace std;

vi d;
vector<char> op;
int eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

int m[15][15];
int M[15][15];

ii MinMax(int i, int j)
{
  int _max = INT_MIN;
  int _min = INT_MAX;
  foi(k, i, j)
  {
    int a = eval(M[i][k], M[k + 1][j], op[k]);
    int b = eval(M[i][k], m[k + 1][j], op[k]);
    int c = eval(m[i][k], M[k + 1][j], op[k]);
    int d = eval(m[i][k], m[k + 1][j], op[k]);
    _min = min(_min, min(a, min(b, min(c, d))));
    _max = max(_max, max(a, max(b, max(c, d))));
  }
  return {_min, _max};
}
int MaxVal()
{

  fori(i, d.size())
  {
    m[i][i] = d[i];
    M[i][i] = d[i];
  }

  fori(s, d.size() - 1)
  {
    fori(i, d.size() - s)
    {
      int j = i + s;
      ii temp = MinMax(i, i + s);
      m[i][j] = temp.first;
      M[i][j] = temp.second;
    }
  }
  return M[1][d.size()];
}
int main()
{
  IOS;
  string s;
  cin >> s;

  fo(i, s.size())
  {
    if (s[i] >= '0' && s[i] <= '9')
      d.push_back(s[i] - 48);
    else
    {
      op.push_back(s[i]);
    }
  }

  cout << MaxVal();

  cout << endl;
  for (int i = 0; i < d.size(); i++)
  {
    for (int j = 0; j < d.size(); j++)
    {
      cout << m[i][j] << " " << M[i][j]<<"\t";
    }
    cout << endl;
  }
  return 0;
}