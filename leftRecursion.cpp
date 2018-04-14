#include<iostream>
#include<string.h>
using namespace std;

int main(){
	char non_terminal[10];
    char beta[10],alpha[10];
    int num;
    int i;
    char production[10][10];
    int index=3;
	cout<<"Enter the number of predictions:";
	cin>>num;
	for(i=0;i<num;i++){
	cin>>production[i];}
	
	for(i=0;i<num;i++){
		non_terminal[i]=production[i][0];
	}
	for(i=0;i<num;i++){
            if(non_terminal[i]==production[i][index]) {
                 alpha[i]=production[i][index+1];
                 while(production[i][index]!=0 && production[i][index]!='|')  {
           index++;  }
                 if(production[i][index]!=0)  {
                      beta[i]=production[i][index+1];
                      cout<<non_terminal[i]<<"->"<<beta[i]<<non_terminal[i]<<"\'\n";
                      cout<<non_terminal[i]<<"\'->"<<alpha[i]<<beta[i]<<non_terminal[i]<<"\'|"<<std::numeric_limits<double>::epsilon()<<"\n";
                        }
            }
            else
            cout<<production[i];
            index=3;     	
	}
}
