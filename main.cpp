

#include <iostream>
#include<bits/stdc++.h>
#include<curses.h>

using namespace std;


int* create_lcg(int step,int increement,int modulo,int seed)
 { int randomno=seed;
   int random[1000]={};
   for(int i=0;i<1000;i++)
    { randomno=(randomno*step+increement)%(int)(pow(2,modulo));
      random[i]=randomno;
    }
  
    
   return random;
 }
 
 void display(int* array)
  {  cout<<"\nThe Array is :\n";
     for(int j=0;j<1000;j++)
       cout<<array[j]<<",";
  }
  
 void runs_1(int* p)
  { int sum=0; int run_copy[1000]={};
    int run_below[1000]={};
    
    for(i=0;i<1000;i++)
     { sum+=p[i];
       run_copy[i]=p[i];
     }
    int mean=sum/1000;
    for(i=0;i<1000;i++)
     { if(run_copy[i]>=mean)
        run_copy[i]=1;
       else
        run_copy[i]=0;
     }
    int count=1,n1=0,n2=0;
    for(i=0;i<1000;i++)
      if(run_copy[i]!=run_copy[i+1])
        count++;
    for(i=0;i<1000;i++)
      {if(run_copy[i]==1)
        n1++;
       else 
        n2++;
      } 
      
    int nu;
    int sigmasq;
    int zcalc,ztheory
    int accuracy=5;
    ztheory=1.96;
    nu=(2*n1*n2/1000)+0.5;
    sigmasq=(2*n1*n2*((2*n1*n2)-1000))/(1000000*999);
    zcalc=(count-nu)/sigmasq;
    
    cout<<"\n"<<nu<<","<<sigmasq<<","<<zcalc<<",";
    if(zcalc<ztheory)
     cout<<"\n Null Hypothesis is Accepted";
    else
     cout<<"\n Null Hypothesis is Rejected";
    
  }
 
int main()
{
    display(create_lcg(13,34,6,67));
    return 0;
}


