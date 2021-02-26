#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> buc;
        for(const string &word : words) {
            int mask = 0;
            for(char ch : word){
                mask |= (1 << (ch - 'a'));
            }
            if(__builtin_popcount(mask) <= 7){
                ++buc[mask];
            }
        }
        vector<int>ans;
        for(const string &puzzle : puzzles){
            int total = 0;
            int mask = 0;
            for(int i = 1;i < 7;++i){
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            do{
                int s = subset | (1 << (puzzle[0] - 'a'));
                if(buc.count(s)){
                    total += buc[s];
                }
                subset = (subset - 1) & mask;
            }while(subset != mask);
            ans.push_back(total);
        }
        return ans;
    }
};
