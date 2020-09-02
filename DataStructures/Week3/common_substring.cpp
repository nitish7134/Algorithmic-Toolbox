//Unsolved
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
#define printvec(a) fo(i, a.size()) cout << a[i] << " "
typedef unsigned long long ull;

using namespace std;
int x;
int p1 = 1000000007;
int p2 = 1000000009;
struct Answer
{
	size_t i = 0, j = 0, len = 0;
	bool worked = false;
};
size_t hash_func(const string &s, int prime)
{
	unsigned long long hash = 0;
	for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
		hash = ((hash * x + s[i]) % prime + prime) % prime;
	return hash;
}
Answer works(int k, string s, string t)
{

	vector<long long> H11(s.size() - k + 1);
	vector<long long> H21(s.size() - k + 1);
	vector<long long> H12(s.size() - k + 1);
	vector<long long> H22(s.size() - k + 1);

	string sub = s.substr(s.size() - k, k);

	H11[s.size() - k] = hash_func(sub, p1);
	H21[s.size() - k] = hash_func(sub, p2);

	sub = t.substr(t.size() - k, k);

	H11[t.size() - k] = hash_func(sub, p1);
	H21[t.size() - k] = hash_func(sub, p2);

	int y1 = 1, y2 = 1;
	fo(i, k)
	{
		y1 = (y1 * x) % p1;
		y2 = (y2 * x) % p2;
	}

	for (int i = s.size() - k - 1; i >= 0; i--)
	{
		H11[i] = (((x * H11[i + 1]) + (int)s[i] - (y1 * (int)t[i + k]))+p1) % p1;
		H21[i] = (((x * H21[i + 1]) + (int)s[i] - (y2 * (int)t[i + k]))+p2) % p2;
	}
	multimap<int, int> HashedS1;
	fo(i, H11.size())
	{
		HashedS1.insert({H11[i], i});
	}

	for (int i = t.size() - k - 1; i >= 0; i--)
	{
		H12[i] = (((x * H12[i + 1]) + (int)t[i] - (y1 * (int)t[i + k]))+p1) % p1;
		H22[i] = (((x * H22[i + 1]) + (int)t[i] - (y2 * (int)t[i + k]))+p2) % p2;
		int key = H12[i];
		auto itr1 = HashedS1.lower_bound(key);
		auto itr2 = HashedS1.upper_bound(key);

		while (itr1 != itr2)
		{
			if (itr1->first == key)
			{
				int j = itr1->second;
				if (H22[i] == H12[j])
					if (s.substr(j, k) == t.substr(i, k))
					{
						Answer a;
						a.i = i;
						a.j = j;
						a.len = k;
						a.worked = true;
						return a;
					}
			}
			itr1++;
		}
	}
	Answer a;
	a.worked = false;
	a.i = 0;
	a.j = 0;
	a.len = 0;
	return a;
}
bool check() {}
Answer solve(const string &s, const string &t)
{
	Answer ans;

	int l = 0, r = min(s.size(), t.size());
	while (l != r)
	{
		int k = l + r;
		k /= 2;
		Answer temp = works(k, s, t);
		if (temp.worked)
		{
			ans = temp;
			l = k;
		}
		else
		{
			r = k - 1;
		}
	}
	return ans;
}

int main()
{
	IOS;
	x = rand() % p1 + 1;
	string s, t;
	while (cin >> s >> t)
	{
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}