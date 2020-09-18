#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
int n,q;multiset<int>ms;set<int>pos;
void add(int p){
    auto it = pos.insert(p).first;
    if(next(it) != pos.end()) ms.insert(*next(it)-p);
    if(it!=pos.begin()){
        ms.insert(p-*prev(it));
        if(next(it)!=pos.end()) ms.erase(ms.find(*next(it)-*prev(it)));
    }
}
void erase(int p){
    auto it = pos.find(p);
    if(next(it)!=pos.end()) ms.erase(ms.find(*next(it)-p));
    if(it!=pos.begin()){
        ms.erase(ms.find(p-*prev(it)));
        if(next(it)!=pos.end()) ms.insert(*next(it)-*prev(it));
    }
    pos.erase(it);
}
int calc(){
    if(pos.size() <= 2) return 0;
    return *(--pos.end()) - *pos.begin() - *(--ms.end());
}
signed main(void){
    IOS;cin >> n >> q;
    for(int i = 0,p;i < n;++i) cin >> p,add(p);
    cout << calc() << endl;
    while(q--){
        int op,x;cin >> op >> x;
        if(op==0) erase(x);
        else add(x);
        cout << calc() << endl;
    }
    return 0;
}
