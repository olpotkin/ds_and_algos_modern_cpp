#include <iostream>
#include <cassert>
#include <vector>


/// Intro: You are going to travel to another city that is located d miles away from your home city.
///        Your car can travel at most m miles on a full tank and you start with a full tank.
///        Along your way, there are gas stations at distances stop_1, stop_2, ... , stop_n from your home city.
///        What is the minimum number of refills needed?
///
/// Input Format: The first line contains an integer d. The second line contains an integer m.
///               The third line specifies an integer n. Finally, the last line contains
///               integers stop_1, stop_2, ... , stop_n.
///
/// Output Format: Assuming that the distance between the cities is d miles, a car can travel at most m miles
///                on a full tank, and there are gas stations at distances stop_1, stop_2, ... , stop_n along the way,
///                output the minimum number of refills needed. Assume that the car starts with a full tank.
///                If it is not possible to reach the destination, output −1.
///


/// @param[in] dist - overall distance
/// @param[in] tank - length of the drive with full tank
/// @param[in] stops - gas stations at distances
int compute_min_refills(const int dist,
                        const int tank,
                        const std::vector<int>& stops) {
  const int numOfStations = stops.size();
  int numOfRefills        = 0;
  int currStation         = 0;

  int startAfterRefill    = 0;

  while (currStation < numOfStations) {
    int lastRefillStation = currStation;

    // If there is enough fuel to reach the finish point
    if (startAfterRefill + tank >= dist)
      break;

    // Skip stations if we have enough fuel
    while ((currStation < numOfStations) &&
           (stops[currStation] - startAfterRefill <= tank)) {
      ++currStation;
    }

    // Still on the same station -> not enough fuel
    if (currStation == lastRefillStation)
      return -1;

    // Refill
    if (currStation <= numOfStations) {
      ++numOfRefills;
      startAfterRefill = stops[currStation-1];

      // We used last station, but not enough fuel to reach finish
      if ((currStation == numOfStations) &&
          (startAfterRefill + tank < dist)) {
        return -1;
      }
    }
  }

  return numOfRefills;
}


void test_solution() {
  /// The distance between the cities is 950,
  /// the car can travel at most 400 miles on a full tank.
  /// It suffices to make two refills: at points 375 and 750.
  /// This is the minimum number of refills as with a single refill one would only be able to travel at most 800 miles.
  assert(compute_min_refills(950, 400, std::vector<int> {200, 375, 550,750}) == 2);
  std::cout << "Test 01 passed..." << std::endl;

  // One cannot reach the gas station at point 9 as the previous gas station is too far away.
  assert(compute_min_refills(10, 3, std::vector<int> {1, 2, 5, 9}) == -1);
  std::cout << "Test 02 passed..." << std::endl;

  assert(compute_min_refills(700, 200, std::vector<int> {100, 200, 300, 400}) == -1);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  int d = 0;
  std::cin >> d;

  int m = 0;
  std::cin >> m;

  int n = 0;
  std::cin >> n;

  std::vector<int> stops(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> stops.at(i);
  }

  std::cout << compute_min_refills(d, m, stops) << std::endl;

  return 0;
}
