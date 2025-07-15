#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int knapsack(vector<int>& weight, vector<int>& value, int bagweight) {
    vector<int> dp(bagweight + 1, 0);  // dp[j] 表示背包容量为j时的最大价值

    // 递推：考虑后续物品
    for (int i = 0; i < weight.size(); i++) {
      for (int j = bagweight; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
      }
    }

    return dp[bagweight];
  }
};

int main() {
  vector<int> weight = {1, 3, 4};    // 物品重量
  vector<int> value = {15, 20, 30};  // 物品价值
  int bagweight = 4;                 // 背包容量

  Solution sol;
  int res = sol.knapsack(weight, value, bagweight);

  cout << "max_value: " << res << endl;  // 输出35（物品0+物品1）

  return 0;
}