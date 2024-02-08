#include "utils.hpp"
#include <string>

bool Utils::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[2] != '.' || date[5] != '.') {
        return false;
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if (year < 0) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

bool Utils::containsValidChars(const std::string& str) {
    for (char c : str) {
        if (c < 32 || c > 126) {
            return false;
        }
    }
    return true;
}

bool Utils::isValidISSN(const std::string &issn)
{
    if (issn.length() != 9 || issn[4] != '-')
    {
        return false;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!std::isdigit(issn[i]))
        {
            return false;
        }
    }
    for (int i = 5; i < 8; ++i)
    {
        if (!std::isdigit(issn[i]))
        {
            return false;
        }
    }
    if (!std::isdigit(issn[8]) && !(std::isalpha(issn[8]) && std::toupper(issn[8]) == 'X'))
    {
        return false;
    }
    return true;
}