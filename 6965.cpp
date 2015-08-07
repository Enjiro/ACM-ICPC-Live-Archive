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
	int n;
	vector<int>vet;
	while(scanf("%d", &n) && n!=-1)
	{
		int x;
		while(n--)
		{
			scanf("%d", &x);
			vet.pb(x);
		}
		sort(vet.begin(), vet.end());

		int t=vet.size();
		if(t&1)
			printf("%d\n", vet[t>>1]);
		else
		{
			int y= (vet[(t>>1)] + vet[(t>>1)-1])>>1;
			printf("%d\n", y);
		}

		vet.clear();
	}
	return 0;
}