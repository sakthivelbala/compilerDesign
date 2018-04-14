#include<iostream>
#include<string.h>
using namespace std;
int i=3,k=0;
char a[100][100];
int num,flag=0;
string data[100];
int change=0,unit=1,id;
void follow(char f);
void first(char d){
	for(int i=0;i<k;i++){
		if(d==a[i][0]){
			for(int j=0;j<num;j++){
				if(a[i][3]==data[j][0]){
					first(a[i][3]);
					flag=1;
				}
			}
			if(flag==0){
				if(change==1&&a[i][3]=='e'){
					follow(a[i][id+2]);
				}
				else
				cout<<a[i][3]<<",";
			}
			flag=0;
		}			
	}
}
void follow(char f){
	for(int i=0;i<k;i++){
		for(id=3;id<strlen(a[i]);id++){
			if(f==a[i][id]){
				for(int k=0;k<num;k++){
					if(data[k][0]==a[i][id+1]){
						first(a[i][id+1]);
						flag=1;	
					}
				}
				if(flag==0){
					cout<<a[i][id+1]<<",";
				}
				flag=0;
			}
			else if(f==a[i][id]&&id<strlen(a[i])-1){
				follow(a[i][0]);
			}
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
	for(int i=0;i<k;i++){
        cout<<a[i]<<'\n';
	}
	for(int i=0;i<num;i++){
		cout<<"FIRST("<<data[i][0]<<")={";
		first(data[i][0]);
		cout<<"\b}\n";
	}
	for(int i=0;i<num;i++){
		cout<<"FOLLOW("<<data[i][0]<<")={";
		if(unit){
					cout<<"$,";
					unit=0;
				}
		follow(data[i][0]);
		cout<<"\b}\n";
	}
	return 0;
}
