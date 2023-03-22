#include <iostream>
using namespace std;

void count(int i, int n) {
    cout<<i<<"  ";
    if (i < n) {
        count(i+1, n);
        cout<<i<<"  ";
    }
}

// 判断是否标识符 $_xx99xx
bool isIdentifier(char *str, int i) {
    if (i > 0 && str[i] == '\0')
        return true;
    if (i > 0 && str[i] != '\0') {
        char ch = str[i];
        if (ch >= 'A' && ch <='Z' || ch >= 'a' && ch <= 'z' || ch == '_' || ch == '$' || ch >='0' && ch <= '9') {
            return isIdentifier(str, i+1);
        }
    }
    return false;
}

int main() {
    char *str = "$_a44a";
    cout<<str<<":"<<isIdentifier(str, strlen(str));
    // int n = 9;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = n; j > i; j--)
    //         cout<<"   ";
    //     count(1, i);
    //     cout<<"\n";
        
    // }
    
    return 0;
}