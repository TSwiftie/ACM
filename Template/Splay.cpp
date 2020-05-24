/************************************************************
	> File Name: Splay.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 09:00:25 PM CST
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
int ch[N][2],cnt[N],sz[N],fa[N],val[N],rt,tot;
void maintain(int o){
	sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + cnt[o];
}
bool chk(int o){
	return o==ch[fa[o]][1];
}
void clear(int o){
	ch[o][0] = ch[o][1] = fa[o] = val[o] = sz[o] = cnt[o] = 0;
}
void rotate(int o){
	int op = fa[o],opp = fa[op],k = chk(o),v = ch[o][k^1];
	ch[o][k^1] = op,ch[op][k] = v,ch[opp][chk(op)] = o;
	fa[o] = opp,fa[op] = o,fa[v] = op;
	maintain(op);
	maintain(o);
}
void splay(int o,int goal = 0){
	while(fa[o]!=goal){
		int op = fa[o],opp = fa[op];
		if(opp!=goal)
			chk(o)==chk(op) ? rotate(op) : rotate(o);
		rotate(o);
	}
	if(!goal) rt = o;
}
void insert(int k){
	if(!rt){
		val[++tot] = k;
		cnt[tot]++;
		rt = tot;
		maintain(rt);
		return ;
	}
	int cur = rt, f = 0;
	while(true){
		if(val[cur]==k){
			cnt[cur]++;
			maintain(cur);
			maintain(f);
			splay(cur);
			break;
		}
		f = cur;
		cur = ch[cur][val[cur] < k];
		if(!cur){
			val[++tot] = k;
			cnt[tot]++;
			fa[tot] = f;
			ch[f][val[f] < k] = tot;
			maintain(tot);
			maintain(f);
			break;
		}
	}
}
int rk(int k){
	int res = 0,cur = rt;
	while(true){
		if(k < val[cur]) cur = ch[cur][0];
		else{
			res += sz[ch[cur][0]];
			if(k==val[cur]){
				splay(cur);
				return res+1;
			}
			res += cnt[cur];
			cur = ch[cur][1];
		}
	}
}
int kth(int k){
	int cur = rt;
	while(true){
		if(ch[cur][0] && k <= sz[ch[cur][0]]) cur = ch[cur][0];
		else{
			k -= cnt[cur] + sz[ch[cur][0]];
			if(k <= 0){
				splay(cur);
				return val[cur];
			}
			cur = ch[cur][1];
		}
	}
}
signed main(void){
	return 0;
}
