#include <iostream>
#include <string>
using namespace std;

int main() {
    string ip;

    cout << "Enter IPv4 Address: ";
    cin >> ip;

    int octet[4];
    int count = 0;
    string temp = "";


    for (int i = 0; i <= ip.length(); i++) {
        
        if (i == ip.length() || ip[i] == '.') {
            

            if (temp == "" || count >= 4) {
                cout << "Invalid IPv4 Address";
                return 0;
            }


            int num = 0;

            for (int j = 0; j < temp.length(); j++) {
                if (temp[j] < '0' || temp[j] > '9') {
                    cout << "Invalid IPv4 Address";
                    return 0;
                }

                num = num * 10 + (temp[j] - '0');
            }


            if (num < 0 || num > 255) {
                cout << "Invalid IPv4 Address";
                return 0;
            }

            octet[count] = num;
            count++;
            temp = "";
        }
        else {
            temp += ip[i];
        }
    }


    if (count != 4) {
        cout << "Invalid IPv4 Address";
        return 0;
    }

    cout << "\nIPv4 Address is Valid\n";
    cout << "_____________________"<<endl;
    cout<<"IPv4 Adress is :"<<ip<<endl;
    cout<<"________________________________"<<endl;

    if (octet[0] >= 0 && octet[0] <= 127) {
        cout << "Class: A\n";
      cout<<"__________"<<endl;
        cout << "Network Address: " << octet[0]<<".0.0.0" << "\n";
      cout<<"______________"<<endl;
        cout << "Host Address: " << octet[1] << "."
             << octet[2] << "." << octet[3]<<".0" << "\n";
      cout<<"_______________"<<endl;
        cout << "Default Network Mask: 255.0.0.0\n";
        cout<<"______________________________"<<endl;
    }


    else if (octet[0] >= 128 && octet[0] <= 191) {
        cout << "Class: B\n";
      cout<<"________"<<endl;
        cout << "Network ID: " << octet[0] << "."
             << octet[1] <<".0.0"<< "\n";
      cout<<"__________________"<<endl;
        cout << "Host ID: " << octet[2] << "."
             << octet[3]<<"0.0" << "\n";
      cout<<"_____________"<<endl;
        cout << "Default Network Mask: 255.255.0.0\n";
        cout<<"_________________________________"<<endl;
    }


    else if (octet[0] >= 192 && octet[0] <= 223) {
        cout << "Class: C\n";
      cout<<"________"<<endl;
        cout << "Network ID: " << octet[0] << "."
             << octet[1] << "."
             << octet[2] <<".0"<< "\n";
      cout<<"_______________________"<<endl;
        cout << "Host ID: " << octet[3]<<".0.0.0" << "\n";
      cout<<"____________"<<endl;
        cout << "Default Network Mask: 255.255.255.0\n";
        cout<<"____________________________________"<<endl;
    }


    else if (octet[0] >= 224 && octet[0] <= 239) {
        cout << "Class: D\n";
      cout<<"_________"<<endl;
        cout << "Network ID: Not Applicable\n";
      cout<<"__________________________"<<endl;
        cout << "Host ID: Not Applicable\n";
      cout<<"_______________________"<<endl;
        cout << "Default Network Mask: Not Applicable\n";
        cout<<"____________________________________"<<endl;
    }


    else {
        cout << "Class: E\n";
      cout<<"____________"<<endl;
        cout << "Network ID: Not Applicable\n";
      cout<<"__________________________"<<endl;
        cout << "Host ID: Not Applicable\n";
      cout<<"________________________"<<endl;
        cout << "Default Network Mask: Not Applicable\n";
        cout<<"____________________________________"<<endl;
    }

    return 0;
}
//Enter IPv4 Address: 99.0.8.9
//
//IPv4 Address is Valid
//_____________________
//IPv4 Adress is :99.0.8.9
//________________________________
//Class: A
//__________
//Network Address: 99.0.0.0
//______________
//Host Address: 0.8.9.0
//_______________
//Default Network Mask: 255.0.0.0
//______________________________
