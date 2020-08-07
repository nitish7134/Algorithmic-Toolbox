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


void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

int min(int a, int b) {
    return a<=b ? a : b;
}
void max_sliding_window(vector<int> A, int w) {
    deque<int> Q(w);
    int i;
    for (i=0;i<min(A.size(), w);i++) {
        while ((!Q.empty()) && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    for (;i<A.size();++i) {
        cout << A[Q.front()] << " ";

        while ((!Q.empty()) && Q.front() <= i - w)
            Q.pop_front();

        while ((!Q.empty()) && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);

    }
    cout << A[Q.front()];


    return;
}


int main() {
    IOS;
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
