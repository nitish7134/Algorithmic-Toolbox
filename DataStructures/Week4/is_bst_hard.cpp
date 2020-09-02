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
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;

struct Node
{
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node> &tree, long long min, long long max, const int index)
{
  if (index == -1)
    return true;
  if (index && tree[index].key >= max || tree[index].key < min)
  {
    return false;
  }
  return IsBinarySearchTree(tree, min, tree[index].key, tree[index].left) && IsBinarySearchTree(tree, tree[index].key, max, tree[index].right);
}

int main()
{
  IOS;
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i)
  {
    long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (!nodes || IsBinarySearchTree(tree, -2147483649, 2147483649, 0))
  {
    cout << "CORRECT" << endl;
  }
  else
  {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
