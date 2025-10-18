#include "StringCalculator.h"
#include "ExtractDelimiters.h"
#include "SplitNumbers.h"
#include "ParseandValidate.h"

namespace {

//  Helper: Checks if input has a custom delimiter line
bool isCustomDelimiter(const std::string& input) {
    return input.rfind("//", 0) == 0;
}

//  Helper: Extracts header and remaining string
std::pair<std::string, std::string> parseHeaderAndBody(const std::string& input) {
    size_t newlinePos = input.find('\n');
    if (newlinePos == std::string::npos)
        throw std::invalid_argument("Invalid delimiter declaration.");

    std::string header = input.substr(2, newlinePos - 2);
    std::string body = input.substr(newlinePos + 1);
    return { header, body };
}

}   // namespace

//  Main method with CCN ≤ 3
int StringCalculator::add(const std::string& input) {
    if (input.empty())
        return 0;

    std::string numbers = input;
    std::vector<std::string> delimiters = {",", "\n"};

    if (isCustomDelimiter(input)) {
        auto [header, body] = parseHeaderAndBody(input);
        delimiters = extractDelimiters(header);
        numbers = body;
    }

    auto tokens = splitNumbers(numbers, delimiters);
    auto validNumbers = parseAndValidate(tokens);

    int sum = 0;
    for (int num : validNumbers)
        sum += num;

    return sum;
}
