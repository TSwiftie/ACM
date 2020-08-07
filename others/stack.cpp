/************************************************************
	> File Name: stack.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 07 Aug 2020 11:59:10 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e5+10;
char ch[N];
stack<char>st;
signed main(void){
    scanf("%s",ch+1);int n = strlen(ch+1);
    for(int i = 1;i <= n;++i){
        if(st.empty() || ch[i]=='{' || ch[i]=='[' || ch[i]=='(') st.push(ch[i]);
        else if((st.top()=='('&&ch[i]==')')||(st.top()=='['&&ch[i]==']')||(st.top()=='{'&&ch[i]=='}')) st.pop();
        else st.push(ch[i]);
    }
    puts(st.size()?"False":"True");
    return 0;
}
