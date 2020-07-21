/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 08:40:13 AM CST
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
int T,n;
string s,m = "abacaba";
void solve(){
    for(int i = 0;i+m.size()-1 < n;++i){
        string t = s;
        bool ok = true;
        for(int j = i,k = 0;k < m.size();++j,++k){
            if(s[j]!=m[k] && s[j]!='?') ok = false;
            t[j] = m[k];
        }
        if(!ok) continue;
        for(int j = 0;j < n;++j) if(t[j]=='?') t[j] = 'd';
        int cnt = 0;
        for(int j = 0;j+m.size()-1 < n;++j)
            if(t.substr(j,7)==m) ++cnt;
        if(cnt==1){
            cout << "YES" << endl;
            cout << t << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}
signed main(void){
    IOS;
    for(cin >> T;T--;){
        cin >> n >> s;
        solve();
    }
    return 0;
}
