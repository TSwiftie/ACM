/************************************************************
	> File Name: 195.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 25 Mar 2020 10:37:28 PM CST
************************************************************/

#include <cstring>
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
const int N = 1003;
int n;
int v[N],w[N],ans[N];
int dp[N];
bool path[N][N];
int V;
signed main(void){
	while(~scanf("%d%d",&V,&n)){
		memset(dp, 0, sizeof dp);
		memset(path, false, sizeof path);
		for(int i = 1;i <= n;i++)
			scanf("%d%d",w+i,v+i);
		for(int i = 1;i <= n;i++)
			for(int j = V;j >= w[i];j--)
				if(dp[j-w[i]] + v[i] > dp[j]){
					dp[j] = dp[j-w[i]] + v[i];
					path[i][j] = true;
				}
		int k = 0,res = dp[V];
		for(int i = n;i >= 1;i--)
			if(path[i][V]){
				ans[++k] = i;
				V -= w[i];
			}
		if(!k) printf("0\n");
		else{
			printf("%d\n",res);
			for(int i = k;i > 0;i--)
				printf("%d%c",ans[i]," \n"[i==1]);
		}
	}
	return 0;
}
