// Valid parenthesis


#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
	stack<char> st;
	
	for (char c : s ) {
		// push opening parathesis
		if (c== '(' || c == '{' || c =='[')
			{
				st.push(c);
			}
			
		else{ //check closing parantsis
			
			if (st.empty()) return false;
			
			char top = st.top();
			
			if ((c== ')' && top != '(') || c == ']' && top != '[' || c== '}' && top != '{')
				{
					return false;
				}
				
				st.pop();
			}
		}
		
		return st.empty(); // if this is true, then stack is empty its a valid parenthis.
	
}
	


int main() {
    // Test cases
    string test1 = "({[]})";
    string test2 = "([)]";
    string test3 = "";
    string test4 = "(";
    string test5 = "]";
    
    cout << test1 << ": " << (isValid(test1) ? "Valid" : "Invalid") << endl; // Valid
    cout << test2 << ": " << (isValid(test2) ? "Valid" : "Invalid") << endl; // Invalid
    cout << test3 << ": " << (isValid(test3) ? "Valid" : "Invalid") << endl; // Valid
    cout << test4 << ": " << (isValid(test4) ? "Valid" : "Invalid") << endl; // Invalid
    cout << test5 << ": " << (isValid(test5) ? "Valid" : "Invalid") << endl; // Invalid
    return 0;
}