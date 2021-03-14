#include <bits/stdc++.h>
#include <cctype>
#include <sstream>
using namespace std;
string str;
vector<string>lines;
signed main(void){
    while(getline(cin,str)){
        string word;
        lines.emplace_back(str);
        vector<string>words;
        for(int i = 0;i < str.size();++i){
            if(isalpha(str[i])) word += str[i];
            else{
                if(word=="") continue;
                else words.emplace_back(word),word = "";
            }
        }
        for(const string & st : words) cout << st << endl;
    }
    return 0;
}

/*
 *In wilds beyond they speak your NamE WRAR (With Reverence And Regret),
 *For none could tame our SS (Savage Souls) yet you the challenge met,
 *Under, Palest. Watch, YT (You Taught) , you changed. Base instincts were redeemed,
 *A WY (World You) gave to bug and beast as they had never dreamed.
 */
