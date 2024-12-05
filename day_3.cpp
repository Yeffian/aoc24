#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include "util.h"

int solve1(std::string txt) {
    int result = 0;
    std::regex s(R"(mul\(\d*,\d*\))");

    auto it = std::sregex_iterator(txt.begin(), txt.end(), s);
    auto end = std::sregex_iterator();

    for (; it != end; ++it) {
        auto contents = it->str();
        contents.replace(0, 3, "");
        auto parts = utilities::split(contents, ",");
        std::string n1 = parts[0];
        std::string n2 = parts[1];
        n1.replace(0, 1, "");
        
        n2.replace(n2.find(")"), 1, "");
        
        result += (stoi(n1) * stoi(n2));
    }
    
    return result;
}

int solve2() {
    int result = 0;
    return result;
}


int main(int argc, const char * argv[]) {
    int res = 0;
    
    std::string text;
    std::ifstream data("./day3.txt");
        
    while (getline(data, text)) {
        res += solve1(text);
    }
    
    data.close();
    
    std::cout << res << std::endl;
    
//    std::cout << solve1("xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))") << std::endl;
//    std::cout << solve2() << std::endl;
    
    return 0;
}
