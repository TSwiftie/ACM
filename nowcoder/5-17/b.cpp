/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 17 May 2020 01:16:55 PM CST
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
const int mod = 998244353;
ll f[N],a[N];
int n,m;
signed main(void){
	f[1] = 1,f[2] = 3;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",a+i);
		if(i<=2) continue;
		f[i] = (3*f[i-1]%mod + 2*f[i-2]%mod)%mod;
	}
	return 0;
}
