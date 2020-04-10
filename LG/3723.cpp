/************************************************************
	> File Name: 3723.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 10 Apr 2020 03:06:33 PM CST
************************************************************/

#include <complex>
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
typedef complex<double> E;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e6+10;
int n, m, lim, a[N], b[N];
ll ans, t, res[N], mx;
int rev[N];
void fft(E *a,int f){
	for(int i = 1;i < lim;i++) if(i < rev[i]) swap(a[i],a[rev[i]]);
	for(int n = 1;n < lim;n <<= 1){
		E wn(cos(PI/n),f*sin(PI/n));
		for(int i = 0;i < lim;i += (n<<1)){
			E w(1,0);
			for(int k = 0;k < n;k++,w*=wn){
				E x = a[i+k],y = w*a[i+k+n];
				a[i+k] = x+y;a[i+k+n] = x-y;
			}
		}
	}
}
void trans(int *a,int *b,int n,int m,ll *ans){
	static E f[N],g[N];
	lim = 1;
	int l = 0;
	for(int i = 1;i <= n;i++) f[i] = a[i];
	for(int i = 1;i <= m;i++) g[i] = b[i];
	for(n += m;lim <= n+m;lim <<= 1) l++;
	for(int i = 1;i < lim;i++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(l-1));
	fft(f,1);fft(g,1);
	for(int i = 0;i < lim;i++) f[i] *= g[i];
	fft(f,-1);
	for(int i = 1;i <= n;i++)
		ans[i] = (ll)(0.5+f[i].real()/lim);
}
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1;i <= n;i++) scanf("%d",b+i);
	for(int i = 1;i <= n;i++){
		ans += a[i]*a[i]+b[i]*b[i];
		t += b[i]-a[i];
	}
	int c1 = floor(t*1.0/n),c2 = ceil(t*1.0/n);
	ans += min(n*c1*c1-2*c1*t,n*c2*c2-2*c2*t);
	for(int i = 1;i <= n;i++) b[i+n] = b[i];
	reverse(a+1,a+1+n);
	trans(a,b,n,n<<1,res);
	ll tmp = 0;
	for(int i = 0;i <= n;i++) tmp = max(tmp,res[i+n+1]);
	ans -= (tmp<<1);
	printf("%lld\n",ans);
	return 0;
}
