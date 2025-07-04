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
// Infix to prefix conversation 
string infixToPrefix(string str){
    // S1: reverse this string 
    reverse(str.begin(),str.end());
    stack<char> st;
    string result;
    // step 2 er process 
    for(int i=0;i<str.length();i++){
        //s1 : 0 to 9 print 
        if(str[i]>='0' && str[i]<='9'){
            result+=str[i];
        } // ')'  then stack push
        else if(str[i]==')'){
            st.push(str[i]);
        }else if(!st.empty() && str[i]=='('){
            while(st.top()!=')'){
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
    reverse(result.begin(),result.end());
    return result;
}
// Prefix Calculation 
int prefixCalculate(string str){
	
	stack <int> st;
	for(int i = str.length()-1; i>=0; i--){
		// str[i] 0 to 9 which is operand
		if(str[i]>='0' && str[i]<='9'){
			st.push(str[i]-'0');
		} else{
			// str[i] which is operator
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			
			switch(str[i]){
				case '+':
					st.push(a+b);
					break;
				case '-':
					st.push(a-b);
					break;
				case '*':
					st.push(a*b);
					break;
				case '/':
					st.push(a/b);
					break;
				case '^':
					st.push(pow(a,b));
					break;
				default:
					break;
			}
			
		}
			
	}
	return st.top();	
}
int main(){
    string infix = "(7+(4*5))-(2+0)";
    string prefix;
    prefix = infixToPrefix(infix);
    cout<<"Prefix is: "<<prefix<<endl
        <<"Prefix Evulation is: "<<prefixCalculate(prefix)<<endl;

    return 0;
}
