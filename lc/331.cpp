#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length(),i = 0,slots = 1;
        while (i < n) {
            if (slots == 0) return false;
            if (preorder[i] == ',') --i;
            else if (preorder[i] == '#') --slots,++i;
            else {
                while (i < n && preorder[i] != ',') i++;
                ++slots;
            }
        }
        return slots == 0;
    }
};
