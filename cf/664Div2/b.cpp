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
vector<pii>ans;
signed main(void){
    int n, m, Sx, Sy;
    scanf("%d%d%d%d",&n,&m,&Sx,&Sy);
    ans.push_back(pii(Sx,Sy));
    bool mark = false;
    for(int i = Sx;i <= n;++i){
        if(!mark){
            for(int j = 1;j < Sy;++j){
                ans.push_back(pii(i,j));
            }
            if(i!=Sx) ans.push_back(pii(i,Sy));
            for(int j = Sy+1;j <= m;++j){
                ans.push_back(pii(i,j));
            }    
        }else{
            for(int j = m;j > Sy;--j){
                ans.push_back(pii(i,j));
            }
            if(i!=Sx) ans.push_back(pii(i,Sy));
            for(int j = Sy-1;j >= 1;--j){
                ans.push_back(pii(i,j));
            }
        }
        mark = !mark;
    }
    for(int i = 1;i < Sx;++i){
        if(!mark){
            for(int j = 1;j < Sy;++j){
                ans.push_back(pii(i,j));
            }
            if(i!=Sx) ans.push_back(pii(i,Sy));
            for(int j = Sy+1;j <= m;++j){
                ans.push_back(pii(i,j));
            }    
        }else{
            for(int j = m;j > Sy;--j){
                ans.push_back(pii(i,j));
            }
            if(i!=Sx) ans.push_back(pii(i,Sy));
            for(int j = Sy-1;j >= 1;--j){
                ans.push_back(pii(i,j));
            }
        }
        mark = !mark;
    }
    for(pii i : ans){
        printf("%d %d\n",i.first,i.second);
    }
    return 0;
}
