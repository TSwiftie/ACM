/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 26 Apr 2020 09:14:42 AM CST
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
const int N = 2e5+10;
int t, n, k, a[N],s[N];
signed main(void){
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++) scanf("%d",a+i);
		for(int i = 2;i < n;i++) s[i] = s[i-1] + (a[i]>a[i-1] && a[i] > a[i+1]);
		int ma = -1,id = 0;
		for(int i = 1,j = k;j <= n;i++,j++) if(s[j-1]-s[i]>ma) id = i,ma = s[j-1]-s[i];
		printf("%d %d\n",ma+1,id);
	}
	return 0;
}
