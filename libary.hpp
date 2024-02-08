/**
 * @file libary.hpp
 * @brief File containing the declaration of the Libary class.
 */

#include <vector>
#include <string>
#include "magazine.hpp"
#include "handlers.hpp"
#include "utils.hpp"

#ifndef LIBARY_HPP
#define LIBARY_HPP
/**
 * @class Libary
 * @brief Represents a library that stores magazines.
 *
 * @details This class provides methods to add and remove magazines, search for magazines by title or ISSN, borrow and return magazines, and save and load the library state from a file.
 */
class Libary
{
private:
    /**
     * @brief A list of all magazines in the library.
     *
     * This list contains all magazines that are currently in the library's inventory.
     * Each magazine in the list is represented by an instance of the Magazine class.
     */
    std::vector<Magazine> magazines;

public:
    /**
     * @brief Adds a magazine to the library.
     *
     * The magazine will be added to the library if it is not already in the library.
     * @param magazine The magazine to add.
     */
    void addMagazine(const Magazine &magazine);

    /**
     * @brief Check if a magazine exists in the library.
     *
     * This function checks if a magazine with a given ISSN exists in the library.
     * @param issn The ISSN of the magazine to check for.
     * @return true if a magazine with the given ISSN exists in the library, false otherwise.
     */
    bool magazineExists(const std::string &issn);

    /**
     * @brief Increase the stock of a magazine.
     *
     * This function increases the stock of a magazine with a given ISSN in the library.
     * If no magazine with the given ISSN exists in the library, the function does nothing.
     * @param issn The ISSN of the magazine to increase the stock of.
     * @param increaseAmount The amount to increase the stock by.
     */
    void increaseStock(const std::string &issn, int increaseAmount);

    /**
     * @brief Search for magazines by title.
     *
     * This function searches for magazines with a given title in the library.
     * It returns a vector of pointers to the matching magazines. If no magazines with the given title are found,
     * it returns an empty vector.
     * @param title The title to search for.
     * @return A vector of pointers to the matching magazines.
     */
    std::vector<Magazine *> searchByTitle(const std::string &title);

    /**
     * @brief Searches for a magazine by ISSN.
     *
     * This function searches for a magazine with a given ISSN in the library.
     * It returns a pointer to the magazine if found, nullptr otherwise.
     * @param issn The ISSN of the magazine to search for.
     * @return A pointer to the magazine if found, nullptr otherwise.
     */
    Magazine *searchByISSN(const std::string &issn);

    /**
     * @brief Borrow a magazine from the library.
     *
     * This function attempts to borrow a magazine from the library.
     * If the magazine has copies available, it increases the number of borrowed copies by 1 and returns true.
     * If no copies are available, it returns false.
     * @param magazine The magazine to borrow.
     * @return true if the magazine was successfully borrowed, false otherwise.
     */
    bool borrowMagazine(Magazine &magazine);

    /**
     * @brief Return a magazine to the library.
     *
     * This function attempts to return a borrowed magazine to the library.
     * If the magazine has borrowed copies, it decreases the number of borrowed copies by 1 and returns true.
     * If no copies are borrowed, it returns false.
     * @param magazine The magazine to return.
     * @return true if the magazine was successfully returned, false otherwise.
     */
    bool returnMagazine(Magazine &magazine);

    /**
     * @brief Saves the library state to a file.
     *
     * This function saves the state of the library to a file. The file will contain the details of all magazines in the library.
     * If no file with the given name exists, it will be created. If a file with the given name already exists, it will be overwritten.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string &filename);

    /**
     * @brief Loads the library state from a file.
     *
     * This function loads the state of the library from a file. The file should contain the details of all magazines in the library.
     * If the file does not exist, the function does nothing. The program will continue to run with the current library state.
     * @param filename The name of the file to load from.
     * @post The library state will be replaced with the state loaded from the file.
     */
    bool loadFromFile(const std::string &filename);
};

#endif // LIBARY_HPP