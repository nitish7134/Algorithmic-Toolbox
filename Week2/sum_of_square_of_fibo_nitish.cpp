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

long long calc_fib(long long n) {

    n = (n+2)%60;
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    int res = 1;
    for(int i = 2; i<=n;i++){
        fib[i] = (fib[i-1]%10 + fib[i-2]%10)%10;
        // res = res + fib[i];
    }
    // cout<<fib[n]<<"\n";
    // if(fib[n] == 0){
    //     return 9;
    // }
    return (fib[n]%10);
}

void solve(){
	int n; cin>>n;
	int res = (calc_fib(n-2)*calc_fib(n-1))%10;
	cout<<res;
}

int main(){
	IOS;
	solve();
return 0;
}