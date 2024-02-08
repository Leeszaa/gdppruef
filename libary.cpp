/**
 * @file library.cpp
 * @brief File containing the implementation of the Library class.
 */

#include "libary.hpp"
#include "handlers.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>

void Libary::addMagazine(const Magazine &magazine)
{
    magazines.push_back(magazine);
}

bool Libary::magazineExists(const std::string &issn)
{
    for (const Magazine &magazine : magazines)
    {
        if (magazine.issn == issn)
        {
            return true;
        }
    }
    return false;
}

void Libary::increaseStock(const std::string &issn, int increaseAmount)
{
    for (Magazine &magazine : magazines)
    {
        if (magazine.issn == issn)
        {
            magazine.stock += increaseAmount;
            break;
        }
    }
}

std::vector<Magazine *> Libary::searchByTitle(const std::string &title)
{
    std::vector<Magazine *> matchingMagazines;
    for (Magazine &magazine : magazines)
    {
        if (magazine.title == title)
        {
            matchingMagazines.push_back(&magazine);
        }
    }
    return matchingMagazines;
}

Magazine *Libary::searchByISSN(const std::string &issn)
{
    for (Magazine &magazine : magazines)
    {
        if (magazine.issn == issn)
        {
            return &magazine;
        }
    }
    return nullptr;
}

bool Libary::borrowMagazine(Magazine &magazine)
{
    if (magazine.stock > magazine.borrowedCopies)
    {
        magazine.borrowedCopies++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Libary::returnMagazine(Magazine &magazine)
{
    if (magazine.borrowedCopies > 0)
    {
        magazine.borrowedCopies--;
        return true;
    }
    else
    {
        return false;
    }
}

void Libary::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);
    for (const Magazine &magazine : magazines)
    {
        file << magazine.author << "\n"
             << magazine.title << "\n"
             << magazine.publisher << "\n"
             << magazine.issn << "\n"
             << magazine.stock << "\n"
             << magazine.publicationDate << "\n"
             << magazine.price << "\n"
             << magazine.borrowedCopies << "\n"; // Save borrowedCopies
    }
    file.close();
}

bool Libary::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string author, title, publisher, issn, publicationDate;
    int stock, borrowedCopies;
    double price;
    while (std::getline(file, author) &&
           std::getline(file, title) &&
           std::getline(file, publisher) &&
           std::getline(file, issn) &&
           file >> stock &&
           file >> publicationDate &&
           file >> price &&
           file >> borrowedCopies)
    {
        if (Utils::containsValidChars(author) &&
            Utils::containsValidChars(title) &&
            Utils::containsValidChars(publisher) &&
            Utils::isValidISSN(issn) &&
            Utils::isValidDate(publicationDate) &&
            stock >= 0 && price >= 0.00 && borrowedCopies >= 0)
        {
            // All fields are valid, add the magazine to the library
            magazines.push_back(Magazine(author, title, publisher, issn, stock, publicationDate, price));
            magazines.back().borrowedCopies = borrowedCopies; // Set borrowedCopies
             file.close();
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}