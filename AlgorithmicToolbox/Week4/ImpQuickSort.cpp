#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define lli long long
#define test() int t; cin>>t; while(t--)
#define fo(i,n) for(lli i=0;i<n;i++)
#define foi(i,initial,n) for(lli i=initial;i<n;i++)
#define fori(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define endl "\n"
#define inp(a,n) fo(i,n)cin>>a[i]
#define printarr(a,n) fo(i,n)cout<<a[i]<<" "

using namespace std;


int main(){
    IOS;
    int n;
    cin>>n;
    int a[n];
    inp(a,n);
    sort(a,a+n);
    printarr(a,n);
    return 0;
}