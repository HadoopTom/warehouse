#include <bits/stdc++.h>
using namespace std;
struct TShare
{
    long long price, cnt;
};

int main()
{
    int num,bought,sold;
    deque<TShare> q;
    stack<TShare> st;
    char opr;
    long long lbfs = 0, fbfs = 0, med = 0, temp = 0, temp1 = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin>>bought>>sold;
        for (int i = 0; i < bought; i++)
        {
            TShare share;
            cin >> share.cnt >> share.price;
            q.push_back(share);
            st.push(share);
            temp += share.cnt * share.price;
            temp1 += share.cnt;
            continue;
        }
        med = temp/temp1;
        for (int i = 0; i < sold + 2; i++)
        {
            TShare share;
            cin >> share.cnt;
            int cnt = share.cnt;
            //fbfs = fbfs + share.price * share.cnt;
            while (cnt > 0)
            {
                auto sh1 = q.front(); q.pop_front();
                if (cnt >= sh1.cnt)
                {
                    fbfs = fbfs - sh1.cnt * sh1.price;
                    cnt -= sh1.cnt;
                }
                else
                {
                    sh1.cnt -= cnt;
                    fbfs = fbfs - cnt * sh1.price;
                    cnt = 0;
                    q.push_front(sh1);
                }
            }
            cnt = share.cnt;
            lbfs += share.price * share.cnt;
            while (cnt > 0)
            {
                auto sh1 = st.top(); st.pop();
                if (cnt >= sh1.cnt)
                {
                    lbfs -= sh1.cnt * sh1.price;
                    cnt -= sh1.cnt;
                }
                else
                {
                    sh1.cnt -= cnt;
                    lbfs -= cnt * sh1.price;
                    cnt = 0;
                    st.push(sh1);
                }
            }
        }
    }
    if (lbfs > fbfs && lbfs > med && fbfs > med) {
        cout<<lbfs<<endl<<fbfs<<endl<<med<<endl;
        cout<<"MEDIUM";
    }
    else if (lbfs > fbfs && lbfs > med && med > fbfs) {
        cout<<lbfs<<endl<<med<<endl<<fbfs<<endl;
        cout<<"FIFO";
    }
    else if (fbfs > lbfs && fbfs > med && lbfs > med) {
        cout<<fbfs<<endl<<lbfs<<endl<<med<<endl;
        cout<<"MEDIUM";
    }
    else if (fbfs > lbfs && fbfs > med && med > lbfs) {
        cout<<fbfs<<endl<<med<<endl<<lbfs<<endl;
        cout<<"LIFO";
    }
    else if (med > fbfs && med > lbfs && fbfs > lbfs) {
        cout<<med<<endl<<fbfs<<endl<<lbfs<<endl;
        cout<<"LIFO";
    }
    else if (med > fbfs && med > lbfs && lbfs > fbfs) {
        cout<<med<<endl<<lbfs<<endl<<fbfs<<endl;
        cout<<"FIFO";
    }
    return 0;
}