#include<iostream>
using namespace std;
int main()
{
    cout<<"Data word: 1011001"<<endl;
    cout<<"No. of redandant bit= 4"<<endl;
    cout<<"Total no. of bits in codeword:  11"<<endl;
    int h[12]={0};
    h[11]=1;
    h[10]=0;
    h[9]=1;
    h[7]=1;
    h[6]=0;
    h[5]=0;
    h[3]=1;
     h[1]=h[1]^h[3]^h[5]^h[7]^h[9]^h[11];
     h[2]=h[2]^h[3]^h[6]^h[7]^h[10]^h[11];
     h[4]=h[4]^h[5]^h[6]^h[7];
     h[8]=h[8]^h[9]^h[10]^h[11];
     cout<<"Final codeword is transmitted: ";
    for(int i=11;i>=1;i--)
    {
        cout<<h[i];
    }

return 0;
}
//Data word: 1011001
//No. of redandant bit= 4
//Total no. of bits in codeword:  11
//Final codeword is transmitted:101001110
