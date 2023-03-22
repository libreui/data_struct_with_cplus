#include <iostream>
#include <stack>
using namespace std;

// 将十进制转为二进制
void decimalToBinary(int num) {
    stack<int> s;

    while (num > 0)
    {
        int remainder = num % 2;
        s.push(remainder);
        num /= 2;
    }

    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

// 将十进制转为八进制
void decimalToOctal(int num) {
    stack<int> s;
    while (num > 0)
    {
        int remainder = num % 8;
        s.push(remainder);
        num /= 8;
    }

    cout<<"Octal:";
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

// 将十进制转为十六进制
void decimalToHexadecimal(int num) {
    stack<char> s;
    while (num > 0)
    {
        int remainder = num % 16;
        if (remainder < 10) {
            s.push(remainder + '0');
        } else {
            s.push(remainder - 10 + 'A');
        }
        num /= 16;
    }
    cout<<"Hexadecimal:";
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

int main() {
    decimalToBinary(255);
    decimalToOctal(8);
    decimalToHexadecimal(254);
    return 0;
}