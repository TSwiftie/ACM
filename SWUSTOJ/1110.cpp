/************************************************************
	> File Name: 1110.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 25 Mar 2020 11:00:57 PM CST
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
const int N = 1e6+6;
int a[N],ans;
signed main(void){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 1;i < n;i++){
			if(a[i] > a[i+1]){
				flag = true;
				swap(a[i],a[i+1]);
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
