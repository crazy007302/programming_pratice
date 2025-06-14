/*
简单

假设你是⼀位很棒的家⻓，想要给你的孩⼦们⼀些⼩饼⼲。但是，每个孩⼦最多只能给⼀块饼⼲。
对每个孩⼦ i，都有⼀个胃⼝值 g[i]，这是能让孩⼦们满⾜胃⼝的饼⼲的最⼩尺⼨；并且每块饼⼲ j，都有⼀个尺⼨
s[j] 。如果 s[j] >= g[i]，我们可以将这个饼⼲ j 分配给孩⼦ i ，这个孩⼦会得到满⾜。你的⽬标是尽可能满⾜越多数
量的孩⼦，并输出这个最⼤数值。

输⼊: g = [1,2,3], s = [1,1]
输出: 1
解释:你有三个孩⼦和两块⼩饼⼲，3 个孩⼦的胃⼝值分别是：1,2,3。虽然你有两块⼩饼⼲，由于他们的尺⼨
都是 1，你只能让胃⼝值是 1 的孩⼦满⾜。所以你应该输出 1

!!!!!  大饼干先满足大胃口
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s){
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int index = s.size() - 1; // 饼干数组的下标
            int result = 0;
            for (int i = g.size() - 1; i >= 0; i--) {
                if (index >= 0 && s[index] >= g[i]) {
                    result++;
                    index--;
                }
            }
            return result;
        }
};

int main() {
    int n, m; // n个孩子，m块饼干
    cin >> n >> m;

    vector<int> g(n); // 孩子的胃口值
    vector<int> s(m); // 饼干的尺寸

    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    Solution sol;
    int res = sol.findContentChildren(g, s);
    cout << res << endl;

    return 0;
}
