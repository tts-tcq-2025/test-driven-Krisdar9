#include "ParseandValidate.h"
#include "NegativeError.h"
#include <vector>
#include <string>
#include <stdexcept>

void processToken(
    const std::string& token,
    std::vector<int>& numbers,
    std::vector<int>& negatives) {
    if (token.empty())
        return;

    int number = std::stoi(token);

    if (number < 0) {
        negatives.push_back(number);
    } else if (number <= 1000) {
        numbers.push_back(number);
    }
}
std::vector<int> parseAndValidate(const std::vector<std::string>& tokens) {
    std::vector<int> numbers;
    std::vector<int> negatives;

    for (const auto& token : tokens) {
        processToken(token, numbers, negatives);
    }

    if (!negatives.empty()) {
        throw std::invalid_argument(formatNegativeError(negatives));
    }

    return numbers;
}
