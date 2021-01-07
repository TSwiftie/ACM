/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 29 Jun 2020 02:15:15 PM CST
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
pair<int,string>a[3010];
int ans[3010],n;
signed main(void){
    cin >> n;
    for(int i = 0;i < n;++i) 
        cin >> a[i].second >> a[i].first;
    sort(a,a+n);
    for(int i = 0;i < n;++i){
        int len = i-a[i].first;
        if(len < 0){
            cout << -1 << endl;
            return 0;
        }
        ans[i] = len;
        for(int j = 0;j < i;++j)
            if(ans[j] >= ans[i])
                ++ans[j];
    }
    for(int i = 0;i < n;++i) 
        cout << a[i].second << " " << 3000+ans[i] << endl;
    return 0;
}
