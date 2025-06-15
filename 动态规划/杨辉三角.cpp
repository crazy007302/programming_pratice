/*

简单

给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:

输入: numRows = 1
输出: [[1]]

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        res.push_back({1});

        for(int i = 1; i<numRows; i++){
            vector<int> row(i+1,1);
            for(int j=1; j<i; j++){
                row[j] = res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(row);
        }

        return res;
        
    }
};

int main() {
    int n = 10;

    Solution sol;
    vector<vector<int>> res = sol.generate(n);

    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++){
            cout << res[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}
