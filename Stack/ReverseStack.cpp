#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& stk, int element) {
    if (stk.empty()) {
        stk.push(element);
        return;
    }
    int topElement = stk.top();
    stk.pop();
    insertAtBottom(stk, element);
    stk.push(topElement);
}

void reverseStack(stack<int>& stk) {
    if (stk.empty()) {
        return;
    }
    int topElement = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk, topElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
