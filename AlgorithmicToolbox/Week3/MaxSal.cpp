#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define MAX 1000003
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define input(a)                \
	for (int i = 0; i < n; i++) \
		cin >> a[i];
#define test  \
	int t;    \
	cin >> t; \
	while (t--)
#define vi vector<int>
#define vii vector<pair<int, int>>
#define ii pair<int, int>
using namespace std;

string maxs(string a, string b)
{

	string XY = a + b;
	string YX = b + a;
	if (XY > YX)
		return a;
	else
		return b;
}
int maxi(vector<string> a)
{
	string temp = a[0];
	if (a.size() == 1)
		return 0;

	int j = 0;
	for (int i = 1; i < a.size(); i++)
	{
		temp = maxs(temp, a[i]);
		if (temp == a[i])
			j = i;
	}
	return j;
}
string largest_number(vector<string> a)
{

	string result = "", temp;

	while (a.size() != 0)
	{
		result += a[maxi(a)];
		a.erase(a.begin() + maxi(a));
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++)
		cin >> a[i];

	cout << largest_number(a);
}