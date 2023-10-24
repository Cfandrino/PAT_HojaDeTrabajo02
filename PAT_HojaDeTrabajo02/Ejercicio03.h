
#pragma once

#include <string>
#include <stack>

class Ejercicio03 {
public:
    int calculate(std::string s) {
        std::stack<int> nums;  
        std::stack<char> ops;  

        int num = 0; 
        char sign = '+'; 

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0'); 
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                evalOperation(nums, ops, sign, num);

                sign = c;
                num = 0;
            }
        }

        evalOperation(nums, ops, sign, num);

        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }

        return result;
    }

private:
    void evalOperation(std::stack<int>& nums, std::stack<char>& ops, char sign, int num) {
        if (sign == '+') {
            nums.push(num);
        }
        else if (sign == '-') {
            nums.push(-num);
        }
        else if (sign == '*') {
            int prev_num = nums.top();
            nums.pop();
            nums.push(prev_num * num);
        }
        else if (sign == '/') {
            int prev_num = nums.top();
            nums.pop();
            nums.push(prev_num / num);
        }
    }
};
