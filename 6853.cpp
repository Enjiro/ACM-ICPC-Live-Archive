#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, m;
	int lucro[105][55];
	int custo[105][105];
	int tt;
	scanf("%d", &tt);
	while(tt--)
	{
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &lucro[i][j]);

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
					scanf("%d", &custo[i][j]);

		for(int j=m-2; j>=0; j--)
		{
			for(int i=0; i<n; i++)
			{
				int temp=lucro[i][j];
				for(int k=0; k<n; k++)
				{
					int viagem=custo[i][k];
					lucro[i][j]=max(lucro[i][j], temp+lucro[k][j+1]-viagem);
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++)
			ans=max(ans, lucro[i][0]);
		printf("%d\n", ans);
	}
	return 0;
}