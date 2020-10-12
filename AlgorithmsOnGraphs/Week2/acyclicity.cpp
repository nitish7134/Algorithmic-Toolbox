#include <iostream>
#include <vector>

using std::pair;
using std::vector;

int dfs(vector<vector<int>> &adj, int x, vector<bool> &visited, vector<bool> &recStack)
{
  visited[x] = true;
  recStack[x] = true;
  for (auto v : adj[x])
  {
    if (!visited[v] && dfs(adj, v, visited, recStack))
      return 1;
    else if (recStack[v])
      return 1;
  }
  recStack[x] = false;
  return 0;
}

int acyclic(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size(), false);
  vector<bool> recStack(adj.size(), false);
  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      if (dfs(adj, i, visited, recStack))
        return 1;
    }
  }
  return 0;
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
  }
  std::cout << acyclic(adj);
}
