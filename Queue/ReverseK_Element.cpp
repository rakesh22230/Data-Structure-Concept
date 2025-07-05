#include<bits/stdc++.h>
using namespace std;

void ReverseKElement(int n, int k, queue<int> &q) {
    int x = n / k;
    int y = n % k;

    stack<int> st;

    // Reverse groups of size k
    while (x > 0) {
        int chk = k;
        while (chk > 0 && !q.empty()) {
            st.push(q.front());
            q.pop();
            chk--;
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        x--;
    }

    // Reverse remaining elements (if any)
    if (y > 0) {
        int chk = y;
        while (chk > 0 && !q.empty()) {
            st.push(q.front());
            q.pop();
            chk--;
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }

    // Print the result
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    ReverseKElement(n, k, q);

    return 0;
}
