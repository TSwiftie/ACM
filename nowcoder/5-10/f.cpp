/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 10 May 2020 02:21:28 PM CST
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
const int N = 2e5+10;
int a[N];
signed main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1,l,r;i <= m;i++){
		scanf("%d%d",&l,&r);
		a[l]++;a[r+1]--;
	}
	for(int i = 1;i <= n;i++)
		a[i] += a[i-1];
	LL ans = 0;
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++)
		ans += 1LL*a[i]*i;
	printf("%lld\n",ans);
	return 0;
}
