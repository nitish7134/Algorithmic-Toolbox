#include<bits/stdc++.h>
#define ll long long
#define MAX 1000003
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define input(a) for(int i=0;i<a.size();i++) cin>>a[i];
#define test int t; cin>>t; while(t--)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int N = (int)1e6+5;
vector<int> res(N);
int pisano_seq(ll m){
	res[0] = 0;
	res[1] = 1;
	for(int i=2; ;i++){
		res[i] = (res[i-1]+res[i-2])%m;
		if(res[i]==1 and res[i-1]==0){
			return i-1;
			break;
		}
	}
	// return res;
	return -1;
}

void solve(){
	ll n,m; cin>>n>>m;
	int sz = pisano_seq(m);
	// for(int i=0;i<sz;i++){
	// 	cout<<res[i]<<" ";
	// }
	// cout<<endl;
	cout<<res[n%sz]<<endl;	
}

int main(){
	IOS;
	solve();
return 0;
}