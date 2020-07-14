/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 09时30分55秒
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int N = 1e5+10;
int a[N];
bool cmp(const int &x,const int &y){
    return x > y;
}
signed main(void){
    IOS;
    int t;
    for(cin >> t;t--;){
        int n, x;
        cin >> n >> x;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        sort(a+1,a+1+n,cmp);
        int ans = 0,last = 0;
        for(int i = 1;i <= n;++i){
            if(a[i] >= x) ++ans,last = i;
            else{
                int cnt = ceil(1.0*x/a[i]);
                if(i-cnt >= last) ++ans,last = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
