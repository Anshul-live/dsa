// Created by Anshul Kumar at 2026/10/07 09:19
// leetgo: dev
// https://leetcode.com/problems/single-number-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int arr[32] = {0};

      for(auto& num : nums){
      int temp = num;
      int bit = 0;
      while(temp != 0){
        arr[bit] += (temp & 1);
        bit++;
        temp >>= 1;
      }
    }

    int ans = 0;
    int bit = 0;
    for(auto & i : arr){
      if(i % 3 == 1){
        ans |= 1 << bit;
      }
      bit++;
    }
    return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.singleNumber(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
