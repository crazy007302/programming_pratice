#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }

    if (sum % 2 != 0) return false;  // 总和为奇数，无法分割
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // 初始状态：和为0

    for (int num : nums) {                   // 遍历物品（数字）
      for (int j = target; j >= num; j--) {  // 倒序遍历背包容量
        dp[j] =
            dp[j] ||
            dp[j - num];  // ||
                          // 操作：逻辑或，表示只要以下两种情况有一种成立，dp[j]
                          // 就为 true：
      }
    }
    return dp[target];
  }
};

int main() {
  vector<int> value = {15, 20, 30, 35};

  Solution sol;
  bool res = sol.canPartition(value);

  cout << "a: " << res << endl;

  return 0;
}