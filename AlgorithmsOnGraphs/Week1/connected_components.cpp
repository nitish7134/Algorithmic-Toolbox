#include <iostream>
#include <vector>

using std::pair;
using std::vector;

vector<bool> vis(10001, false);
int number_of_components(vector<vector<int>> &adj, int i)
{
  vis[i] = true;
  for (auto v : adj[i])
    if (vis[v] == false)
      number_of_components(adj, v);
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vis.resize(n);
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int ctr = 0;
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == false)
    {
      number_of_components(adj, i);
      ctr++;
    }
  }
  std::cout << ctr;
}
