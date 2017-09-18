#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s1,s2;
		cin>>s1>>s2;
		int flag=0;
		int a1[26],a2[26];
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a1));

		for(int j=0;j<s1.length();j++){
			a1[s1[j]-'a']++;
			a2[s2[j]-'a']++;
		}
		for(int j=0;j<26;j++){
			if(a1[j]>1&&a2[j]==0)
				flag=1;
		}
		int c1=0,c2=0,c=0;
		for(int j=0;j<26;j++){
			if(a1[j]>0&&a2[j]>0)
				c++;
			if(a1[j]>0)
				c1++;
			if(a2[j]>0)
				c2++;
		}
		if(c1>c2&&c2==c)
			flag=1;
		if(flag==1)
			cout<<"A\n";
		else
			cout<<"B\n";
	}
	//cout<<"hello";
	return 0;
	
}