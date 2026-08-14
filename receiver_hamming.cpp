#include<iostream>
#include <string>
using namespace std;
int main()
{
    int h[12];
    string code="10101101110";
    for(int i=0;i<11;i++)
    {
        h[11-i]=code[i]-'0';
    }
    int r1=h[1]^h[3]^h[5]^h[7]^h[9]^h[11];
    int r2=h[2]^h[3]^h[6]^h[7]^h[10]^h[11];
    int r4=h[4]^h[5]^h[6]^h[7];
    int r8=h[8]^h[9]^h[10]^h[11];
    int error=(r1*1)+(r2*2)+(r4*4)+(r8*8);
    cout<<"Received code: "<<code<<endl;
    cout<<"R1="<<r1<<endl;
    cout<<"R2="<<r2<<endl;
    cout<<"R4="<<r4<<endl;
    cout<<"R8="<<r8<<endl;
    cout<<"Error at position: "<<endl;
    h[error]=h[error]^1;
    cout<<"Correct Hamming code: ";
    for(int i=11;i>=1;i--)
    {
        cout<<h[i];
    }
 return 0;
}
//Received code: 10101101110
//R1=0
//R2=0
//R3=0
//R4=0
//Error at position: 6
//Correct Hamming code:10101001110
