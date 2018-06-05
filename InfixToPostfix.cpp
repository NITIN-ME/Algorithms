#include<iostream>
#include<stack>
using namespace std;

int val(char ch){
	if(ch == '(' || ch == ')') return -1;
	if(ch == '*' || ch == '/') return 2;
	if(ch == '+' || ch == '-') return 1;
}

string InfixToPostfix(string s){
	string f = "";
	stack<char> st;
	for(int i = 0 ; i < s.size(); i++){
		char ch = s[i];
		//cout<<"CH: "<<ch<<endl;
		if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')'){
			f += ch;
			//cout<<"ADDING1: "<<ch<<endl;
		}
		else{
			if(st.empty() || ch == '('){
				st.push(ch);
				//cout<<"PUSHING1: "<<ch<<endl;
			}
			else if(ch == ')'){
				while(st.top() != '('){
					f += st.top();
					//cout<<"POPPING1: "<<st.top()<<endl;
					st.pop();
				}
				//cout<<"POPPING2: "<<st.top()<<endl;
				st.pop();
			}
			else{
				while(val(st.top()) > val(ch) && !st.empty() && ch != '('){
					f += st.top();
					//cout<<"ADDING2: "<<st.top()<<endl;
					//cout<<"POPPING3: "<<st.top()<<endl;
					st.pop();
					if(st.size() == 0) break;
				}
				st.push(ch);
				//cout<<"PUSHING2: "<<ch<<endl;
			}
		}
		//cout<<"f: "<<f<<endl;
	}
	while(!st.empty()){
		//cout<<"ADDING3: "<<st.top()<<endl;
		f += st.top();
		st.pop();
	}
	return f;
}

int main(){
	cout<<InfixToPostfix("a+(b*c)")<<endl;
	cout<<InfixToPostfix("a+b*c-d*e")<<endl;
	cout<<InfixToPostfix("((a+b)*c-d)*e")<<endl;
	return 0;
}
