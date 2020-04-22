/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 12:15:34 PM CST
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
const int N = 4e5+10;
int s[N];
int a[N>>1];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, k;
		scanf("%d%d",&n,&k);
		for(int i = 0;i < n;i++)
			scanf("%d",a+i);
		for(int i = 0;i < n/2;i++){
			int x = a[i],y = a[n-i-1];
			if(x > y) swap(x,y);
			s[2]+=2;
			s[x+1]--;
			s[x+y]--;
			s[x+y+1]++;
			s[y+k+1]++;
		}
		int ans = n;
		for(int i = 2;i <= 2*k;i++){
			s[i] += s[i-1];
			ans = min(ans,s[i]);
		}
		printf("%d\n",ans);
		memset(s,0,sizeof s);
	}
	return 0;
}
