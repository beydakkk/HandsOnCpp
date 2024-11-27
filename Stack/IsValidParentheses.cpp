#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsValidParentheses(const string& input) {
    stack<char> s;

    for (char c : input){
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else{
            if(s.empty() || 
              (c == ')' && s.top() != '(') ||
              (c == '}' && s.top() != '{') ||
              (c == ']' && s.top() != '['))
                return false; 
            s.pop(); 
        }
    }
    return s.empty();   // If the stack is empty, all brackets are matched
}

int main() {
    string test1 = "({[]})";
    string test2 = "(]";
    string test3 = "([{}])";
    string test4 = "([)]";
    string test5 = "";

    cout << test1 << " -> " << (IsValidParentheses(test1) ? "Valid" : "Invalid") << "\n";
    cout << test2 << " -> " << (IsValidParentheses(test2) ? "Valid" : "Invalid") << "\n";
    cout << test3 << " -> " << (IsValidParentheses(test3) ? "Valid" : "Invalid") << "\n";
    cout << test4 << " -> " << (IsValidParentheses(test4) ? "Valid" : "Invalid") << "\n";
    cout << "Empty string -> " << (IsValidParentheses(test5) ? "Valid" : "Invalid") << "\n";

    return 0;
}