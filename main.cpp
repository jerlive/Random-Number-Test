/******************************************************************************

         Coded by Jerin Mathew Vithayathil, TVE16IE036
         https://github.com/jerlive/Random-Number-Test/edit/master/main.cpp

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<curses.h>

using namespace std;
int i;

int* create_lcg(int step,int increement,int modulo,int seed)
 { int randomno=seed;
   int random[1000]={};
   for(int i=0;i<1000;i++)
    { randomno=(randomno*step+increement)%(int)(pow(2,modulo));
      random[i]=randomno;
    }
  
    
   return random;
 }
 
 
  
 void runs_1(int* p)
  { int sum=0; int run_copy[1000]={};
    int run_below[1000]={};
    int big=p[0],small=p[0];
    
    for(i=0;i<1000;i++)
     { if(p[i]>=big)
        big=p[i];
     }
     
    for(i=0;i<1000;i++)
     { if(p[i]<=small)
        small=p[i];
     }
    void display(int*); 
    float mean=49.5;
   //float mean=big+small/2;
    
    for(i=0;i<1000;i++)
     { if(p[i]>=mean)
        run_copy[i]=1;
       else
        run_copy[i]=0;
     }
    display(p);
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
      
    float nu;
    long int sigmasq;
    float zcalc,ztheory;
    int accuracy=5;
    ztheory=1.96;
    nu=(2*n1*n2/1000)+0.5;long int temp=2*n1*n2,temp2=1000000/999;
    sigmasq=(temp*(temp-1000))/temp2;
    zcalc=(count-nu)/sigmasq;
    cout<<"\n\n RESULTS :";
    cout<<"\n Observed Mean : "<<nu<<"\n Observed Variance : "<<sigmasq<<"\n Calculated Z-Score : "<<zcalc<<"\n Above the Mean : "<<n1<<"\n Below the Mean : "<<n2<<"\n Number of Runs : "<<count<<".";
    if(zcalc<ztheory)
     cout<<"\n Null Hypothesis for Runs Test is Accepted";
    else
     cout<<"\n Null Hypothesis for Runs Test is Rejected";
    
  }
  
void display(int* array)
  {  cout<<"\nThe Array is :\n";
     for(int j=0;j<1000;j++)
       cout<<array[j]<<",";
     
  }
 
int main()
{
    runs_1(create_lcg(13,34,6,67));
    return 0;
}


