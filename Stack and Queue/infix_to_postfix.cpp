#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// fucntion that fill me precedence of  operator:
int getPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // Example for exponentiation
    default:
        return 0; // For unknown operators or parentheses
    }
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            ans = ans + s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // that is if we see closing bracket we pop stack element until see a opening

            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            // here we are poping the opening bracket
            st.pop();
        }

        else
        {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top()))

            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    // poping out reaminign elements of stack untill it is empty

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// infix to prefix

// updated function

string infix_to_prefix(string s)
{

    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    // code form infix to postfix:

    stack<char> st;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            ans = ans + s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // that is if we see closing bracket we pop stack element until see a opening

            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            // here we are poping the opening bracket
            st.pop();
        }

        else
        {
            while (!st.empty() &&
                   (getPrecedence(s[i]) < getPrecedence(st.top()) ||
                    (getPrecedence(s[i]) == getPrecedence(st.top()) && s[i] != '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // poping out reaminign elements of stack untill it is empty

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = infix_to_prefix(exp);

    cout << ans;

    return 0;
}