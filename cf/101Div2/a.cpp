/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 11:18:11 AM CST
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
const int N = 303;
int used[300],all[303];
string st[3];
signed main(void){
	for(int i = 0;i < 3;i++)
		cin >> st[i];
	for(int i = 0;i < 2;i++)
		for(int j = 0;j < SZ(st[i]);j++)
			used[st[i][j]]++;
	for(int i = 0;i < SZ(st[2]);i++)
		all[st[2][i]]++;
	for(int i = 0;i < 260;i++){
		if(used[i]!=all[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
