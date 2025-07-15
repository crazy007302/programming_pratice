#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int knapsack(vector<int>& weight, vector<int>& value, int bagweight) {
    // dp[i][j] 表示从0~i-1号物品中选择，背包容量为j时的最大价值
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化：只考虑第一个物品（i=0）
    for (int j = weight[0]; j <= bagweight; j++) {
      dp[0][j] = value[0];
    }

    // 递推：考虑后续物品
    for (int i = 1; i < weight.size(); i++) {
      for (int j = 0; j <= bagweight; j++) {
        if (j < weight[i]) {
          dp[i][j] = dp[i - 1][j];  // 当前物品放不下，继承上一状态
        } else {
          dp[i][j] = max(dp[i - 1][j],                        // 不放当前物品
                         dp[i - 1][j - weight[i]] + value[i]  // 放当前物品
          );
        }
      }
    }

    return dp[weight.size() - 1][bagweight];
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