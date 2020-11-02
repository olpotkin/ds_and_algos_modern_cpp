#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


/// Intro: You are organizing an online lottery. To participate, a person bets on a single integer.
///        You then draw several ranges of consecutive integers at random. A participant’s payoff then
///        is proportional to the number of ranges that contain the participant’s number minus the number
///        of ranges that does not contain it. You need an efficient algorithm for computing the payoffs
///        for all participants. A naive way to do this is to simply scan, for all participants, the
///        list of all ranges. However, you lottery is very popular: you have thousands of participants
///        and thousands of ranges. For this reason, you cannot afford a slow naive algorithm.
///
/// Task: You are given a set of points on a line and a set of segments on a line. The goal is to compute,
///       for each point, the number of segments that contain this point.
///
/// Input Format: The first line contains two non-negative integers s and p defining the number of segments
///               and the number of points on a line, respectively. The next s lines contain two
///               integers a_i, b_i defining the i-th segment [a_i, b_i]. The next line contains p integers
///               defining points x_1, x_2, ... , x_p.
///
/// Output Format: Output p non-negative integers k_0, k_1, ... , k_p−1 where k_i is the number of segments
///                which contain x_i.
///


std::vector<int> fast_count_segments(
  std::vector<std::pair<int, int>> segments,
  std::vector<int> points)
{
  std::vector<std::pair<int, int>> pts;
  std::vector<std::pair<int, int>> seg;

  // Pushing point and index in a vector as a pair
  for (int i = 0; i < points.size(); ++i) {
    pts.push_back(std::make_pair(points[i], i));
  }

  for (int i = 0; i < segments.size(); ++i) {
    // (l, +1)
    seg.push_back(std::make_pair(segments[i].first, 1));
    // (r+1, -1)
    seg.push_back(std::make_pair(segments[i].second + 1, -1));
  }

  // Sort the vector of points in ascending order mapped with positions
  std::sort(pts.begin(), pts.end());
  // Sort the vector of segments in descending order (to be iterated from back)
  std::sort(seg.begin(), seg.end(), std::greater<std::pair<int, int>>());

  // Create a vector to store the common points in the segments
  std::vector<int> cnt(points.size());
  // Count of segments
  int count = 0;

  // Iterate on the points and pop the pair from the segment vector until it's first value
  // is less than equal to current point and add it's second value to the count
  for (int i = 0; i < points.size(); ++i) {
    int pointPos = pts[i].first;

    while (!seg.empty() && seg.back().first <= pointPos) {
      count += seg.back().second;
      seg.pop_back();
    }

    cnt[pts[i].second] = count;
  }

  return cnt;
}


std::vector<int> naive_count_segments(
  std::vector<int> starts,
  std::vector<int> ends,
  std::vector<int> points)
{
  std::vector<int> cnt(points.size());

  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }

  return cnt;
}


void test_solution() {
  /// Here, we have two segments and three points. The first point lies only in the first segment while the
  /// remaining two points are outside of all the given segments.
  /// Expecting result: {1, 0, 0}
  std::vector<int> starts_test_01 {0, 7};
  std::vector<int> ends_test_01 {5, 10};
  std::vector<std::pair<int, int>> segments_test_01 {std::make_pair(0, 5), std::make_pair(7, 10)};
  std::vector<int> points_test_01 {1, 6, 11};

  std::vector<int> cnt_naive_test_01 = naive_count_segments(starts_test_01, ends_test_01, points_test_01);
  std::vector<int> cnt_fast_test_01  = fast_count_segments(segments_test_01, points_test_01);

  assert(cnt_naive_test_01 == cnt_fast_test_01);
  std::cout << "Test 01 passed..." << std::endl;

  /// Expecting result: {0, 0, 1}
  std::vector<int> starts_test_02 {-10};
  std::vector<int> ends_test_02 {10};
  std::vector<std::pair<int, int>> segments_test_02 {std::make_pair(-10, 10)};
  std::vector<int> points_test_02 {-100, 100, 0};

  std::vector<int> cnt_naive_test_02 = naive_count_segments(starts_test_02, ends_test_02, points_test_02);
  std::vector<int> cnt_fast_test_02  = fast_count_segments(segments_test_02, points_test_02);

  assert(cnt_naive_test_02 == cnt_fast_test_02);
  std::cout << "Test 02 passed..." << std::endl;

  /// Expecting result: {0, 0, 1}
  std::vector<int> starts_test_03 {0, -3, 7};
  std::vector<int> ends_test_03 {5, 2, 10};
  std::vector<std::pair<int, int>> segments_test_03 {std::make_pair(0, 5), std::make_pair(-3, 2), std::make_pair(7, 10)};
  std::vector<int> points_test_03 {1, 6};

  std::vector<int> cnt_naive_test_03 = naive_count_segments(starts_test_03, ends_test_03, points_test_03);
  std::vector<int> cnt_fast_test_03  = fast_count_segments(segments_test_03, points_test_03);

  assert(cnt_naive_test_03 == cnt_fast_test_03);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n, m;
  std::cin >> n >> m;

  // It will be easier to store segments as a pairs (for the fast solution)
  std::vector<std::pair<int, int>> segments;

  std::vector<int> starts(n);
  std::vector<int> ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
    // Only for fast solution:
    segments.push_back(std::make_pair(starts[i], ends[i]));
  }

  std::vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }

  // Use fast_count_segments
  //std::vector<int> cnt = naive_count_segments(starts, ends, points);
  std::vector<int> cnt = fast_count_segments(segments, points);

  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
