#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cassert>


/// Introduction: You are responsible for collecting signatures from all tenants of a certain building.
///               For each tenant, you know a period of time when he or she is at home. You would like to
///               collect all signatures by visiting the building as few times as possible.
///               The mathematical model for this problem is the following. You are given a set of segments
///               on a line and your goal is to mark as few points on a line as possible so that each segment
///               contains at least one marked point.
///
/// Task: Given a set of 𝑛 segments {[a_0, b_0], [a_1, b_1], ... , [a_n−1, b_n−1]} with integer coordinates
///       on a line, find the minimum number m of points such that each segment contains at least one point.
///       That is, find a set of integers X of the minimum size such that for any segment [a_i, b_i] there is a
///       point x ∈ X such that a_i <= x ≤ b_i.
///
/// Input: The first line of the input contains the number n of segments. Each of the following n lines contains
///        two integers a_i and b_i (separated by a space) defining the coordinates of endpoints of the i-th segment.
///
/// Output: Output the minimum number m of points on the first line and the integer coordinates of m points (separated
///         by spaces) on the second line. You can output the points in any order. If there are many such sets of points,
///         you can output any set. (It is not difficult to see that there always exist a set of points of the minimum
///         size such that all the coordinates of the points are integers.)
///
/// Some helpful links:
/// https://medium.com/competitive/covering-segments-by-points-fc2c56c4b038
///


struct Segment {
  int start;
  int end;
};


std::vector<int> optimal_points(std::vector<Segment>& segments) {
  // The key is to sort the segments according to their end points.
  std::sort(segments.begin(), segments.end(),
    [](const Segment& lhs, const Segment& rhs) -> bool { return lhs.end < rhs.end; });

//  for (const auto& s : segments)
//    std::cout << "sorted - Segment { " << s.start << ", " << s.end << " }" << std::endl;

  std::vector<int> points;
  // Taking end point of the first segment
  int curr_point = segments[0].end;
  points.push_back(curr_point);

  for (const auto& s : segments) {
    // If current point is not in the segment
    if (curr_point < s.start || curr_point > s.end) {
      // Update current point
      curr_point = s.end;
      // Add current point to the result
      points.push_back(curr_point);
    }
  }
  
  return points;
}


void test_solution() {
  /// In this sample, we have three segments: [1, 3], [2, 5], [3, 6] (of length 2, 3, 3 respectively).
  /// All of them contain the point with coordinate 3:
  /// 1 <= 3 <= 3,
  /// 2 <= 3 <= 5,
  /// 3 <= 3 <= 6.
  std::vector<Segment> inputData_test_1 {
    Segment{1, 3},
    Segment{2, 5},
    Segment{3, 6} };
  const std::vector<int> expectedResult_test_1 { 3 };
  assert(optimal_points(inputData_test_1) == expectedResult_test_1);
  std::cout << "Test 01 passed..." << std::endl;

  /// The second and the third segments contain the point with coordinate 3
  /// while the first and the fourth segments contain the point with coordinate 6.
  /// All the four segments cannot be covered by a single point, since the segments [1,3] and [5,6] are disjoint.
  std::vector<Segment> inputData_test_2 {
    Segment{4, 7},
    Segment{1, 3},
    Segment{2, 5},
    Segment{5, 6} };
  const std::vector<int> expectedResult_test_2 { 3, 6 };
  assert(optimal_points(inputData_test_2) == expectedResult_test_2);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  std::vector<int> points = optimal_points(segments);

  std::cout << points.size() << std::endl;
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
