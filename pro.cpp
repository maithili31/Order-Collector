#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct data {
    string name;
    string orderItems;  
    int orderId;
};

bool orderRecieve(struct data &temp,int &orderNo) {

    string newName;
    string newOrderItem;     

    cin>>newName>>newOrderItem;

    temp.name=newName;
    temp.orderItems=newOrderItem;
    temp.orderId=orderNo;
    return true;
}

void inputQueue(queue<data> q,struct data &temp,int &orderNo) {
    q.push(temp);
    cout<<"Order Received"<<endl;
    cout<<"Your order number is : "<<temp.orderId<<endl;
    orderNo+=1;
}

void orderDelivered(queue<data> q) {
    cout<<q.front().name<<endl;
    cout<<q.front().orderItems<<endl;
    cout<<q.front().orderId<<endl;
    cout<<"Order is delivered to : "<<q.front().name<<endl;
    if(!q.empty()) {
        q.pop();
    }
}

int main () {
    struct data temp;
    queue<data> q;
    int orderNo=1;
    while (1) {
        cout<<"Do you want to place an order ?"<<endl;
        int n;
        cout<<"Press 1 for YES"<<endl;
        cout<<"Press 2 for NO"<<endl;
        cin>>n;
        if (n==3) {
            break;
        }
        switch(n) {
            case 1 :
                orderRecieve(temp,orderNo);
                cout<<"done"<<endl;
                inputQueue(q,temp,orderNo);
                break;
                
            case 2 :
                if(!q.empty()) {
                    orderDelivered(q);   
                } else {
                    cout<<"All orders are delivered"<<endl;
                }
                break;
            
            default :
                cout<<"Incorrect Input"<<endl;
                break;
        } 
    }
    return 0;
}