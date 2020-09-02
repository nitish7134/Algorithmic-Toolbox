#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query
{
    string type, s;
    size_t ind;
};

class QueryProcessor
{
    int bucket_count;
    vector<vector<string>> elems;
    size_t hash_func(const string &s) const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
            hash = ((hash * multiplier + s[i]) % prime + prime) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) {}

    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query &query)
    {
        if (query.type == "check")
        {
            int index = query.ind;
            for (int i = elems[index].size() - 1; i >= 0; i--)
            {
                cout << elems[index][i] << " ";
            }
            cout << "\n";
        }
        else
        {
            int hash = hash_func(query.s);
            bool isFound = false;
            auto itr = find(elems[hash].begin(), elems[hash].end(), query.s);
            if (itr != elems[hash].end())
                isFound = true;
            if (query.type == "find")
            {
                writeSearchResult(isFound);
            }
            else if (query.type == "add")
            {
                if (!isFound)
                    elems[hash].push_back(query.s);
            }
            else if (query.type == "del")
            {
                if (isFound)
                {
                    elems[hash].erase(itr);
                }
            }
        }
    }

    void processQueries()
    {
        int n;
        elems.resize(bucket_count);
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
