#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct thread
{
  int index;
  long long doneTime = 0;
};

class JobQueue
{
private:
  int num_workers_;
  vector<thread> threads;

  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const
  {
    for (int i = 0; i < jobs_.size(); ++i)
    {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData()
  {
    int m;
    cin >> num_workers_ >> m;
    threads.resize(num_workers_);
    jobs_.resize(m);
    for (int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
  int leftChildIndex(int i)
  {
    int r = (2 * i) + 1;
    return r >= jobs_.size() ? -1 : r;
  }
  int rightChildIndex(int i)
  {
    int r = (2 * i) + 2;
    return r >= jobs_.size() ? -1 : r;
  }
  void moveDown(int i)
  {
    int minIndex = i;
    int l = leftChildIndex(i);
    // if both finish_time are the same compare index of threads
    if (l < threads.size())
    {
      if ((threads[l].doneTime < threads[minIndex].doneTime) || (threads[l].doneTime == threads[minIndex].doneTime && threads[l].index < threads[minIndex].index))
      {
        minIndex = l;
      }
    }
    int r = rightChildIndex(i);
    if (r < threads.size())
    {
      if ((threads[r].doneTime < threads[minIndex].doneTime) || (threads[r].doneTime == threads[minIndex].doneTime && threads[r].index < threads[minIndex].index))
      {
        minIndex = r;
      }
    }
    if (i != minIndex)
    {
      swap(threads[i], threads[minIndex]);
      moveDown(minIndex);
    }
  }
  void AssignJobs()
  {
    for (int i = 0; i < num_workers_; i++)
    {
      threads[i].index = i;
      threads[i].doneTime = 0;
    }
    assigned_workers_.resize(jobs_.size());
    start_times_.reserve(jobs_.size());
    for (int i = 0; i < jobs_.size(); i++)
    {

      assigned_workers_[i] = threads[0].index;
      assigned_workers_[i] = threads[0].index;
      start_times_[i] = threads[0].doneTime;
      threads[0].doneTime += jobs_[i];
      moveDown(0);
    }
  }

public:
  void Solve()
  {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
