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
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;

class TreeOrders
{
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;

public:
  void read()
  {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++)
    {
      cin >> key[i] >> left[i] >> right[i];
    }
  }
  void in_order(int index)
  {
    if (left[index] != -1)
    {
      in_order(left[index]);
    }
    cout<<key[index]<< " ";

    if (right[index] != -1)
    {
      in_order(right[index]);
    }
  } 
  void in_order()
  {
    in_order(0);
    cout<<endl;
  }

  void pre_order(int index)
  {
    cout<<key[index]<<" ";
    if (left[index] != -1)
    {
      pre_order(left[index]);
    }
    if (right[index] != -1)
    {
      pre_order(right[index]);
    }
  }
  void pre_order()
  {
    pre_order(0);
    cout<<endl;
  }
  void post_order(int index)
  {
    if (left[index] != -1)
    {
      post_order(left[index]);
    }
    if (right[index] != -1)
    {
      post_order(right[index]);
    }
    cout<<key[index]<<" ";  
  }
  void post_order()
  {
    post_order(0);
    cout<<endl;
  }
};

int main_with_large_stack_space()
{
  IOS;
  TreeOrders t;
  t.read();
  t.in_order();
  t.pre_order();
  t.post_order();
  return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }
#endif

  return main_with_large_stack_space();
}
