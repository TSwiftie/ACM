/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 08 Aug 2020 06:50:22 PM CST
************************************************************/
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
const int N = 2e5+10;
char ch[N];
int _;
vi pos[10];
signed main(void){
    for(scanf("%d",&_);_--;){
        scanf("%s",ch+1);
        int n = strlen(ch+1),Max = 0;
        for(int i = 1;i <= n;++i) pos[ch[i]-'0'].push_back(i),Max = max(Max,SZ(pos[ch[i]-'0']));
        int ans = n-Max;
        for(int i = 0;i < 9;++i){
            for(int j = i+1;j < 10;++j){
                vi tmp;
                for(int k = 1;k <= n;++k)
                    if(ch[k]-'0'==i||ch[k]-'0'==j) tmp.push_back(ch[k]-'0');
                if(!SZ(tmp)) continue;
                int pre = tmp[0],cnt = 1;
                for(int k = 1;k < SZ(tmp);++k){
                    if(tmp[k]==pre) continue;
                    else ++cnt,pre = tmp[k];
                }
                if(cnt&1) --cnt;
                ans = min(ans,n-cnt);
            }
        }
        printf("%d\n",ans);
        for(int i = 0;i < 10;++i) pos[i].clear();
    }
    return 0;
}
