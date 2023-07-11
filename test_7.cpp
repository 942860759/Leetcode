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
class Solution {
public:
    int reverse(int x) {
        std::vector<int> origin;
        if (x < INT_MIN || x > INT_MAX)
            return 0;
        if (x == INT_MIN)
            return 0;
        int abs_x = x;
        if (x < 0)
            abs_x = -x;
        while (abs_x / 10 > 0) {
            origin.push_back(abs_x % 10);
            abs_x = abs_x / 10;
        }
        origin.push_back(abs_x % 10);

        int result = 0;
        int j = 0;
        std::vector<int> max_int = {2,1,4,7,4,8,3,6,4,7};
        std::vector<int> min_int = {2,1,4,7,4,8,3,6,4,8};
        if (origin.size() > max_int.size())
            return 0;
        else if (origin.size() == max_int.size() && x > 0) {
            for (int i = 0; i < origin.size(); i++) {
                if (origin[i] > max_int[i])
                    return 0;
                else if (origin[i] == max_int[i])
                    continue;
                else
                    break;
            }
        } else if (origin.size() == max_int.size() && x < 0) {
            for (int i = 0; i < origin.size(); i++) {
                if (origin[i] > min_int[i])
                    return 0;
                else if (origin[i] == min_int[i])
                    continue;
                else
                    break;
            }
        }
        
        for (int i = origin.size() - 1; i >= 0; i--) {
            result = pow(10, j) * origin[i] + result;
            j++;
        }
        if (x < 0)
            result = - result;
        return result;
    }
};

int main() {
    Solution solution;
    int result = solution.reverse(-2147483648);
    std::cout <<  result << std::endl;
    return 0;
}