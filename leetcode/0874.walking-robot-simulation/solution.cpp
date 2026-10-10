// Created by Anshul Kumar at 2026/10/10 14:25
// leetgo: dev
// https://leetcode.com/problems/walking-robot-simulation/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  struct Robot {
    int x;
    int y;
    int dir;
    Robot(int x, int y, int dir) : x(x), y(y), dir(dir) {}
  };
  void move(Robot &r, int cmd, unordered_set<unsigned long long> &obstacles) {
    if (cmd == -1) {
      r.dir = (r.dir + 1) % 4;
    } else if (cmd == -2) {
      r.dir = (r.dir - 1 + 4) % 4;
    } else {

      vector<vector<int>> m;
      m.push_back({0, 1});
      m.push_back({1, 0});
      m.push_back({0, -1});
      m.push_back({-1, 0});

      auto t = m[r.dir];
      for (int i = 0; i < cmd; i++) {
        int newx = r.x + t[0];
        int newy = r.y + t[1];
        unsigned long long p = (unsigned long long)((newx + 30000) << 16) |
                               (unsigned long long)(newy + 30000);
        if (obstacles.find(p) != obstacles.end()) {
          return;
        }
        r.x = newx;
        r.y = newy;
      }
    }
  }
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    Robot r(0, 0, 0);
    unordered_set<unsigned long long> s;

    if (commands.size() == 0)
      return 0;
    for (auto &obs : obstacles) {
      unsigned long long p = ((unsigned long long)(obs[0] + 30000) << 16) |
                             (unsigned long long)(obs[1] + 30000);
      s.insert(p);
    }
    int dist = 0;

    for (int i = 0; i < commands.size(); i++) {
      int cmd = commands[i];
      move(r, cmd, s);
      dist = max(dist, (r.x * r.x) + (r.y * r.y));
    }
    return dist;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  try {
    vector<int> commands = LeetCodeIO::deserialize<vector<int>>(cin);
    vector<vector<int>> obstacles =
        LeetCodeIO::deserialize<vector<vector<int>>>(cin);

    Solution obj;
    auto res = obj.robotSim(commands, obstacles);

    stringstream out_stream;
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << '\n';
  } catch (const LeetCodeIO::Error &error) {
    cerr << "LC_IO: " << error.what() << '\n';
    return 2;
  }
  return 0;
}
