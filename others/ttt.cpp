/************************************************************
	> File Name: ttt.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 03 Jul 2020 07:43:44 PM CST
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
struct node{
    int id,sco,pot;
    string name;
}s[1003];
bool cmp(node a,node b){
    return a.sco > b.sco;
}
signed main(void){
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> s[i].id >> s[i].name >> s[i].sco >> s[i].pot;
    stable_sort(s+1,s+1+n,cmp);
    int a, b;
    cin >> a >> b;
    for(int i = a;i <= b;++i)
        cout << s[i].id << " " << s[i].name << " " << s[i].sco << " " << s[i].pot << endl;
    return 0;
}
