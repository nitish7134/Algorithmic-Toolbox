#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder
{
private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  int leftChildIndex(int i)
  {
    int r = (2 * i) + 1;
    return r >= data_.size() ? -1 : r;
  }
  int rightChildIndex(int i)
  {
    int r = (2 * i) + 2;
    return r >= data_.size() ? -1 : r;
  }

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i)
    {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void swap(int i, int j)
  {
    swaps_.push_back({i, j});
    int temp = data_[i];
    data_[i] = data_[j];
    data_[j] = temp;
  }
  void moveDown(int i)
  {
    int smallerOne = i;
    int l = leftChildIndex(i);
    int r = rightChildIndex(i);
    if (l != -1 && data_[i] > data_[l])
      smallerOne = l;
    if (r != -1 && data_[smallerOne] > data_[r])
      smallerOne = r;
    if (smallerOne != i)
    {
      swap(i, smallerOne);
      moveDown(smallerOne);
    }
  }
  void GenerateSwaps()
  {
    swaps_.clear();
    for (int i = data_.size() / 2; i >= 0; i--)
    {
      moveDown(i);
    }
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
