#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0,n = cardPoints.size();
        int win = n - k;
        for(int i = 0;i < win;++i) sum += cardPoints[i];
        int minx = sum;
        for(int i = win;i < n;++i){
            sum += cardPoints[i] - cardPoints[i-win];
            minx = min(minx, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minx;
    }
};
/*
 *### 解题思路
 *因为只能从头和尾拿取，所以剩下的n-k个数字肯定是连续的，所以我们可以维护一个滑动窗口，求出最小的n-k的子段和，然后用总和减去最小的子段和就是最大的能拿取的和。
 *
 *### 代码
 *
 *```cpp
 *class Solution {
 *public:
 *    int maxScore(vector<int>& cardPoints, int k) {
 *        int sum = 0,n = cardPoints.size()，win = n - k;
 *        for(int i = 0;i < win;++i) sum += cardPoints[i];
 *        int minx = sum;
 *        for(int i = win;i < n;++i){
 *            sum += cardPoints[i] - cardPoints[i-win];
 *            minx = min(minx, sum);
 *        }
 *        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minx;
 *    }
 *};
 *```
 */
