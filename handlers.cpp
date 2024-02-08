/**
 * @file handlers.cpp
 * @brief File containing the implementation of the Handler class.
 */
#include "handlers.hpp"
#include "utils.hpp"
#include <iostream>
#include <cctype>
#include <limits>

Libary libary;

std::string Handler::getInputWithValidation(const std::string& prompt, bool (*validationFunc)(const std::string&)) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (validationFunc(input)) {
            break;
        } else {
            std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut.\n";
        }
    } while (true);
    return input;
}

int Handler::getNumericInputWithValidation(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cout << "Ungueltige Eingabe. Bitte geben sie eine ganzzahlige Nummer ein.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

double Handler::getDoubleInputWithValidation(const std::string& prompt) {
    double input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cout << "Ungueltige Eingabe. Bitte geben sie eine Nummer ein. Moegliche Eingaben sind: XX.XX oder X.XX (X für Zahl).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

void Handler::handleAddMagazine() {
    std::string author = getInputWithValidation("Autor eigeben (keine Umlaute oder Sonderzeicehn): ", Utils::containsValidChars);
    std::string title = getInputWithValidation("Titel eingeben (keine Umlaute oder Sonderzeicehn): ", Utils::containsValidChars);
    std::string publisher = getInputWithValidation("Verlag eingeben (keine Umlaute oder Sonderzeicehn): ", Utils::containsValidChars);
    std::string issn = getInputWithValidation("ISSN eingeben: ", Utils::isValidISSN);
    int stock = getNumericInputWithValidation("Anzahl im Lager eingeben: ");
    std::string publicationDate = getInputWithValidation("Veroeffentlichungsdatum eingeben (DD.MM.YYYY): ", Utils::isValidDate);
    double price = getDoubleInputWithValidation("Preis eingeben (in Euro ohne Währungszeichen): ");

    if (libary.magazineExists(issn)) {
        libary.increaseStock(issn, stock);
        std::cout << "Ein Magazin mit der ISSN " << issn << " existiert bereits. Die Anzahl im Lager wird um " << stock << " erhöht.\n";
        std::cout << "------------------------\n";
    } else {
        libary.addMagazine(Magazine(author, title, publisher, issn, stock, publicationDate, price));
    }
}

void Handler::handleSearchByTitle() {
    std::string title = getInputWithValidation("Titel eingeben: ", Utils::containsValidChars);
    std::vector<Magazine*> magazines = libary.searchByTitle(title);
    if (!magazines.empty()) {
        std::cout << "Magazin(e) gefunden: \n";
        for (Magazine* magazine : magazines) {
            std::cout << "Author: " << magazine->author << "\n";
            std::cout << "Titel: " << magazine->title << "\n";
            std::cout << "Verlag: " << magazine->publisher << "\n";
            std::cout << "ISSN: " << magazine->issn << "\n";
            std::cout << "Erscheinungsdatum: " << magazine->publicationDate << "\n";
            std::cout << "Preis: " << magazine->price << " Euro\n";
            std::cout << "Anzahl im Lager: " << magazine->stock << "\n";
            std::cout << "Davon ausgeliehen: " << magazine->borrowedCopies << "\n";
            std::cout << "------------------------\n";
        }
    } else {
        std::cout << "Magazin nicht gefunden\n";
        std::cout << "------------------------\n";
    }
}

void Handler::handleSearchByISSN()
{
    std::string issn;
    do
    {
        std::cout << "ISSN eingeben: ";
        std::getline(std::cin, issn);
        if (Utils::isValidISSN(issn))
        {
            break;
        }
        else
        {
            std::cout << "Ungueltiges ISSN Format. ISSN sollte ein 8-Zahliger Code im Format XXXX-XXXX sein.\n";
        }
    } while (true);
    Magazine *magazine = libary.searchByISSN(issn);
    if (magazine)
    {
        std::cout << "Magazin gefunden: "
                  << "\n";
        std::cout << "Autor: " << magazine->author << "\n";
        std::cout << "Titel: " << magazine->title << "\n";
        std::cout << "Verlag: " << magazine->publisher << "\n";
        std::cout << "ISSN: " << magazine->issn << "\n";
        std::cout << "Erscheinungsdatum: " << magazine->publicationDate << "\n";
        std::cout << "Preis: " << magazine->price << " Euro\n";
        std::cout << "Anzahl im Lager: " << magazine->stock << "\n";
        std::cout << "Davon ausgeliehen: " << magazine->borrowedCopies << "\n";
        std::cout << "------------------------\n";
    }
    else
    {
        std::cout << "Magazin nicht gefunden\n";
        std::cout << "------------------------\n";
    }
}

void Handler::handleBorrowMagazine()
{
    std::string issn;
    do
    {
        std::cout << "ISSN eingeben: ";
        std::getline(std::cin, issn);
        if (Utils::isValidISSN(issn))
        {
            break;
        }
        else
        {
            std::cout << "Ungueltiges ISSN Format. ISSN sollte ein 8-Zahliger Code im Format XXXX-XXXX sein.\n";
        }
    } while (true);
    Magazine *magazine = libary.searchByISSN(issn);
    if (magazine) {
        if (libary.borrowMagazine(*magazine)) {
            std::cout << "Magazin wurde ausgeliehen\n";
            std::cout << "------------------------\n";
        } else {
            std::cout << "Keine Exemplare zum Ausleihen vorhanden.\n";
            std::cout << "------------------------\n";
        }
    } else {
        std::cout << "Magazin nicht gefunden\n";
        std::cout << "------------------------\n";
    }
}

void Handler::handleReturnMagazine()
{
    std::string issn;
    do
    {
        std::cout << "ISSN eingeben: ";
        std::getline(std::cin, issn);
        if (Utils::isValidISSN(issn))
        {
            break;
        }
        else
        {
            std::cout << "Ungueltiges ISSN Format. ISSN sollte ein 8-Zahliger Code im Format XXXX-XXXX sein.\n";
        }
    } while (true);
    Magazine *magazine = libary.searchByISSN(issn);
    if (magazine) {
        if (libary.returnMagazine(*magazine)) {
            std::cout << "Magazin wurde zurueckgegeben\n";
            std::cout << "------------------------\n";
        } else {
            std::cout << "Keine ausgeliehenen Exemplare zum Zurueckgeben vorhanden.\n";
            std::cout << "------------------------\n";
        }
    } else {
        std::cout << "Magazin nicht gefunden\n";
        std::cout << "------------------------\n";
    }
}

void Handler::handleExit()
{
    libary.saveToFile("magazine.txt");
    exit(0);                           // Exit the program
}