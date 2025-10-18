#include <vector>
#include <string>
#include "ParseandValidate.h"
#include "NegativeError.h"
#include <stdexcept>

std::vector<int> parseAndValidate(const std::vector<std::string>& tokens) {
    std::vector<int> numbers;
    std::vector<int> negatives;

    for (const auto& token : tokens) {
        if (token.empty()) continue;
        int number = std::stoi(token);
        if (number < 0)
            negatives.push_back(number);
        else if (number <= 1000)
            numbers.push_back(number);
    }

    if (!negatives.empty()) {
        throw std::invalid_argument(formatNegativeError(negatives));
    }

    return numbers;
}
