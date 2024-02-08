/**
 * @file main.cpp
 * @brief Main entry point of the application.
 *
 * This file includes the main function that is the entry point of the application.
 * It includes the necessary headers and starts the application.
 */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
#include <limits>

#include "libary.hpp"
#include "handlers.hpp"
#include "utils.hpp"

/**
 * @brief The main function and entry point of the application.
 *
 * This function creates a Library and a Handler object, loads the magazines from a file,
 * and then enters a loop where it presents a menu to the user and handles their choice.
 * The loop continues until the user chooses to exit.
 *
 * @return int The exit status of the application. 0 for success, non-zero for failure.
 */
int main()
{
    Libary libary;
    Handler handler(libary);
    bool fileLoaded = libary.loadFromFile("magazine.txt");

    if (!fileLoaded)
    {
        std::cout << "Die Magazindatenbank wurde nicht gefunden oder ist beschaedigt oder ist im falschen Format. \n"
                  << "Moechten Sie ohne Datenbank weiter machen? Es wird dann eine neue Datenbank erstellt. (J/N):";
        char choice;
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            std::cout << "Das Programm wurde beendet.\n";
            return 0; // Exit the program
        }
    }
    while (true)
    {
        std::cout << "1. Magazin hinzufuegen\n"
                  << "2. Suche via Titel\n"
                  << "3. Suche via ISSN\n"
                  << "4. Magazin ausleihen\n"
                  << "5. Magazin zurueckgeben\n"
                  << "6. Beenden\n"
                  << "Geben Sie Ihre Auswahl ein: ";
        int choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
            std::cout << "Ungueltige Auswahl. Bitte geben Sie eine Nummer zwischen 1 und 6 ein.\n";
            continue; // skip the rest of the loop
        }
        std::cin.ignore(); // ignore newline at the end of the input
        switch (choice)
        {
        case 1:
            handler.handleAddMagazine();
            break;
        case 2:
            handler.handleSearchByTitle();
            break;
        case 3:
            handler.handleSearchByISSN();
            break;
        case 4:
            handler.handleBorrowMagazine();
            break;
        case 5:
            handler.handleReturnMagazine();
            break;
        case 6:
            std::cout << "Das Programm wurde beendet und die Datenbank gespeichert.\n";
            handler.handleExit();
            break;
        default:
            std::cout << "Ungueltige Auswahl. Bitte geben Sie eine Nummer zwischen 1 und 6 ein.\n";
            break;
        }
    }
    return 0;
}