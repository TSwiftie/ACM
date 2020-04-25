/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 25 Apr 2020 08:44:36 PM CST
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
int t, n, k;
int a[N],s[N];
signed main(void){
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&k);
		s[0] = 0,a[0] = -1,a[n+1] = -1;
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		for(int i = 1;i < n;i++){
			if(a[i] > a[i-1] && a[i] > a[i+1])
				s[i] = s[i-1] + 1;
			else s[i] = s[i-1];
		}
		int ans = 0,ansIndex = 0;
		for(int i = 1;i <= n-k+1;i++){
			int now = s[i+k-1]-s[i-1];
			if(a[i]>a[i-1]&&a[i]>a[i+1]) now--;
			if(a[i+k-1]>a[i+k-2]&&a[i+k-1]>a[i+k]) now--;
			if(now > ans){
				ans = now;
				ansIndex = i;
			}
		}
		printf("%d %d\n",ans+1,ansIndex);
	}
	return 0;
}
