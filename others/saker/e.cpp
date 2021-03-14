#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
char s[N];
signed main(void){
	int n;
    scanf("%lld %s",&n,s);
	int a=0,b=0,len = strlen(s),ans=0;
	for(int i = 0;i < len;++i) {
        int c=s[i]-'0';
		if(n>=c){
			n-=c;
			if(c==2) b++;
			else a++;
		}else{
			if(b){
				b--,n+=2;
				if(c==1) a++,n-=1;
				else b++,n-=2;
			}
		}
		ans+=a+b; 
	}
    printf("%lld\n",ans);
	return 0;
}
