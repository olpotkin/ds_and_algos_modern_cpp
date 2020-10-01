#include <iostream>
#include <vector>
#include <algorithm>


/// Parallel processing
///
/// Intro: In this problem you will simulate a program that processes a list of jobs in parallel. Operating systems
///        such as Linux, MacOS or Windows all have special programs in them called schedulers which do exactly this
///        with the programs on your computer.
///
/// Task: You have a program which is parallelized and uses n independent threads to process the given list of m jobs.
///       Threads take jobs in the order they are given in the input. If there is a free thread, it immediately takes
///       the next job from the list. If a thread has started processing a job, it doesn’t interrupt or stop until it
///       finishes processing the job. If several threads try to take jobs from the list simultaneously, the thread
///       with smaller index takes the job. For each job you know exactly how long will it take any thread to process
///       this job, and this time is the same for all the threads. You need to determine for each job which thread will
///       process it and when will it start processing.
///
/// Input: The first line of the input contains integers n and m. The second line contains m integers t_i — the times
///        in seconds it takes any thread to process i-th job. The times are given in the same order as they are in the
///        list from which threads take jobs. Threads are indexed starting from 0.
///
/// Output: Output exactly m lines. i-th line (0-based index is used) should contain two spaceseparated integers
///         — the 0-based index of the thread which will process the i-th job and the time in seconds when it will start
///         processing that job.


struct Thread {
  int threadIdx;
  long long finishTime;
};


class JobQueue {
 private:
  int num_workers_;
  std::vector<Thread>    threads;
  std::vector<long long> jobs_;
  std::vector<int>       assigned_workers_;
  std::vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      std::cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long  m;
    std::cin >> num_workers_ >> m;

    threads.resize(num_workers_);
    jobs_.resize(m);
    for(long long i = 0; i < m; ++i) {
      std::cin >> jobs_[i];
    }
  }

  /// New Approach Implementation
  int getLeftChild(const int i) {
    if (i == 0) return i + 1;

    return 2*i + 1;
  }

  /// New Approach Implementation
    int getRightChild(const int i) {
    if (i == 0) return i + 2;

    return 2*i + 2;
  }

  /// New Approach Implementation
  /// Use finish_time to determine the order
  void SiftDown(const int i) {
    int minIdx = i;

    int left = getLeftChild(i);
    // If both finish_time are equal, compare index of threads
    if (left < threads.size()) {
      if (threads[left].finishTime < threads[minIdx].finishTime ||
           (threads[left].finishTime == threads[minIdx].finishTime &&
            threads[left].threadIdx < threads[minIdx].threadIdx)) {
          minIdx = left;
      }
    }

    int right = getRightChild(i);
    if (right < threads.size()) {
      if (threads[right].finishTime < threads[minIdx].finishTime ||
           (threads[right].finishTime == threads[minIdx].finishTime &&
            threads[right].threadIdx < threads[minIdx].threadIdx)) {
         minIdx = right;
      }
    }

    if (i != minIdx) {
      std::swap(threads[i], threads[minIdx]);
      SiftDown(minIdx);
    }
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    /*
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    std::vector<long long> next_free_time(num_workers_, 0);

    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
    */

    /// New Approach Implementation
    for (int i = 0; i < num_workers_; ++i) {
      threads[i].threadIdx  = i;
      threads[i].finishTime = 0;
    }

    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    for (int i = 0; i < jobs_.size(); ++i) {
      assigned_workers_[i] = threads[0].threadIdx;
      start_times_[i]      = threads[0].finishTime;

      // Update finish time of root
      long long updFinishTime = threads[0].finishTime + jobs_[i];
      threads[0].finishTime   = updFinishTime;

      // Check if the heap changed after the update of finish_time of the root
      SiftDown(0);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);

  JobQueue job_queue;
  job_queue.Solve();

  return 0;
}
