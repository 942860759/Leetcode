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
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max = 0;
        int area = 0;
        while(start < end) {
            area = (end - start) * min(height[start], height[end]);
            if (max < area)
                max = area;
            if (height[start] < height[end])
                start++;
            else {
                end--;
            }
        }
        return max;
    }
};

int main() {
    Solution solution;
    vector<int> input{1,8,6,2,5,4,8,3,7};
    int result = solution.maxArea(input);
    std::cout <<  result << std::endl;
    return 0;
}