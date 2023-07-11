// Definition for singly-linked list.
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        std::vector<std::vector<char> > result_v(numRows, std::vector<char>());
        for (int i = 0; i < s.size(); i++) {
            // line 1 (2 * numRows - 2)
            int firstLine = 2 * numRows - 2;
            if ( i % firstLine == 0) {
                int col = (i / firstLine) * (numRows - 1);
                result_v[0].push_back(s[i]);
            } else {
                int number = i % firstLine;
                if (number < numRows) {
                    int col = (i / firstLine) * (numRows - 1);
                    int row = number;
                    result_v[row].push_back(s[i]);
                } else {
                    int row = firstLine - number;
                    int col = (i / firstLine) * (numRows - 1) + number + 1 - numRows;
                    result_v[row].push_back(s[i]);
                }
            }
        }
        std::string result_s;
        for ( int row = 0; row < numRows; row ++) {
            for (int col = 0; col < result_v[row].size(); col ++) {
                result_s.push_back(result_v[row][col]);
            }
        }
        return result_s;
    }
};

int main() {
    Solution solution;
    string result = solution.convert("aabaaaaa", 4);
    std::cout <<  result << std::endl;
    return 0;
}