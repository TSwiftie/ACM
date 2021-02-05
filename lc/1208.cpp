#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/*
 *class Solution {
 *public:
 *    int sum[100005];
 *    int equalSubstring(string s, string t, int maxCost) {
 *        int n = s.size(),ans = 0;
 *        sum[0] = abs(s[0] - t[0]);
 *        for(int i = 1;i < n;++i) sum[i] = sum[i-1] + abs(s[i] - t[i]);
 *        for(int i = 0;i < n;++i) printf("%d%c",abs(s[i]-t[i])," \n"[i==n-1]);
 *        for(int i = 0;i < n;++i) printf("%d%c",sum[i]," \n"[i==n-1]);
 *        for(int i = 0;i < n;++i){
 *            if(sum[i] <= maxCost){
 *                ans = max(ans, i);
 *                continue;
 *            }else{
 *                int re = sum[i] - maxCost;
 *                int pos = lower_bound(sum,sum+i, re) - sum;
 *                ans = max(ans,i-pos);
 *            }
 *        }
 *    }
 *};
 */
class Solution {
public:
    int diff[100005];
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(),ans = 0,sum = 0;
        for(int i = 0;i < n;++i) diff[i] =  abs(s[i] - t[i]);
        int l = 0,r = 0;
        while(r < n){
            sum += diff[r];
            while(sum > maxCost) sum -= diff[l++];
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};
