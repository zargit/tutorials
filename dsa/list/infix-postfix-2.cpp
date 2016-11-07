#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

string opt[2] = {"+-", "/*"};
stack<char> st;

int getPrecedence(char ch){
	for(int i=0;i<2;i++){
		for(int j=0;j<opt[i].length();j++){
			if(opt[i][j]==ch) return i;
		}
	}
	return -1;
}

string makeEmptyUntil(bool bracket=false){
	string str = "";
	while(!st.empty()){
		char t = st.top();
		st.pop();
		if(bracket && t=='(') break;
		str += t;
	}
	return str;
}

string infixToPostfix(string infix){
	string postfix = "";
	// your solution goes here
	for(int i=0;i<infix.length();i++){
		int p = getPrecedence(infix[i]);
		if(p==-1){
			// handling operands or brackets
			if(isalpha(infix[i])){
				// handling operands
				postfix += infix[i];
			}else{
				// handling brackets
				if(infix[i]=='('){
					st.push(infix[i]);
				}else{
					postfix += makeEmptyUntil(true);
				}
			}
		}else{
			// handling operators
			if(!st.empty()){
				// stack is not empty
				int operatorInStack = getPrecedence(st.top());
				if(p<=operatorInStack){
					// input operator has lower or equal precedence with operator at top of stack
					postfix += makeEmptyUntil(true);
					st.push(infix[i]);
				}else{
					// input operator has higher precedence than operator at top of stack
					st.push(infix[i]);
				}
			}else{
				// stack is empty
				st.push(infix[i]);
			}
		}
	}
	// make sure there is nothing left in the stack
	postfix += makeEmptyUntil();
	return postfix;
}

int main(){
	string infix;
	cin>>infix;
	cout<<infixToPostfix(infix)<<endl;
	/*stack<char> st;
	char ch = '+';
	st.push(ch);
	ch = '*';
	st.push(ch);

	while(!st.empty()){
		cout<<st.top()<<"  ";
		st.pop();
	}*/
	return 0;
}
