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


vector<int> solve(int k, const string &text, const string &pattern) {
	vector<int> pos;
	return pos;
}

int main() {
IOS;
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
