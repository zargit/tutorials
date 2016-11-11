#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

string opts[4] = {"&","+-","/*","^"};
stack<char> st;

int getPrecedence(char ch){
	for(int i=0;i<4;i++){
		for(int j=0;j<opts[i].length();j++){
			if(ch==opts[i][j]) return i;
		}
	}
	return -1;
}

string makeEmptyUntil(char opt=' '){
	string str = "";
	while(!st.empty()){
		char t = st.top();
		if(t!='(' && getPrecedence(t)<getPrecedence(opt)) break; // break if the t has lesser predence than opt
		st.pop();
		if(t=='(') break;
		str += t;
	}
	return str;
}

string infixToPostfix(string infix){
	string postfix = "";
	// Write your solution here
	
	for(int i=0;i<infix.length();i++){
		int p = getPrecedence(infix[i]);
		if(p==-1){
			if(isalpha(infix[i])){
				postfix += infix[i];
			}else{
				if(infix[i]=='('){
					st.push(infix[i]);
				}else{
					postfix += makeEmptyUntil();
				}
			}
		}else{
			if(!st.empty()){
				int operatorInStack = getPrecedence(st.top());
				if(p>operatorInStack){
					st.push(infix[i]);
				}else{
					postfix += makeEmptyUntil(infix[i]);				
					st.push(infix[i]);
				}
			}else{
				st.push(infix[i]);
			}
		}
	}
	postfix += makeEmptyUntil();
	return postfix;
}

int main(){
	string infix;
	cin>>infix; // take input infix expression	
	// write your code after this
	cout<<infixToPostfix(infix)<<endl;
	return 0;
}














