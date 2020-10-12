#include <iostream>
#include <vector>

using std::pair;
using std::vector;

vector<bool> vis(1001,false);
bool reach(vector<vector<int>> &adj, int x, int y)
{
  vis[x] = true;
  if (x == y)
    return true;
  for (auto v : adj[x])
  {
    if (vis[v] == false)
      if (reach(adj, v, y))
        return true;
  }
  return false;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) ? 1 : 0;
}
