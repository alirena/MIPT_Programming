#include <iostream>
#include <vector>

std::string GetAnswer(std::vector<size_t>& function) {
    std::vector<size_t> prefix(function.size(), 0);
    for(size_t i = 1; i < function.size(); ++i) {
        if (function[i] != 0) {
            for(int j = function[i] - 1; j >= 0 && !(prefix[i + j]); j--) {
                prefix[i + j] = j + 1;
            }
        }
    }
    
    std::string answer = "a";
    std::vector<char> poss_symb_(prefix.size(), 'b');
    for (size_t i = 1; i < prefix.size(); ++i) {
        if (prefix[i] == 0) {
            answer += poss_symb_[i - 1];
            ++poss_symb_[i - 1];
            continue;
        }
        answer += answer[prefix[i] - 1];
        poss_symb_[i] = poss_symb_[prefix[i] - 1];
    }
    
    return answer;
}

int main() {
    std::vector<size_t> function;
    size_t item;
    while (std::cin >> item) {
        function.push_back(item);
    }
    std::string answer = GetAnswer(function);
    std::cout << answer;
    return 0;
}


