#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define ll long long
#define test int t; cin>>t; while(t--)
#define fo(i,n) for(ll i=0;i<n;i++)
#define foi(i,initial,n) for(ll i=initial;i<=n;i++)
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
vi bars;
int n;
int value[10001][301];

int main(){
    IOS;
    int W;
    cin>>W>>n;
    bars.resize(n);
    inp(bars,n);
    fo(i,n){
        foi(j,1,W){
            value[j][i] = value[j][i-1];
            if(j>=bars[i])
                value[j][i] = max(value[j][i],value[j-bars[i]][i-1]+bars[i]);            
        }
    }
    cout<<value[W][n-1];
    return 0;
}