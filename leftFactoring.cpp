#include<iostream>
#include<string.h>
using namespace std;
int  main(){
	string s;
	cout<<"Enter the production:";
	cin>>s;
	int i=0,k=0;
	char a[100][100];
	for(int j=3;j<s.length();j++){
	while(s[j]!='|'&&j<s.length()){
		a[k][i++]=s[j];
		j++;
	}
	i=0;
	k++;
	}
	int flag=1,x=0,y=0;
	char alpha[100][100],beta[100][100];
	for(int i=0;i<k;i++){
		int l=strlen(a[i]);
		if(flag){
			if(x==0){
				strcpy(alpha[x++],a[i]);
			}
			else if(alpha[0][0]==a[i][0]){
				strcpy(alpha[x++],a[i]);
			}
			else 
			flag=0;
		}
		if(flag==0){
			strcpy(beta[y++],a[i]);
		}
	}
	char temp[100];
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(strlen(alpha[i])<strlen(alpha[j])){
				strcpy(temp,alpha[i]);
				strcpy(alpha[i],alpha[j]);
				strcpy(alpha[j],temp);
			}		
		}
	}
	int z=0,nf=1;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(alpha[i][z]!=alpha[j][z]){
				nf=0;
			}
		}
		if(nf){
		z++;
		}
	}
	cout<<s[0]<<"->";
	for(int i=0;i<z;i++){
		cout<<alpha[0][i];
	}
	cout<<s[0]<<"\'"<<"|";
	for(int i=0;i<y;i++){
		cout<<beta[i];
		if(i<y-1)
		cout<<"|";
	}
	int flag1=0;
	cout<<"\n"<<s[0]<<"\'->";
	for(int i=0;i<x;i++){
		for(int j=z;j<strlen(alpha[i]);j++)
		{flag1=1;
		cout<<alpha[i][j];}
		if(flag1==0)
		cout<<"epsilon";
		flag1=0;
		if(i<x-1)
		cout<<"|";
	}

	return 0;
}
