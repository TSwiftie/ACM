/************************************************************
	> File Name: 2365.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 13 May 2020 10:51:00 AM CST
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
const int N = 5010;
int f[N],t[N],c[N],n,S,q[N],l,r;
signed main(void){
	scanf("%d%d",&n,&S);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",t+i,c+i);
		t[i] += t[i-1];
		c[i] += c[i-1];
	}
	memset(f,INF,sizeof f);
	f[0] = 0;
	l = r = 1;
	for(int i = 1;i <= n;i++){
		while(l < r && f[q[l+1]]-f[q[l]] <= (S+t[i])*(c[q[l+1]]-c[q[l]])) l++;
		f[i] = f[q[l]]+t[i]*c[i]+S*c[n]-c[q[l]]*(S+t[i]);
		while(l < r && (f[i]-f[q[r]])*(c[q[r]]-c[q[r-1]]) <= (f[q[r]]-f[q[r-1]])*(c[i]-c[q[r]])) r--;
		q[++r] = i;
	}
	printf("%d\n",f[n]);
	return 0;
}
