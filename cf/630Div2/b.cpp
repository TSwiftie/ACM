/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 09:29:39 AM CST
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
const int N = 1e3+10;
int ans[N],a[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		int tot = 1;
		for(int i = 2;i <= 1000;i++){
			bool mark = false;
			for(int j = 1;j <= n;j++)
				if(a[j]%i==0&&!ans[j])
					ans[j] = tot,mark = true;
			if(mark) tot++;
		}
		printf("%d\n",tot-1);
		for(int i = 1;i <= n;i++)
			printf("%d%c",ans[i]," \n"[i==n]);
		memset(ans,0,sizeof ans);
	}
	return 0;
}
