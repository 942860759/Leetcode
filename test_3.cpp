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
    bool ifSameString(string s) {
        std::map<std::string, int> key_map = {};
        for (int i = 0 ; i < s.size(); i++) {
            std::map<std::string, int>::iterator it = key_map.begin();
            while ( it != key_map.end()) {
                if (std::to_string(s[i]) == it->first.c_str())
                    return true;
                ++it;
            }
            key_map[std::to_string(s[i])] = 1;
        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int tmp = 0;
        for (int i = 0 ; i < s.size(); i++) {
            std::map<char, int> key_map = {};
            int start = i;
            for (int j = i; j < s.size(); j++) {
                if (key_map.find(s[j]) == key_map.end()) {
                    // not found
                    key_map[s[j]] = 1;
                } else {
                    // found
                    tmp = j - i;
                    if (tmp > maxLength)
                        maxLength = tmp;
                    break;
                }

                if (maxLength < (j - i + 1))
                    maxLength = (j - i + 1);
            }
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    int maxLength = solution.lengthOfLongestSubstring("aab");
    std::cout <<  maxLength << std::endl;
    return 0;
}