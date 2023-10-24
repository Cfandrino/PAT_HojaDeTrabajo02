#include <stack>
#include <string>

int calculate(std::string s) {
    std::stack<int> numStack;
    std::stack<char> opStack;
    int num = 0;
    int result = 0;
    int sign = 1;

    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else {
            result += sign * num;
            num = 0;

            if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                numStack.push(result);
                opStack.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result = opStack.top() * result + numStack.top();
                opStack.pop();
                numStack.pop();
            }
        }
    }

    result += sign * num;
    return result;
}