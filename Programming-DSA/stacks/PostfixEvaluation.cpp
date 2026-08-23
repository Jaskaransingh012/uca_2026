/*
Evaluation of Postfix expressions
The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix.

For example: 3 1 * + 9 - is a postfix expression where paranthesis are not required to change the order of evaluation of expressions. The order of evaluation for expressions with operator is governed by the position of the operator in the expression.

Here, the order of evaluation is: *, +, -

(3 * 1) + 2) - 9 is the equivalent infix expression and the value of the expression is: -4

Constraints: 0 < Length of expression < 50 Operands are numeric Operators are: "+" for addition, "-" for subtraction, "*" for multiplication, "/" for division and

Every token in the expression is separated by a space.

Sample Input 2 3 1 * + 9 -

Sample Output -4

*/

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(string expression)
{
    stack<int> st;
    stringstream ss(expression);

    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        }
    }

    return st.top();
}

int main()
{
    string expression = "2 3 1 * + 9 -";

    cout << evaluatePostfix(expression) << endl;

    return 0;
}
