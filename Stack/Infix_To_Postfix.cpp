#include<bits/stdc++.h>
using namespace std;
// Precission function
int PrecissionCal(char c){
    if(c=='^'){
        return 3;
    }else if(c=='/' || c=='*'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    } else{
        return -1;
    }
}
// Infix to postfix conversation 
string infixToPostfix(string str){
    
    stack<char> st;
    string result;
    
    for(int i=0;i<str.length();i++){
        //s1 : 0 to 9 print 
        if(str[i]>='0' && str[i]<='9'){
            result+=str[i];
        } // ')'  then stack push
        else if(str[i]=='('){
            st.push(str[i]);
        }else if(!st.empty() && str[i]==')'){
            while(st.top()!='('){
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        } else{
            while(!st.empty() && PrecissionCal(st.top()) >= PrecissionCal(str[i]) ){
                result+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()) {
    	result+=st.top();
    	st.pop();
	}
    return result;
}

int main(){
    string infix = "(4*(3+5))-(2+0)";
    string postfix;
    postfix = infixToPostfix(infix);
    cout<<"Postfix is: "<<postfix<<endl;
    //    <<"Prefix Evulation is: "<<prefixCalculate(prefix)<<endl;

    return 0;
}
