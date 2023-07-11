// Definition for singly-linked list.
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;
#include <cmath>
#include <ctype.h>   // isdigit()
#include <limits.h>  // INT_MIN, INT_MAX
#include <cstring>

class Solution {
public:
    int myAtoi(string s) {
        string res;
        long int result = 0;
        bool isPositive = true;
        int start, end = -1;
        for (int i = 0; i < s.size(); i++) {
            char str1 = ' ';
            char str2 = '-';
            char str3 = '+';
            if (s[i] == str1)
                continue;
            if (s[i] == str2 && start < 0) {
                isPositive = false;
                start = i + 1;
                continue;
            }
            if (s[i] == str3 && start < 0) {
                start = i + 1;
                continue;
            }
            if (start < 0) {
                if (isdigit(s[i])) {
                    start = i;
                    continue;
                } else {
                    return 0;
                }
                
            }
            if (start >= 0) {
                if(isdigit(s[i])) {
                    continue;
                } else {
                    end = i - 1;
                    break;
                }
            }
        }
        if (end < 0) {
            end = s.size() + 1;
            res = s.substr(start, end - start + 1);
        } else{
            res = s.substr(start, end - start);
        }
        
        for (int j = 0; j < res.size(); j ++) {
            result = pow(10, j) * int(res[res.size() - j - 1] - '0') + result;
        }
        if (!isPositive)
            result = -result;
        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;
        return result;
    }
};

int main() {
    Solution solution;
    int result = solution.myAtoi("   -42");
    std::cout <<  result << std::endl;
    return 0;
}