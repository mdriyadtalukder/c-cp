#include <iostream>
#include <cmath>
using namespace std;
int main(){

    //153 (1³+5³+3³=153)
    
    int n,r=0,sum=0;
    cin>>n;
    int temp=n;

    cout<<endl;

    while (temp !=0)
    {
        r=temp%10;
        sum=sum+pow(r,3);
        temp=temp/10;

    }
     if(sum==n){
            cout<<"Armstrong";
        }
        else{
         cout<<"Not Armstrong";        
        }
    
}