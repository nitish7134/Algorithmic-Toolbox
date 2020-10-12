#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> open;
  open.push({0, s});
  vector<long long> dist(adj.size(), numeric_limits<long long>::max());
  dist[s] = 0;
  while (!open.empty())
  {
    int u = open.top().second;
    open.pop();
    int i = 0;
    for (auto v : adj[u])
    {
      if (dist[v] > dist[u] + cost[u][i])
      {
        dist[v] = dist[u] + cost[u][i];
        open.push({dist[v], v});
      }
      i++;
    }
  }
  if (dist[t] != numeric_limits<long long>::max())
    return dist[t];
  else
    return -1;
}

int main()
{
  int n, m;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
