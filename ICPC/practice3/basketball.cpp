// Problem A: Basketball One-on-One
// Link: https://open.kattis.com/contests/qd7hf2/problems/basketballoneonone

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int scoreA = 0, scoreB = 0;
    bool lead2Needed = false;
    for (int i = 0; i < input.size(); i+=2) {
        char player = input[i];
        int points = atoi(&input[i + 1]);

        if (player == 'A') {
            scoreA += points;
        } else {
            scoreB += points;
        }
        if (scoreA == 10 && scoreB == 10)
            lead2Needed = true;
        
        if (lead2Needed) {
            bool Blead2 = (scoreB - scoreA >= 2);
            bool Alead2 = (scoreA - scoreB >= 2);
            if (Blead2)
                std::cout << 'B' << std::endl;
            else if (Alead2) 
                std::cout << 'A' << std::endl;
            else 
                continue;
        }

        if (!lead2Needed) {
            if (scoreA >= 11)
                std::cout << 'A' << std::endl;
            else if (scoreB >= 11) 
                std::cout << 'B' << std::endl;
        }
    }
    return 0;
}