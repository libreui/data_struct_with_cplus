#include <iostream>
// #include "SingleQueue.h"
#include "DoubleQueue.h"

using namespace std;




int main() {
    DoubleQueue queue;
    queue.push(11);
    queue.push(22);
    queue.push(33);
    queue.push(44);
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    try {
        cout<<queue.peek()<<endl;
    } catch (exception *err) {
        cout<<err->what()<<endl;
    }
    
    return 0;
}