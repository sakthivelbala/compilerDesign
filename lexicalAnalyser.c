#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int isKeyword(char buffer[]){
    char keywords[34][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","printf","register","return","scanf","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;
    for(i = 0; i < 34; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}
int main(){
    char ch, buffer[20], operators[] = "+-*/%=",specialchar[]="(){};:,.!@#$%^&*";
    FILE *fp;
    int i,j=0,flag=0,op=0,ky=0,iden=0,spc=0,strcnt=0;
    fp = fopen("program.txt","r");
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF){
           for(i = 0; i < 6; ++i){
               if(ch == operators[i]){

                   printf("%c is operator\n", ch);
                   op++;}
           }
           for(i = 0; i < 16; ++i){
               if(ch == specialchar[i]){
                   printf("%c is special character\n", ch);
                   spc++;}
           }
           if(isalnum(ch)||ch=='"'||(ch==' '&&flag==1)){
                if(ch=='"'){
                    if(flag==0){
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                }
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)&&flag==0){
                   buffer[j] = '\0';
                   j = 0;
                   //printf("%s\n",buffer);
                   if(buffer[0]=='"'){
                    printf("%s is string\n",buffer);strcnt++;
                   }
                   else if(isKeyword(buffer) == 1){
                       printf("%s is keyword\n", buffer);ky++;}
                   else{
                       printf("%s is indentifier\n", buffer);iden++;}
           }

    }

    fclose(fp);
    //printf("keywords =%d\nidentifiers =%d\noperators =%d\nstrings =%d\nspecial characters =%d\n",ky,iden,op,strcnt,spc);
    printf("Total=%d",ky+iden+op+strcnt+spc);
    return 0;
}



