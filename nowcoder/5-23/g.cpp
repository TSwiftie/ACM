/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 23 May 2020 02:30:01 PM CST
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
set<int>s;
map<int,int>mp;
int n,a[N],b[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d",a+i,b+i);
			if(a[i]==b[i]) continue;
			s.insert(a[i]);
			s.insert(b[i]);
			mp[a[i]]++;
			mp[b[i]]--;
		}
		printf("%d ",SZ(s));
		int ans = 0,front = 0;
		for(auto it = mp.begin();it!=mp.end();it++){
			ans = max(ans,it->second+front);
			front += it->second;
		}
		printf("%d\n",ans);
		s.clear();mp.clear();
	}
	return 0;
}
