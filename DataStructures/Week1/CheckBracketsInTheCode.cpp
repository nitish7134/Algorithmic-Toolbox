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

int main() {
    IOS;
    vector<char> stack;
    vector<char> stacki;
    string c;
    getline(cin, c);
    int firstOpen = -1;
    fo(i, c.length()) {

        if (c[i]=='[' || c[i] == '{' || c[i] == '(') {
            if (firstOpen==-1)
                firstOpen = i+1;
            stack.push_back(c[i]);
            stacki.push_back(i);
        }
        else
        {
            if (c[i]!=']' && c[i]!='}' && c[i]!=')') {
                continue;

            }
            if (stack.empty()) {
                cout<<i+1<<endl;
                return 0;
            }
            if ((stack.back() == '(' && c[i]!=')') || (stack.back() == '{' && c[i]!='}') || (stack.back() == '[' && c[i]!=']')) {
                cout<<i+1<<endl;
                return 0;
            }
            else
            {
                stack.pop_back();
                stacki.pop_back();
            }

        }
    }
    if (stack.empty())
        cout<<"Success"<<endl;
    else
    {
        cout<<stacki.front()+1<<endl;
    }
    return 0;
}