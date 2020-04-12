/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 12 Apr 2020 10:11:57 PM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e5+10;
ll a[N];
signed main(void){
	int t,n;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld",a+i);
		}
		sort(a+1,a+1+n);
		int mid = ceil(1.0*n/2),l,r;
		if(n&1) printf("%lld ",a[mid]),l = mid-1,r = mid+1;
		else l = mid,r = mid+1;
		for(;r <= n;r++,l--)
			printf("%lld %lld ",a[l],a[r]);
		puts("");
	}
	return 0;
}
