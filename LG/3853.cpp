/************************************************************
	> File Name: 3853.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 02:52:54 PM CST
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
const int N = 1e5+10;
int a[N];
int l, n, k;
bool check(int dis){
	int cnt = 0;
	for(int i = 0;i <= n;i++){
		if(a[i+1]-a[i] > dis){
			cnt += (a[i+1]-a[i])/dis;
			if((a[i+1]-a[i])%dis==0) cnt--;
		}
		if(cnt > k) return false;
	}
	return true;
}
signed main(void){
	scanf("%d%d%d",&l,&n,&k);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	int L = 0,R = 10000006;
	a[0] = 0,a[n+1] = l;
	while(L < R){
		int mid = (L+R)>>1;
		if(check(mid)) R = mid;
		else L = mid+1;
	}
	printf("%d\n",L);
	return 0;
}
