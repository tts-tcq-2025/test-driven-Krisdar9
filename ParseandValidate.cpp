#include "parse_and_validate.h"
#include "format_negative_error.h"
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
