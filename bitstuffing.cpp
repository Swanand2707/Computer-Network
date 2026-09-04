#include<iostream>
#include<string>
using namespace std;
int main()
{
    string in;
    cout<<"Enter Data:";
    cin>>in;
    int count=0;
    for(int i=0;i<in.length();i++)
    {
        cout<<in[i];
        if (in[i] == '1')
        {
            count++;
            if(count == 5)
            {
                cout<<0;
                count=0;
            }
        }
        else
        {
            count=0;
        }
    }
}
