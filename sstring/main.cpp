#include <iostream>
#include <string>
using namespace std;

string reverse(string str, int l, int r) {
    if (l >= r) {
        return str;
    }

    swap(str[l], str[r]);

    return reverse(str, ++l, --r);
}

int main() {
    string p = "abcdefg";
    cout<<p<<endl;
    cout<<reverse(p, 0, p.size()-1);
    return 0;
}