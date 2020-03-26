/************************************************************
	> File Name: 204.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 26 Mar 2020 01:57:39 PM CST
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
int a[105],n;
void func1(int x){
	for(int i = 0;i < n;i++)
		if(a[i]==x){
			printf("%d\n%d\n",i,i+1);
			return ;
		}
	printf("-1\n%d\n",n);
	return ;
}
void func2(int x){
	sort(a,a+n);
	int cnt = 0;
	for(int i = 0;i < n;i++){
		cnt++;
		if(a[i]==x){
			printf("%d\n%d\n",i,i+1);
			return ;
		}
		if(a[i]>x) break;
	}
	printf("-1\n%d\n",cnt);
	return ;
}
void func3(int x){
	int L = 0,R = n-1,cnt = 0;
	while(L <= R){
		cnt++;
		int mid = (L+R)>>1;
		if(a[mid]==x){
			printf("%d\n%d\n",mid,cnt);
			return ;
		}else if(x > a[mid]) L = mid+1;
		else R = mid-1;
	}
	printf("-1\n%d\n",cnt);
	return;
}
signed main(void){
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",a+i);
	int x;
	scanf("%d",&x);
	func1(x);
	func2(x);
	func3(x);
	return 0;
}
