/************************************************************
	> File Name: 143.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 11:01:30 AM CST
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
int cnt;
void Hanoi(int n,char a,char b,char c){
	if(n==1){
		printf("%c-->%c   ",a,c);
		if((++cnt)%5==0)
			printf("\n");
		return ;
	}
	Hanoi(n-1,a,c,b);
	printf("%c-->%c   ",a,c);
	if((++cnt)%5==0)
		printf("\n");
	Hanoi(n-1,b,a,c);
}
signed main(void){
	int n;
	while(~scanf("%d",&n)){
		if(!n) break;
		cnt = 0;
		Hanoi(n,'A','B','C');
		printf("\n");
	}
	return 0;
}
