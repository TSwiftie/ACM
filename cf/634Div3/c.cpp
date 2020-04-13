/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 13 Apr 2020 10:38:48 PM CST
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
int n,a[N];
int cnt[N];
set<int>s;
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i),cnt[a[i]]++,s.insert(a[i]);
		int ans = 0;
		for(int i = 1;i <= n;i++){
			int now;
			if(cnt[a[i]]==SZ(s)-1) now = cnt[a[i]];
			else if(cnt[a[i]] > SZ(s)-1) now = min(cnt[a[i]]-1,SZ(s));
			else now = cnt[a[i]];
			ans = max(ans,now);
		}
		printf("%d\n",ans);
		memset(cnt,0,sizeof cnt);
		s.clear();
	}
	return 0;
}
