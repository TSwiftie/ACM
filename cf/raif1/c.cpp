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
const char *INPUT = "/home/ts/code/in.in";
string s;
signed main(void){
    IOS;int t;for(cin >> t;t--;){
        cin >> s;stack<char>st;
        for(int i = 0;i < SZ(s);++i){
            if(s[i]=='A') st.push(s[i]);
            else if(!st.empty() && st.top()=='A') st.pop();
            else st.push(s[i]);
        }
        int ans = 0;
        while(!st.empty() && st.top()=='A') ++ans,st.pop();
        cout << ans + (SZ(st) & 1) << endl;
    }
    return 0;
}
