/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 08 Aug 2020 04:29:22 PM CST
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
const int N = 1e5+5;
int t, n, p[N<<1], a[N];
bool vis[N];
signed main(void){
    IOS;
    for(cin >> t;t--;){
        cin >> n;
        int mx = 0;
        vi ind;
        for(int i = 1;i <= n<<1;++i){
            cin >> p[i];
            if(p[i] > mx){
                mx = p[i];
                ind.push_back(i);
            }
        }
        ind.push_back(2*n+1);
        vi lens;
        for(int i = 1;i < SZ(ind);++i) lens.push_back(ind[i]-ind[i-1]);
        sort(all(lens));
        fill(vis,vis+1+n,false);
        vis[0] = true;
        int m = lens.size();
        for(int k = 0;k < m;++k){
            int r = k;
            while(r < m && lens[r]==lens[k]) ++r;
            fill(a,a+n+1,0);
            for(int i = lens[k];i <= n;++i){
                if(!vis[i] && vis[i-lens[k]] && a[i-lens[k]] < r-k){
                    a[i] = a[i-lens[k]]+1;
                    vis[i] = true;
                }
            }
            k = r-1;
        }
        cout << (vis[n] ? "YES" : "NO") << endl;
    }
    return 0;
}
