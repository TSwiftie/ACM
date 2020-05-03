/************************************************************
	> File Name: 3165.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 06:26:15 PM CST
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
int rt,sz,n,q[N];
int size[N],rev[N],ch[N][2],tag[N],fa[N];
struct node{
	int v,id;
}a[N];
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
bool cmp(const node &a,const node &b){
	return a.v==b.v ? a.id < b.id : a.v < b.v;
}
void maintain(int o){
	if(o){
		size[o] = rev[o];
		if(ch[o][0]) size[o] += size[ch[o][0]];
		if(ch[o][1]) size[o] += size[ch[o][1]];
	}
}
bool chk(int o){
	return ch[fa[o]][1]==o;
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
			chk(o)==chk(op)?rotate(op):rotate(o);
		rotate(o);
	}
	if(!goal) rt = o;
}
signed main(void){
	return 0;
}
