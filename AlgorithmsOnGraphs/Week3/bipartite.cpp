#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bipartite(vector<vector<int>> &adj)
{

  queue<int> q;
  vector<int> color(adj.size(), -1);
  q.push(0);
  color[0] = 1;
  while (q.empty() == false)
  {
    int u = q.front();
    q.pop();
    for (auto v : adj[u])
    {
      if (color[v] == -1)
      {
        q.push(v);
        color[v] = 1 - color[u];
      }
      else if (color[v] == color[u])
        return 0;
    }
  }
  return 1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
