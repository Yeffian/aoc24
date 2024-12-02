#include <iostream>
#include <fstream>
#include "util.h"

int solve1(std::vector<int> a, std::vector<int> b) {
    int result = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    for (int i = 0; i < a.size(); i++) {
        result += abs(a[i] - b[i]);
    }
    
    return result;
}

int solve2(std::vector<int> a, std::vector<int> b) {
    int result = 0;
    
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * utilities::count(b, a[i]);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    std::string text;
    std::ifstream data("./day1.txt");
    
    std::vector<int> a;
    std::vector<int> b;
    
    std::cout << "here" << std::endl;
    while (getline(data, text)) {
        std::vector<std::string> nums = utilities::split(text, "   ");
        
        int x = stoi(nums[0]);
        int y = stoi(nums[1]);
        
        a.push_back(x);
        b.push_back(y);
    }
    
    data.close();
    
    std::cout << solve1(a, b) << std::endl;
    std::cout << solve2(a, b) << std::endl;
    
    return 0;
}
