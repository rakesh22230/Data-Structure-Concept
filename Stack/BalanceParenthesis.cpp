#include<bits/stdc++.h>
using namespace std;

// Check balanced Parenthesis
bool IsbalanceParenteis(string s) {
    bool isbalanced = true; 
    int n = s.size(); 
    stack<char> st;

    // if first char is closing bracket, it's wrong
    if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
        return false;
    }

    // loop to check every character
    for (int i = 0; i < n; i++) {

        // opening brackets push into stack ---> ( , { , [ 
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        // closing bracket ')' check
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') { // matching '(' found
                st.pop(); 
            } else { 
                isbalanced = false;
                break;
            }
        } 
        // closing bracket '}' check
        else if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') { // matching '{' found
                st.pop();
            } else {
                isbalanced = false;
                break;
            }
        } 
        // closing bracket ']' check
        else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') { // matching '[' found
                st.pop();
            } else {
                isbalanced = false;
                break;
            }
        }
    }

    // after loop, if stack not empty → wrong
    if (!st.empty()) {
        isbalanced = false;
    }

    return isbalanced; 
}

int main() {
    string str;
    cin >> str; 

    // call function 
    if (IsbalanceParenteis(str)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
