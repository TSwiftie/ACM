#include <cctype>
#include <cstdio>
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int judgeNum(string a,string b){
    if(a==b) return 0;
    if(a.size()==b.size()){
        for(int i = 0;i < SZ(a);++i){
            if(a[i]==b[i]) continue;
            else if(a[i] < b[i]) return -1;
            else if(a[i] > b[i]) return 1;
        }
    }else if(a.size() < b.size()) return -1;
    else if(a.size() > b.size()) return 1;
}
signed main(void){
    string a, b;cin >> a >> b;
    int la = a.size(),lb = b.size(),len = min(la,lb);
    for(int i = 0;i < len;++i){
        if(isalpha(a[i]) && isalpha(b[i]) && a[i]==b[i]) continue;
        if(isalpha(a[i]) && isalpha(b[i]) && a[i] > b[i]) { puts(">");return 0; }
        if(isalpha(a[i]) && isalpha(b[i]) && a[i] < b[i]) { puts("<");return 0; }
        if(isdigit(a[i]) && isdigit(b[i])){
            int res = judgeNum(a.substr(i,la-i-1), b.substr(i,lb-i-1));
            if(res==0) { puts("=");return 0; }
            else if(res==-1) { puts("<");return 0; }
            else if(res==1) { puts(">");return 0; }
        }
    }
    return 0;
}
