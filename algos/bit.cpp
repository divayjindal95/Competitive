#include <bits/stdc++.h>

#define rep(i,s,e) for(int i=s;i<e;i++)
#define repr(i,e,s) for(int i=e;i>s;i--)

using namespace std;

int N=100000;
int a[100005],bit[100005];

void update(int n, int val, int index){
	int i=index;
	while(i<=n){
		bit[i]+=val;
		i = i + ( i & ( -i ))	;
	}
}

void make_tree(int n){
	for(int i=1;i<n+1;i++){
		update(n,a[i],i);
	}
}

int getsum(int i, int j){
	int sum1=0,sum2=0;
	int k=i;
	while(k>0){
		sum1+=bit[k];
		k=k-(k&(-k));
	}

	k=j;
	while(k>0){
		sum2+=bit[k];
		k=k-(k&(-k));
	}
	return sum2-sum1;
}

int main(){
	std::ios::sync_with_stdio(false);
	//int tc;
	//cin>>tc;
	//for(int t=0;t<tc;t++){

	//}

	int n;
	cin>>n;
	rep(i,1,n+1) cin>>a[i];
	memset(bit,0,sizeof(bit));
	make_tree(n);
	rep(i,1,n+1)	cout<<a[i]<<" ";
	cout<<"\n";
	rep(i,1,n+1)	cout<<bit[i]<<" ";
	getsum(2,5);
	return 0;
}