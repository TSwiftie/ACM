/************************************************************
	> File Name: FFT.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 10:03:42 PM CST
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
typedef complex<double> E;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 131072;
int n, m, L;
char ch[N];
int R[N],c[N];
E a[N],b[N];
void fft(E *a,int f){
	for(int i = 0;i < n;i++) if(i < R[i]) swap(a[i],a[R[i]]);
	for(int i = 1;i < n;i<<=1){
		E wn(cos(PI/i),f*sin(PI/i));
		for(int j = 0;j < n;j+=(i<<1)){
			E w(1,0);
			for(int k = 0;k < i;k++,w*=wn){
				E x = a[j+k],y = w*a[j+k+i];
				a[j+k] = x+y;a[j+k+i] = x-y;
			}
		}
	}
	if(f==-1) for(int i = 0;i < n;i++) a[i] /= n;
}
signed main(void){
	scanf("%d",&n);n--;
	scanf("%s",ch);
	for(int i = 0;i <= n;i++) a[i] = ch[n-i]-'0';
	scanf("%s",ch);
	for(int i = 0;i <= n;i++) b[i] = ch[n-i]-'0';
	m = 2*n;
	for(n = 1;n <= m;n<<=1) L++;
	for(int i = 0;i < n;i++) R[i] = (R[i>>1]>>1)|((i&1)<<(L-1));
	fft(a,1);fft(b,1);
	for(int i = 0;i <= n;i++) a[i] *= b[i];
	fft(a,-1);
	for(int i = 0;i <= m;i++) c[i] = (int)(a[i].real()+0.1);
	for(int i = 0;i <= m;i++)
		if(c[i] >= 10){
			c[i+1] += c[i]/10,c[i] %= 10;
			if(i==m) m++;
		}
	for(int i = m;i >= 0;i--) printf("%d",c[i]);
	return 0;
}
