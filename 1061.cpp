#include<iostream>

#include<cstdlib>

#include<algorithm>

#include<cstring>

using namespace std;

int main(){

   char num[100001]={0};cin>>num;

   int begin=0,end=0;bool bo=0;

   int len=strlen(num);

   for(int i=0;i<len-4;i+=2)

      for(int j=i+2;j<=i+(len-i)/2;j+=2)

         if(equal(num+i,num+j,num+j)){

            if(j-i>end-begin){

               begin=i;end=j;bo=1;

            }

            if(j==(len-i)/2)break;

         }

   if(bo)

      for(int i=begin;i<end;++i)cout<<num[i];

   else cout<<"NO";

}