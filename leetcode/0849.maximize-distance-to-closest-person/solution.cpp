// Created by Anshul Kumar at 2026/10/09 20:05
// leetgo: dev
// https://leetcode.com/problems/maximize-distance-to-closest-person/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    int n = seats.size();

    vector<int> dist(n, INT_MAX);
    int seat = -1;
    for (int i = 0; i < n; i++) {
      if (seats[i] == 1) {
        seat = i;
      }
      if (seat == -1)
        continue;
      dist[i] = i - seat;
    }

    seat = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (seats[i] == 1) {
        seat = i;
      }
      if (seat == -1)
        continue;
      dist[i] = min(dist[i], seat - i);
    }
    cout << seat << endl;

    int max_num = 0;
    for (int d : dist) {
      max_num = max(d, max_num);
      cout << d << " ";
    }
    return max_num;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<int> seats = LeetCodeIO::deserialize<vector<int>>(cin);

    Solution obj;
    auto res = obj.maxDistToClosest(seats);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
