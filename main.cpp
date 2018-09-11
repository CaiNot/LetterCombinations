#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    string values[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> curList, lastList = {""}, newList;
        if (digits.length() < 1)
            return curList;
        string temp;
        int lengthDig = digits.size(), lengthVal = 0, position = 0;
        for (int i = 0; i < lengthDig; i++) {
            position = digits[i] - '2';
            lengthVal = values[position].size();
            for (int j = 0; j < lengthVal; j++) {
                temp = values[position][j];
                curList.push_back(temp);
            }
            for (int k = 0; k < curList.size(); k++) {
                for (int n = 0; n < lastList.size(); n++) {
                    newList.push_back(lastList[n] + curList[k]);
                }
            }
            lastList = newList;
            curList.clear();
            newList.clear();
        }
        return lastList;
    }

    void backTrace(){
        
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    auto results = s.letterCombinations("");
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}