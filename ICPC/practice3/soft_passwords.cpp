// Problem I: Soft Passwords
// Link: https://open.kattis.com/contests/qd7hf2/problems/softpasswords

#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

std::string reverse(std::string in) {
    std::string out = "";
    for (int i = 0; i < in.length(); i++) {
        if (isalpha(in[i]) && islower(in[i])) {
            out += toupper(in[i]);
        } else if (isdigit( (int) in[i] )) {
            out += in[i];
        } else {
            out += tolower(in[i]);
        }
    }
    return out;
}

int main() {
    std::string s;
    std::string p;
    std::cin >> s;
    std::cin >> p;

    if (s == p) {
        std::cout << "Yes" << std::endl;
    } else if (isdigit( (int) s[0] ) && (p.length() == s.length() - 1)) {
        std::cout << "Yes" << std::endl;
    } else if (isdigit( (int) s[s.length()-1] ) && (p.length() == s.length() - 1)) {
        std::cout << "Yes" << std::endl;
    } else if (s == reverse(p)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
