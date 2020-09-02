//UNSOLVED	
#include <cstdio>
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

class Rope {
	string s;
public:
	Rope(const string &s) : s(s) { 
	}

	void process( int i, int j, int k ) {
                // Replace this code with a faster implementation
                string t = s.substr(0, i) + s.substr(j + 1);
                s = t.substr(0, k) + s.substr(i, j - i + 1) + t.substr(k);
	}

	string result() {
		return s;
	}
};

int main() {
IOS;
	string s;
	cin >> s;
	Rope rope(s);
	int actions;
	cin >> actions;
        for (int action_index = 0; action_index < actions; ++action_index) {
                int i, j, k;
		cin >> i >> j >> k;
		rope.process(i, j, k);
	}
	cout << rope.result() <<endl;
}
