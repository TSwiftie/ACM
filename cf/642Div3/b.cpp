/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 15 May 2020 02:36:36 PM CST
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
const int N = 31;
int a[N],b[N];
bool cmp(int x,int y){
	return x > y;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, k;
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		for(int i = 1;i <= n;i++)
			scanf("%d",b+i);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n,cmp);
		for(int i = 1;i <= k;i++){
			if(a[i] > b[i]) break;
			swap(a[i],b[i]);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
			ans += a[i];
		printf("%d\n",ans);
	}
	return 0;
}
