/************************************************************
	> File Name: 2165.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 03:50:17 PM CST
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
const int N = 55;
int n;
int a[N],s[N];
int ans,sum;
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",a+i);
		s[i] = s[i-1] + a[i];
		sum += a[i];
	}
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			if(s[j]-s[i]==sum/2) ans++;
	printf("%d\n",ans*(ans-1)/2);
	return 0;
}
