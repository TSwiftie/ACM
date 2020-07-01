#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 505;
const int INF = 0x3f3f3f3f;
int e[MAXN][MAXN];
int n, m, w, t;
signed main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&w);
		int t1, t2, t3, mark = 0;
		memset(e,INF,sizeof(e));
		for(int i = 1;i <= n;++i) e[i][i] = 0;
		for(int i = 1;i <= m;++i){
			scanf("%d%d%d",&t1,&t2,&t3);
			if(e[t1][t2]>t3)
                e[t1][t2] = e[t2][t1] = t3;
		}
		for(int i = 1;i <= w;++i){
			scanf("%d%d%d",&t1,&t2,&t3);
			e[t1][t2] = -t3;
		}		
		for(int k = 1;k <= n;++k)
			for(int i = 1;i <= n;++i){
				for(int j = 1;j <= n;++j)
					if(e[i][j]>e[i][k]+e[k][j])
						e[i][j] = e[i][k] + e[k][j];
				if(e[i][i]<0){
                    mark = 1;
                    break;
                }
			}
        printf("%s\n",mark?"YES":"NO");
	}
	return 0;
}
