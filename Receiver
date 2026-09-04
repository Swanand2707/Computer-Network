#include <iostream>
#include <string>
using namespace std;

string divide(string data, string div)
{
    int n = data.length();
    int m = div.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < m; j++)
            {
                if (data[i + j] == div[j])
                    data[i + j] = '0';
                else
                    data[i + j] = '1';
            }
        }
    }

    return data.substr(n - m + 1);
}

int main()
{
    string data, div, rem, code;

    cout << "Enter Data Word: ";
    cin >> data;

    cout << "Enter Divisor: ";
    cin >> div;
    int zero = div.length() - 1;
    string temp = data + string(zero, '0');
    rem = divide(temp, div);
    code = data + rem;

    cout << "\nData Word       : " << data << endl;
    cout << "Divisor         : " << div << endl;
    cout << "Zeros to add    : " << zero << endl;
    cout << "Data + Zeros    : " << temp << endl;
    cout << "Remainder       : " << rem << endl;
    cout << "Final Code Word : " << code << endl;
}
