/************************************************************
	> File Name: 3338.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 10 Apr 2020 01:34:28 PM CST
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
const int N = 262144;
int n, m, L;
int rev[N];
E f[N],rf[N],g[N],e1[N],e2[N];
void fft(E *a,int f){
	for(int i = 0;i < n;i++) if(i > rev[i]) swap(a[i],a[rev[i]]);
	for(int i = 1;i < n;i <<= 1){
		E wn(cos(PI/i),f*sin(PI/i));
		for(int j = 0;j < n;j += (i<<1)){
			E w(1,0);
			for(int k = 0;k < i;k++,w *= wn){
				E x = a[j+k],y = w*a[j+k+i];
				a[j+k] = x+y;
				a[j+k+i] = x-y;
			}
		}
	}
	if(f==-1)
		for(int i = 0;i < n;i++) a[i]/=n;
}
signed main(void){
	scanf("%d",&n);
	n--;
	for(int i = 0;i <= n;i++){
		double x;
		scanf("%lf",&x);
		f[i] = x;
		rf[n-i] = x;
	}
	for(int i = 1;i <= n;i++) g[i] = (1.0/i/i);
	m = n<<1;
	for(n = 1;n <= m;n <<= 1) L++;
	for(int i = 0;i < n;i++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(L-1));
	fft(f,1);fft(g,1);fft(rf,1);
	for(int i = 0;i < n;i++) e1[i] = f[i] * g[i];
	for(int i = 0;i < n;i++) e2[i] = rf[i] * g[i];
	fft(e1,-1),fft(e2,-1);
	for(int i = 0;i <= m/2;i++)
		printf("%.3lf\n",e1[i].real()-e2[m/2-i].real());
	return 0;
}
