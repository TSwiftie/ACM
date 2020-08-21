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
const int N = 2e5+10;
int n, m, k, mx, top, su[N];
struct node{ int a,b,c,cnt,ans; }s1[N],s2[N];
struct BitTree{
    int tr[N];
    void add(int o,int v){ while(o <= mx){ tr[o] += v;o += lowbit(o); } }
    int ask(int o,int ans = 0){ while(o){ ans += tr[o];o -= lowbit(o); } return ans; }
}bit;
bool cmp1(node x,node y){
    if(x.a==y.a){
        if(x.b==y.b) return x.c < y.c;
        else return x.b < y.b;
    }
    else return x.a < y.a;
}
bool cmp2(node x,node y){
    if(x.b==y.b) return x.c < y.c;
    else return x.b < y.b;
}
void cdq(int l,int r){
    if(l+1==r) return ;
    int mid = (l+r)>>1;
    cdq(l,mid);cdq(mid,r);
    sort(s2+l,s2+mid,cmp2);sort(s2+mid,s2+r,cmp2);
    int i = mid, j = l;
    while(i < r){
        while(s2[i].b >= s2[j].b && j < mid){ bit.add(s2[j].c,s2[j].cnt);++j; }
        s2[i].ans += bit.ask(s2[i].c);
        ++i;
    }
    for(int i = l;i < j;++i) bit.add(s2[i].c,-s2[i].cnt);
}
signed main(void){
    scanf("%d%d",&n,&k);mx = k;
    for(int i = 1;i <= n;++i){ scanf("%d%d%d",&s1[i].a,&s1[i].b,&s1[i].c); }
    sort(s1+1,s1+1+n,cmp1);
    for(int i = 1;i <= n;++i){
        ++top;
        if(s1[i].a!=s1[i+1].a||s1[i].b!=s1[i+1].b||s1[i].c!=s1[i+1].c){
            ++m;
            s2[m] = s1[i];
            s2[m].cnt = top;
            top = 0;
        }
    }
    cdq(1,m+1);
    for(int i = 1;i <= m;++i) su[s2[i].ans+s2[i].cnt] += s2[i].cnt;
    for(int i = 1;i <= n;++i) printf("%d\n",su[i]);
    return 0;
}
