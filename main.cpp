#include <iostream>
#include <deque>

using namespace std;

struct stuff{
    int amount;
    int price;
};

int main() {
    string a,b;
    stuff p;
    deque<int> lol;
    cin>>a;
    int LIFO,FIFO,Med;
    while (cin>>b) {
        //FIFO
       if (b == "E") {
           continue;
       }
       cin>>p.amount>>p.price;
       if (b == "B") {
           FIFO+=p.amount*p.price;
       }
    }
    return 0;
}
