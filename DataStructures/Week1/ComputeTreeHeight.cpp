#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define ll long long
#define test int t; cin>>t; while(t--)
#define fo(i,n) for(ll i=0;i<n;i++)
#define foi(i,initial,n) for(ll i=initial;i<n;i++)
#define fori(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a,n) fo(i,n)cin>>a[i]
#define printvec(a) fo(i,a.size())cout<<a[i]<<" "

using namespace std;

struct node {
    vector<node> children;
};

int main() {
    IOS;
    int n;
    cin>>n;
    vvi nodes(n);
    int root = -1;
    int temp;
    fo(i, n) {
        cin>>temp;
        if (temp==-1)
            root = i;
        else {
            nodes[temp].push_back(i);
        }
    }
    queue<int> q;
    q.push(root);
    int height = 0;
    while (true) {
        int nodeCount = q.size();
        if (!nodeCount) {
            cout<<height<<endl;
            return 0;
        }
        height+=1;
        while (nodeCount>0) {
            int frontV = q.front();
            q.pop();
            if (!nodes[frontV].empty()) {
                fo(i, nodes[frontV].size())
                    q.push(nodes[frontV][i]);
            }
            nodeCount--;
        }
    }

    return 0;
}