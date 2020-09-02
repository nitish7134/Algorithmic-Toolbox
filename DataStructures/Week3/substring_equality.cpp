//UNSOLVED
#include <bits/stdc++.h>
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);                   \
	cerr.tie(NULL)
#define ll long long
#define test  \
	int t;    \
	cin >> t; \
	while (t--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define foi(i, initial, n) for (ll i = initial; i < n; i++)
#define fori(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a)                      \
	fo(i, a.size()) cout << a[i] << " "; \
	cout << endl;

using namespace std;
	int m1 = 1000000007;
	int m2 = 1000000009;
class Solver
{
	string s;
	vector<unsigned long long> H1, H2;

	int x;

public:
	Solver(string s) : s(s)
	{
		x = 1 + (rand() % m1);
		H1.resize(s.size() + 1);
		H2.resize(s.size() + 1);
		H1[0] = 0;
		H2[0] = 0;
		fori(i, s.size())
		{
			H1[i] = (x * H1[i - 1] + s[i-1]) % m1;
			H2[i] = (x * H1[i - 1] + s[i-1]) % m2;
		}
		printvec(H1);
		cout << endl;
		printvec(H2);
	}
	bool ask(int a, int b, int l)
	{
		long long mul1 = 1, mul2 = 1;
		fo(i, l)
		{
			mul1 = (mul1 * x) % m1;
			mul2 = (mul2 * x) % m2;
		}
		if ((H1[a + l] - (mul1 * H1[a])) % m1 == (H1[b + l] - (mul1 * H1[b])) % m1)
			if ((H2[a + l] - (mul2 * H2[a])) % m2 == (H2[b + l] - (mul2 * H2[b])) % m2)
				return s.substr(a, l) == s.substr(b, l);
			else
			{
				cout << a << " " << b << " " << l << ":" << (H2[a + l] - (mul2 * H2[a])) % m2 << " " << (H2[b + l] - (mul2 * H2[b])) % m2 << endl;
			}
		else
		{
			cout << a << " " << b << " " << l << ":" << (H1[a + l] - (mul1 * H1[a])) % m1 << " " << (H1[b + l] - (mul1 * H1[b])) % m1 << endl;
		}

		return false;
	}
};

int main()
{
	IOS;
	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
