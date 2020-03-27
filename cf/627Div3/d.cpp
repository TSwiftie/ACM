/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 10:27:03 AM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int n,a[7<<15];
ll ans;
signed main(void){
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",a+i);
	for(int i = 0,x;i < n;i++)
		scanf("%d",&x),a[i]-=x;
	sort(a,a+n);
	for(int i = n;i > 0;i--)
		if(a[n-i] + a[n-1] > 0) ans+=i-1,n--;
	printf("%lld\n",ans);
	return 0;
}
