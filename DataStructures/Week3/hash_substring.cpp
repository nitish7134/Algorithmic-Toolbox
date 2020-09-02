#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

static const size_t multiplier = 6;
static const size_t prime = 1000000007;

struct Data
{
    string pattern, text;
};

Data read_input()
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
size_t hash_func(const string &s)
{

    unsigned long long hash = 0;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
        hash = ((hash * multiplier + s[i]) % prime + prime) % prime;
    return hash;
}
void print_occurrences(const std::vector<int> &output)
{
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
std::vector<int> get_occurrences(const Data &input)
{
    string s = input.pattern, t = input.text;
    vector<int> ans;
    int patternHash = hash_func(s);
    int S = t.size(), P = s.size();
    int H[S - P + 1];
    string sub = t.substr(S - P, P);
    H[S - P] = hash_func(sub);
    ull y = 1;
    for (int i = 1; i <= P; i++)
    {
        y = (y * multiplier) % prime;
    }
    for (int i = S - P - 1; i >= 0; i--)
    {
        H[i] = ((multiplier * H[i + 1]) + (int)t[i] - (y * (int)t[i + P])) % prime;
    }

    for (size_t i = 0; i <= S - P; ++i)
    {
        if (H[i] == patternHash)
        {
            sub = t.substr(i, P);
            if (sub == s)
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
