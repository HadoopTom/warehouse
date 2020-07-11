#include <bits/stdc++.h>

using namespace std;

struct Order {
    int amount,price;
};

int main() {
    int number,bought,sold,sumLIFO,sumFIFO,sumMed,sum,amountsold[sold];
    deque<int> LIFO,FIFO,p;
    cin>>number;
    for (int i = 0; i < number; i++) {
        cin >> bought >> sold;
        Order lol[bought];
        for (int i = 0; i < bought; i++) {
            cin >> lol[i].amount >> lol[i].price;
        }
        for (int i = 0; i < sold; i++) {
            cin >> amountsold[i];
        }
        for (int i = 0; i < bought; i++) {
            if (amountsold[i] > lol[i].amount) {

            }
        }
    }
    return 0;
}