#include<iostream>
#include<string.h>
using namespace std;
int i=3,k=0;
char a[100][100];
int num,flag=0;
string data[100];
void trailing(char f);
void leading(char d){
	for(int i=0;i<k;i++){
		if(a[i][0]==d){
			for(int j=0;j<k;j++){
				if(a[j][0]==a[i][3]){
					flag=1;
				}
			}
		if(flag){
			if(strlen(a[i])==4){
				leading(a[i][3]);
			}
			else{
				cout<<a[i][4];
			}
		}
		else{
			cout<<a[i][3];
		}
		flag=0;
		}
	}
	
}
void trailing(char f){
	for(int i=0;i<k;i++){
		if(a[i][0]==f){
			for(int j=0;j<k;j++){
				if(a[j][0]==a[i][strlen(a[i])-1]){
					flag=1;
				}
			}
		if(flag){
			if(strlen(a[i])==4){
				trailing(a[i][strlen(a[i])-1]);
			}
			else{
				cout<<a[i][strlen(a[i])-2];
			}
		}
		else{
			cout<<a[i][strlen(a[i])-1];
		}
		flag=0;
		}
	}
	
}
int  main(){
	cout<<"Enter the number of productions";cin>>num;
	cout<<"Enter the productions \'e as in epsilon\'";
	for(int i=0;i<num;i++){
        cin>>data[i];
	}
	for(int x=0;x<num;x++){
    string s=data[x];
	for(int j=3;j<s.length();j++){
    a[k][0]=s[0];
    a[k][1]=s[1];
    a[k][2]=s[2];
	while(s[j]!='|'&&j<s.length()){
		a[k][i++]=s[j++];
	}
	i=3;
	k++;
	}
	}
	for(int i=0;i<num;i++){
		cout<<"LEADING("<<data[i][0]<<")={";
		leading(data[i][0]);
		cout<<"}\n";
	}
	for(int i=0;i<num;i++){
		cout<<"TRAILING("<<data[i][0]<<")={";
		trailing(data[i][0]);
		cout<<"}\n";
	}
	return 0;
}
