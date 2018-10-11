#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void zfunction(const std::string & temp){
    std::string str = temp + "#";
    std::string text = "";
    std::vector <size_t> zf(temp.length() + 1, 0);
    size_t size = temp.length();
    size_t left = 0, right = 0;
    size_t pos = temp.length();
    
    for (size_t i = 1; i < size + 1; i++) {
        if (i <= right) {
            zf[i] = std::min(right - i + 1, zf[i - left]);
        }
        while (i + zf[i] < size + 1 && str[zf[i]] == str[zf[i] + i]) {
            zf[i]++;
        };
        if (i + zf[i] - 1 > right) {
            left = i;
            right = zf[i] + i - 1;
        }
    }
    
    
    bool cont = true;
    char ch = std::cin.get();
    while(cont) {
        text = str + text;
        char symb;
        for (int i = 0; i < 2 * size; i++) {
            if (std::cin.get(symb) && symb != '\n') {
                text += symb;
                cont = true;
            } else cont = false;
        }
        
        size_t begin = size + 1;
        size_t end = text.length() - size + 1;
        size_t k = 0;
        for (size_t i = begin; i < end; i++) {
            pos++;
            if (pos <= right) {
                k = std::min(right - pos + 1, zf[pos - left]);
            }
            while (i + k < text.length() && text[k] == text[k + i]) {
                k++;
            };
            if (pos + k - 1> right) {
                left = pos;
                right = k + pos - 1;
            }
            if (k == size) {
                printf("%d ", pos - size - 1);
            }
        }
        std::string newText = "";
        for (int i = 0; i < size - 1; i++) {
            newText += text[end + i];
        }
        text = newText;
    }
}

int main() {
    std::string temp;
    std::cin >> temp;
    zfunction(temp);
    return 0;
}
