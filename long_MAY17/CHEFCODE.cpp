#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,e) for(int i=s;i<e;i++)
#define repr(i,e,s) for(int i=e;i>s;i--)

long int mod=1000000000;
long int arr[35];


int rec(int index, int n, int prod, int N, int count, long int *a){
	if(index==n){
		if(index<N/2)
			a[count]=prod;
		else
			a[count]=prod;
		//cout<<prod<<" "<<count<<"\n";
		return count+1;
	}
	count=rec(index+1,n,prod,N,count,a);
	count=rec(index+1,n,(prod*arr[index])%mod,N,count,a);
	return count;
}
int search(long int a[], int val, int n){
	int l,h,mid;
	l=0;
	h=n;
	mid=(l+h)/2;
	while(l<=h){
		if(a[mid]<val) l=mid+1;
		if(a[mid]>val)	h=mid-1;
		if(a[mid]==val) break;
		cout<<"helo";
	}

	if(a[mid]==val)
		return mid;
	return l;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	long int k;
	cin>>n>>k;
	for(int t=0;t<n;t++){
		cin>>arr[t];
	}
	int r=pow(2,n);
	int p=pow(2,n/2);
	long int a1[p],a2[p];
	rec(0,n/2,1,n,0,a1);
	//cout<<"\n";
	rec(n/2,n,1,n,0,a2);
	//rep(i,0,p) cout<<a1[i]<<" ";
	//cout<<"hello";

	sort(a1,a1+p);
	sort(a2,a2+p);

	long int temp=1;
	int res=0;
	while(a1[temp]<=k){
		long int cur=k/a1[temp];
		int index = search(a2,cur,p);
		res+=index-1;
		temp++;

	}
	cout<<res;
	return 0;
}
