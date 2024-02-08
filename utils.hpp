/**
 * @file utils.hpp
 * @brief Utility functions for the library management system
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

/**
 * @class Utils
 * @brief A utility class that provides static helper functions
 *
 * This class provides static functions that are used throughout the library management system.
 * These functions include validation checks for strings, ISSN, and dates.
 */
class Utils {
public:
 /**
     * @brief Check if a date is valid.
     *
     * This function checks if a date is valid. A date is considered valid if it is in the format DD.MM.YYYY,
     * the year is not negative, the month is between 1 and 12, and the day is between 1 and the number of days in the month.
     * The function also takes into account leap years when validating the day for February.
     * @param date The date to check.
     * @return true if the date is valid, false otherwise.
     */
    static bool isValidDate(const std::string &date);

    /**
     * @brief Check if a string contains invalid characters.
     *
     * This function checks if a string contains any characters that are not printable ASCII characters.
     * Printable characters are in the range 32 to 126.
     * @param str The string to check.
     * @return false if the string contains invalid characters, true otherwise.
     */
    static bool containsValidChars(const std::string &str);

        /**
     * @brief Checks if the given ISSN is valid.
     *
     * This function checks if the given ISSN is valid according to the ISSN format. An ISSN is valid if it is a 9-character string where the first 4 characters are digits, the 5th character is a hyphen, the next 3 characters are digits, and the last character is either a digit or the letter 'X'.
     *
     * @param issn The ISSN to check.
     * @return true If the ISSN is valid.
     * @return false If the ISSN is invalid.
     */
    static bool isValidISSN(const std::string &issn);
};

#endif // UTILS_HPP