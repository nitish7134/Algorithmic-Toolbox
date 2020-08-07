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


vector<int> res;
int fib(int n){
	
	return -1;
}


int calculateSum(int n,int m) 
{ 
    return fib(n+2) - fib(m+2) - 2; 
} 

int main(){
	IOS;
	int n,m;
	res.resize(n);
	cin>>m>>n;
	cout<<calculateSum(n,m);
return 0;
}