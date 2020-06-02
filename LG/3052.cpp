/************************************************************
	> File Name: 3052.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 02 Jun 2020 05:13:48 PM CST
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
int n, w, a[20];
int f[1<<18],g[1<<18];
signed main(void){
	scanf("%d%d",&n,&w);
	for(int i = 1;i <= n;++i) scanf("%d",a+i);
	memset(f,127,sizeof f);
	f[0] = 1;g[0] = w;
	for(int i = 0;i < (1<<n);++i)
		for(int j = 1;j <= n;++j){
			if(i&(1<<(j-1))) continue;
			if(g[i]>=a[j] && f[i|(1<<(j-1))] >= f[i]){
				f[i|(1<<(j-1))] = f[i];
				g[i|(1<<(j-1))] = max(g[i|(1<<(j-1))],g[i]-a[j]);
			}else if(g[i] < a[j] && f[i|(1<<(j-1))] >= f[i]+1){
				f[i|(1<<(j-1))] = f[i]+1;
				g[i|(1<<(j-1))] = max(g[i|(1<<(j-1))],w-a[j]);
			}
		}
	printf("%d\n",f[(1<<n)-1]);
	return 0;
}
