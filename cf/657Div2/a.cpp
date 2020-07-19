/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 04:56:22 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 55;
string str,ed = "abacaba";
signed main(void){
    IOS;
    int t;
    for(cin >> t;t--;){
        int n;
        cin >> n >> str;
        bool mark;
        int pos = -1,cnt = 0;
        for(int i = 0;i <= n-7;++i){
            string tmp = str.substr(i,7);
            mark = false;
            for(int j = 0;j < 7;++j){
                if(tmp[j]!=ed[j]&&tmp[j]!='?'){
                    mark = true;
                    break;
                }
            }
            if(!mark){
                pos = i;
                ++cnt;
            }
        }
        if(pos!=-1&&cnt==1){
            cout << "Yes" << endl;
            for(int i = 0;i < pos;++i){
                if(str[i]=='?') cout << 'a';
                else cout << str[i];
            }
            cout << ed;
            for(int i = pos+7;i < n;++i){
                if(str[i]=='?') cout << 'a';
                else cout << str[i];
            }
            cout << endl;
        }else cout << "No" << endl;
    }
    return 0;
}
