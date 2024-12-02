#ifndef util_h
#define util_h

#include <vector>

namespace utilities {
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
}

#endif /* util_h */
