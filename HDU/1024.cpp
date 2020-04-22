/************************************************************
	> File Name: 1024.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 02:51:07 PM CST
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
const int N = 1e6+10;
int dp1[N],a[N],dp2[N];
int ans;
signed main(void){
	int n, m;
	while(~scanf("%d%d",&m,&n)){
		for(int i = 1;i <= n;i++){
			scanf("%d",a+i);
			dp1[i] = dp2[i] = 0;
		}
		for(int i = 1;i <= m;i++){
			ans = -INF;
			for(int j = i;j <= n;j++){
				dp1[j] = max(dp1[j-1]+a[j],dp2[j-1]+a[j]);
				dp2[j-1] = ans;
				ans = max(ans,dp1[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
