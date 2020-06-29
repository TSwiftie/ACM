/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 29 Jun 2020 08:56:29 AM CST
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
//mt19937 rnd(time(0));
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
int t,n;
char ch[55];
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        stack<char>st;
        scanf("%s",ch+1);
        for(int i = 1;i <= n;++i){
            if(st.empty()) st.push(ch[i]);
            else if(st.top()=='('&&ch[i]==')') st.pop();
            else st.push(ch[i]);
        }
        printf("%d\n",SZ(st)/2);
    }
    return 0;
}
