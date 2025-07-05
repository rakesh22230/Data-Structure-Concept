#include<bits/stdc++.h>
#include"MYQUE.h"
using namespace std;

int main() {
    Queue <int> q;
    cout<<"Enter the size: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int chk;
        cin>>chk;
        q.push(chk);
    }


    while (!q.empty()) {
        cout << q.pop() << endl;
    }

    Queue<string> s;
    s.push("Rakes Barman");
         while(!s.empty()){
        cout<<s.pop()<<endl;
     }

    return 0;
}
