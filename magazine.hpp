/**
 * @file magazine.hpp
 * @brief File containing the declaration of the Magazine class.
 */

#include <string>

#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

/**
 * @class Magazine
 * 
 * A class representing a magazine in a library. It contains information about the author, title, publisher, ISSN, stock, publication date, price, and how many magazines are borrowed.
 *
 * @brief A class representing a magazine in a library.
 */
class Magazine {
public:
    std::string author;  ///< The author of the magazine.
    std::string title;  ///< The title of the magazine.
    std::string publisher;  ///< The publisher of the magazine.
    std::string issn;  ///< The ISSN of the magazine.
    int stock;  ///< The number of copies of the magazine in stock.
    std::string publicationDate;  ///< The publication date of the magazine.
    double price;  ///< The price of the magazine.
    int borrowedCopies;  ///< The number of copies of the magazine that are currently borrowed.

    /**
     * @brief Construct a new Magazine object.
     * 
     * @param author The author of the magazine.
     * @param title The title of the magazine.
     * @param publisher The publisher of the magazine.
     * @param issn The ISSN of the magazine.
     * @param stock The number of copies of the magazine in stock.
     * @param publicationDate The publication date of the magazine.
     * @param price The price of the magazine.
     * @param borrowedCopies The number of copies of the magazine that are currently borrowed.
     */
    Magazine(std::string author, std::string title, std::string publisher, std::string issn, int stock, std::string publicationDate, double price)
    : author(author), title(title), publisher(publisher), issn(issn), stock(stock), publicationDate(publicationDate), price(price), borrowedCopies(0) {}
};
#endif // MAGAZINE_HPP