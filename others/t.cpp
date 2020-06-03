/************************************************************
	> File Name: t.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 03 Jun 2020 04:28:15 PM CST
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
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
bool isSqu[130];
int squ[130],tot;
signed main(void){
	for(int i = 1;i*i <= 129;++i)
		squ[++tot] = i*i,isSqu[i*i] = true;
	for(int i = 1;i <= tot;++i)
		for(int j = i+1;j <= tot;++j)
			for(int k = j+1;k <= tot;++k){
				int a = squ[i],b = squ[j],c = squ[k],d = 129-a-b-c,cnt = 0;
				if(a>15&&b>15&&c>15&&d>15){
					cnt += isSqu[a-15];
					cnt += isSqu[b-15];
					cnt += isSqu[c-15];
					cnt += isSqu[d-15];
					if(cnt==3)
						printf("%d %d %d %d\n",a,b,c,d);
				}
			}
	return 0;
}
