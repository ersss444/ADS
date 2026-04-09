#include <iostream>
#include <vector>
#include <string>

int MA

void generatePermutationsWithRepetition(const std::vector<char>& elements, std::string current_permutation, int remaining_length) {
    if (remaining_length == 0) {
        std::cout << current_permutation << std::endl;
        return;
    }

    for (char element : elements) {
        generatePermutationsWithRepetition(elements, current_permutation + element, remaining_length - 1);
    }
}

int main() {
    std::vector<char> elements = {'+', '-', '*', '/'};
    int permutation_length = 4;
    generatePermutationsWithRepetition(elements, "", permutation_length);

    return 0;
}
