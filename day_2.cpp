#include <iostream>
#include <fstream>
#include "util.h"

bool isSafe(const std::vector<int>& report) {
    if (report.size() < 2) return false;

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];
        
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }
        
        if (diff > 0) {
            isDecreasing = false;
        } else if (diff < 0) {
            isIncreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}

int solve1(std::vector<std::vector<int>> report) {
    int result = 0;
    for (auto level : report)
        if (isSafe(level))
            result += 1;
    return result;
}


int main(int argc, const char * argv[]) {
    std::string text;
    std::ifstream data("./day2.txt");
    
    std::vector<std::vector<int>> report;
    
    while (getline(data, text)) {
        std::vector<std::string> nums = utilities::split(text, " ");
        std::vector<int> levels;
        
        for (auto n : nums) {
            levels.push_back(stoi(n));
        }
        
        report.push_back(levels);
    }
    
    data.close();
    
    std::cout << solve1(report) << std::endl;
    
    return 0;
}
