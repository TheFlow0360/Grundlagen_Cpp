#ifndef CONSOLETOOLS_H
#define CONSOLETOOLS_H

#include <string>
#include <list>

class ConsoleTools
{
private:
    static std::list<std::string> textToLines( std::string const &aText, int const aCharsPerLine );

public:
    ConsoleTools();

    static void printBox( std::string const &aTitle, char const aBorderSymbol );
    static void printBox( std::string const &aTitle, std::string const &aText, char const aBorderSymbol );
};

#endif // CONSOLETOOLS_H
