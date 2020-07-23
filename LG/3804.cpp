/************************************************************
	> File Name: 3804.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 23 Jul 2020 10:33:21 AM CST
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
const int N = 2e6+5;
char ch[N];
int siz[N];
ll ans;
struct Suffix_Automaton{
    int nxt[N<<1][26],fa[N<<1],l[N<<1];
    int last,cnt;
    int cntA[N],A[N];
    Suffix_Automaton(){
        clear();
    }
    void clear(){
        last = cnt = 1;
        fa[1] = l[1] = 0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while(*s){
            add(*s-'a');++s;
        }
    }
    void add(int c){
        int p = last, np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p] + 1; last = np;
        while(p&&!nxt[p][c]) nxt[p][c] = np,p = fa[p];
        if(!p) fa[np] = 1;
        else{
            int q = nxt[p][c];
            if(l[q] == l[p] + 1) fa[np] = q;
            else{
                int nq = ++cnt;
                l[nq] = l[p] + 1;
                memcpy(nxt[nq],nxt[q],sizeof nxt[q]);
                fa[nq] = fa[q];fa[np] = fa[q] = nq;
                while(nxt[p][c] == q) nxt[p][c] = nq,p = fa[p];
            }
        }
        siz[np] = 1;
    }
    void build(){
        memset(cntA,0,sizeof cntA);
        for(int i = 1;i <= cnt;++i) ++cntA[l[i]];
        for(int i = 1;i <= cnt;++i) cntA[i] += cntA[i-1];
        for(int i = cnt;i >= 1;--i) A[cntA[l[i]]--] = i;
        for(int i = cnt;i;--i){
            int p = A[i];
            siz[fa[p]] += siz[p];
            if(siz[p] > 1) ans = max(ans,1ll*siz[p]*l[p]);
        }
    }
}sam;
signed main(void){
    scanf("%s",ch+1);
    sam.init(ch+1);
    sam.build();
    printf("%lld\n",ans);
    return 0;
}
