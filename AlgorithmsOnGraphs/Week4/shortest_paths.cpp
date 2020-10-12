#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;
void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &dist, vector<int> &reachable, vector<bool> &shortest)
{
  queue<int> q;
  vector<int> prev(adj.size());
  dist[s] = 0;
  reachable[s]=true;
  for (int i = 0; i < adj.size(); i++)
  {
    for (int u = 0; u < adj.size(); u++)
    {
      if(dist[u]!=numeric_limits<long long>::max())
      for (int k = 0; k < adj[u].size(); k++)
      {
        int v = adj[u][k];
        if (dist[v] > dist[u] + cost[u][k])
        {
          dist[v] = dist[u] + cost[u][k];
          reachable[v]=true;
          if (i == adj.size() - 1)
          {
            q.push(v);
          }
        }
      }
    }
  }

  vector<bool> visited(adj.size());
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    shortest[u] = false;
    for (auto v : adj[u])
    {
      if (!visited[v])
      {
        q.push(v);
        visited[v] = true   ;
        shortest[v] = false;
      }
    }
  }
}

int main()
{
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<bool> shortest(n, true);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++)
  {
    if (!reachable[i])
    {
      std::cout << "*\n";
    }
    else if (!shortest[i])
    {
      std::cout << "-\n";
    }
    else
    {
      std::cout << distance[i] << "\n";
    }
  }
}
