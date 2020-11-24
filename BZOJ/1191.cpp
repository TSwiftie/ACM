/************************************************************
	> File Name: 1191.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com
	> Created Time: Fri 17 Apr 2020 01:56:32 PM CST
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
const int N = 1e3+5;
bool mp[N][N],vis[N];
int linker[N];
int n, m;
bool dfs(int u){
	for(int v = 0;v < n;v++){
		if(!vis[v]&&mp[u][v]){
			vis[v] = true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int a, b;
		scanf("%d%d",&a,&b);
		mp[i][a] = mp[i][b] = true;
	}
	memset(linker,-1,sizeof linker);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		memset(vis,false,sizeof vis);
		if(dfs(i)) ans++;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
