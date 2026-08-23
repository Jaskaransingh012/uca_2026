#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isBalanced(string s)
{

    stack<char> st;

    for (char ch : s)
    {

        if (ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch);
        }
        else if (st.empty() || (ch == '}' && st.top() != '{' || ch == ']' && st.top() != '[' ||
                                ch == ')' && st.top() != '('))
        {
            return false;
        }
        else
            st.pop();
    }

    return st.empty();
}

int main ()
 {

    string s = "{([]()]}";

    cout << isBalanced(s) << endl;

 }
