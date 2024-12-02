#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    
    res.push_back(s.substr(pos_start));
    return res;
}

int count(std::vector<int> v, int n) {
    int result = 0;
    for (auto a : v) {
        if (a == n)
            result += 1;
    }
    
    return result;
}

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
        result += a[i] * count(b, a[i]);
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
        std::vector<std::string> nums = split(text, "   ");
        
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
