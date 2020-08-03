/************************************************************
	> File Name: 2761.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 03 Aug 2020 10:26:17 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
struct pack{ int f1,f2,b1,b2,t; }p[505];
int n, m, fir, dis[1<<22], tag;
queue<int>q;
bool exi[1<<22];
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline int gtag(){
    char ch = getchar();
    while(ch!='+'&&ch!='-'&&ch!='0') ch = getchar();
    if(ch=='+') return 1;
    if(ch=='-') return 2;
    return 0;
}
void spfa(){
    memset(dis,0x7f,sizeof dis);
    dis[fir] = 0;
    q.push(fir);
    while(q.size()){
        int u = q.front();
        for(int i = 1;i <= m;++i){
            if((u&p[i].b1)==p[i].b1 && (u&p[i].b2)==0){
                int v = ((u|p[i].f1)|p[i].f2)^p[i].f1;
                if(dis[u] + p[i].t < dis[v]){
                    dis[v] = dis[u] + p[i].t;
                    if(!exi[v]){ q.push(v);exi[v] = true; }
                }
            }
        }
        exi[u] = false;
        q.pop();
    }
}
signed main(void){
    n = read();m = read();
    for(int i = 1;i <= m;++i){
        p[i].t = read();
        for(int j = 1;j <= n;++j){
            tag = gtag();
            if(tag==1) p[i].b1|=(1<<j-1);
            if(tag==2) p[i].b2|=(1<<j-1);
        }
        for(int j = 1;j <= n;++j){
            tag = gtag();
            if(tag==1) p[i].f2|=(1<<j-1);
            if(tag==2) p[i].f1|=(1<<j-1);
        }
    }
    fir = (1<<n)-1;
    spfa();
    if(dis[0]==dis[(1<<22)-1]) printf("0\n");
    else printf("%d\n",dis[0]);
    return 0;
}
