/************************************************************
	> File Name: Tarjan.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 15 Jun 2020 10:46:02 AM CST
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
vi G[N];
int dfn[N],low[N],idx,Stack[N],tp;
bool InStack[N];
int block[N],scc;
int sz[N];
void Tarjan(int u){
	low[u] = dfn[u] = ++idx;
	Stack[++tp] = u;
	InStack[u] = true;
	for(int v : G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u] = low[v] > low[u] ? low[u] : low[v];
		}else if(InStack[v] && low[u] < dfn[v])
			low[u] = dfn[v];
	}
	if(dfn[u]==low[u]){
		++scc;
		int v = Stack[tp];
		while(v != u){
			block[v] = scc;
			++sz[scc];
			InStack[v] = false;
			v = Stack[--tp];
		}
	}
}
signed main(void){
	return 0;
}
