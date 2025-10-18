#include "StringCalculator.h"
#include "ExtractDelimiters.h"
#include "SplitNumbers.h"
#include "ParseandValidate.h"

int StringCalculator::add(const std::string& input) {
    if (input.empty()) return 0;

    std::string numbers = input;
    std::vector<std::string> delimiters = {",", "\n"};

    if (numbers.rfind("//", 0) == 0) {
        size_t newlinePos = numbers.find('\n');
        if (newlinePos == std::string::npos)
            throw std::invalid_argument("Invalid delimiter declaration.");

        std::string header = numbers.substr(2, newlinePos - 2);
        delimiters = extractDelimiters(header);
        numbers = numbers.substr(newlinePos + 1);
    }

    auto tokens = splitNumbers(numbers, delimiters);
    auto validNumbers = parseAndValidate(tokens);

    int sum = 0;
    for (int num : validNumbers)
        sum += num;

    return sum;
}
