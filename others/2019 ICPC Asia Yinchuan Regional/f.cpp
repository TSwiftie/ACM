/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 09 Aug 2020 04:14:48 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int p = 998244353;
inline int ksm(int a,int b,int res = 1){ for(;b;a=a*a%p,b>>=1) if(b&1) res=res*a%p; return res; }
inline int get(int x){ x%=p; int inv6=ksm(6,p-2); return x*(x+1)%p*(2*x%p+1)%p*inv6%p; }
signed main(void){
    int n; scanf("%lld",&n);
    int ans = 0, inv2 = ksm(2,p-2);
    for(int i = 2;i <= n;++i){
        int res = 1;
        if(i*i>n){
            int q = n%p;
            ans = ans+(q+1)%p*(i+q)%p*(q-i%p+1+p)%p*inv2%p;
            ans = (ans-(get(n)-get(i-1))%p+p)%p;
            break;
        }
        for(int l = i,tmp = 0;l <= n;l = res,++tmp){
            res *= i;
            if(res>n){
                ans = ans+i%p*tmp*(n%p-l+1+p)%p;
                break;
            }else ans = ans+i%p*tmp*(res%p-l+p)%p;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
