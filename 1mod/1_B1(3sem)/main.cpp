#include <iostream>
#include <vector>

std::string GetAnswer(std::vector<size_t>& function) {
    std::string answer = "a";
    std::vector<char> poss_symb_(function.size(), 'b');
    for (size_t i = 1; i < function.size(); ++i) {
        if (function[i] == 0) {
            answer += poss_symb_[i - 1];
            ++poss_symb_[i - 1];
            continue;
        }
        answer += answer[function[i] - 1];
        poss_symb_[i] = poss_symb_[function[i] - 1];
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
