/**
 * @file handlers.hpp
 * @brief File containing the declaration of the Handler class.
 */

#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include "libary.hpp"
#include "utils.hpp"

/**
 * @class Handler
 * @brief Class responsible for handling user input and interactions with the Library.
 *
 * The Handler class is designed to interact with the user and the Library.
 * It contains methods for validating user input and performing actions
 * on the Library based on that input.
 */
class Handler
{
private:
    /**
     * @brief Reference to a Library object.
     *
     * This member is used to interact with the Library, such as adding
     * magazines, searching for magazines, etc.
     */
    Libary &libary;

public:
    /**
     * @brief Constructor that takes a reference to a Library object.
     *
     * This constructor initializes the libary member with the provided
     * Library object. This allows the Handler to interact with the Library.
     *
     * @param libary Reference to a Library object.
     */
    Handler(Libary &libary) : libary(libary) {} // constructor that takes a Library reference

    /**
     * @brief Get input from the user with validation.
     *
     * This function prompts the user for input and validates it using the provided validation function.
     * If the input is not valid, the function prompts the user again until they provide valid input.
     * @param prompt The prompt to display to the user.
     * @param validationFunc The function to use to validate the input.
     * @return The valid input from the user.
     */
    std::string getInputWithValidation(const std::string &prompt, bool (*validationFunc)(const std::string &));

    /**
     * @brief Get numeric input from the user with validation.
     *
     * This function prompts the user for numeric input and validates it. If the input is not a number,
     * the function prompts the user again until they provide a number.
     * @param prompt The prompt to display to the user.
     * @return The numeric input from the user.
     */
    int getNumericInputWithValidation(const std::string &prompt);

    /**
     * @brief Get double input from the user with validation.
     *
     * This function prompts the user for double input and validates it. If the input is not a number,
     * the function prompts the user again until they provide a number.
     * @param prompt The prompt to display to the user.
     * @return The double input from the user.
     */
    double getDoubleInputWithValidation(const std::string &prompt);

    /**
     * @brief Handle adding a magazine to the library.
     *
     * This function prompts the user for the details of a magazine and adds it to the library.
     * If a magazine with the same ISSN already exists in the library, the function increases the stock of the existing magazine.
     */
    void handleAddMagazine();

    /**
     * @brief Handles the search of a magazine by title in the library.
     *
     * This function prompts the user to enter a title, and then searches the library for a magazine with that title.
     * If a magazine is found, its details are printed to the console. If multiple magazines are found,
     * the details of all matching magazines are printed.
     *
     */
    void handleSearchByTitle();

    /**
     * @brief Handles the search of a magazine by ISSN in the library.
     *
     * This function prompts the user to enter an ISSN, and then searches the library for a magazine with that ISSN.
     * If a magazine is found, its details are printed to the console.
     *
     */
    void handleSearchByISSN();

    /**
     * @brief Handles the borrowing of a magazine.
     *
     * This function prompts the user to enter an ISSN. It validates the ISSN and if it's valid,
     * it attempts to borrow the magazine with that ISSN from the library. If the magazine is not found or
     * there are no copies left to borrow, it informs the user. Otherwise, it borrows the magazine and informs the user.
     */
    void handleBorrowMagazine();

    /**
     * @brief Handles the returning of a magazine.
     *
     * This function prompts the user to enter an ISSN. It validates the ISSN and if it's valid,
     * it attempts to return the magazine with that ISSN to the library. If the magazine is not found or
     * there are no borrowed copies left to return, it informs the user.
     */
    void handleReturnMagazine();

    /**
     * @brief Handles the exit operation from the library system.
     *
     * This function saves the current state of the library to a file and then exits the program.
     *
     */
    void handleExit();
};

#endif // HANDLERS_HPP