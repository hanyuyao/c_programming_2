#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

stack<int> s;

bool doOperation(void)
{
	int a;
	if(!s.empty() && s.top() != 0 && s.top() != -1){
		a = s.top();
		s.pop();
		if(!s.empty() && s.top() != 0 && s.top() != -1){
			s.push(a);
			return true;
		}
		else{
			s.push(a);
			return false;
		}
	}
	return false;
}

void operate(void)
{
	int a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	
	int op = s.top();
	s.pop();
	
	if(op==0){
		s.push((a+b));
		//cout << a << '+' << b << endl;
	}
	else{
		s.push((b-a));
		//cout << b << '-' << a << endl;
	}
}

int main(){
	char c;
	int i;
	
	while((c=getchar())!='0'){
		if(c=='+'){
			s.push(0);
			//cout << "push +" << endl;
		}
		else if(c=='-'){
			s.push(-1);
			//cout << "push -" << endl;
		}
		else if(isspace(c)){}
		else{
			ungetc(c, stdin);
			scanf("%d", &i);
			s.push(i);
			while(doOperation()){
				operate();
			}
		}
	}
	
	cout << s.top();
} 
