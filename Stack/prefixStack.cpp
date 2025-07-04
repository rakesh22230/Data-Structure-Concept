#include<bits/stdc++.h>
using namespace std;
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
	
	string str;
	cout<<"Enter your value: ";
	getline(cin,str);
	int prefix = prefixCalculate(str);
	cout<<"Prefix Calculator is: "<<prefix<<endl;
	
	return 0;
}
