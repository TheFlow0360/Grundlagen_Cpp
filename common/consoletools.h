#ifndef CONSOLETOOLS_H
#define CONSOLETOOLS_H

#include <string>
#include <list>
#include <cstdlib>

struct CornerSymbols {
    char topLeft;
    char topRight;
    char bottomLeft;
    char bottomRight;

    CornerSymbols(char const symbol) : topLeft(symbol), topRight(symbol), bottomLeft(symbol), bottomRight(symbol) {}
    CornerSymbols(char const topLeft, char const topRight, char const bottomLeft, char const bottomRight) : topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {}
};

struct BorderSymbols {
    CornerSymbols corners;
    char top;
    char left;
    char bottom;
    char right;

    BorderSymbols(char const symbol);
    BorderSymbols(char const borderSymbol, char const cornerSymbol);
    BorderSymbols(char const borderSymbol, CornerSymbols const cornerSymbols);
    BorderSymbols(char const verticalBorderSymbol, char const horizontalBorderSymbol, char const cornerSymbol);
    BorderSymbols(char const verticalBorderSymbol, char const horizontalBorderSymbol, CornerSymbols const cornerSymbols);
    BorderSymbols(char const topBorderSymbol, char const leftBorderSymbol, char const bottomBorderSymbol, char const rightBorderSymbol, char const cornerSymbol);
    BorderSymbols(char const topBorderSymbol, char const leftBorderSymbol, char const bottomBorderSymbol, char const rightBorderSymbol, CornerSymbols const cornerSymbols);
};

class ConsoleTools
{
private:
    static std::list<std::string> textToLines( std::string const &aText, unsigned int const aCharsPerLine );
public:
    ConsoleTools();

    static void clearScreen() {
#ifdef _WIN32
        if ( !std::system("cls") ) {};
#else
        if ( !std::system("clear") ) {};
#endif
    }

    static void printBox( std::string const &aTitle, char const aBorderSymbol = '#' );
    static void printBox( std::string const &aTitle, BorderSymbols const aBorderSymbols );
    static void printBox( std::string const &aTitle, std::string const &aText, char const aBorderSymbol = '#' );
    static void printBox( std::string const &aTitle, std::string const &aText, BorderSymbols const aBorderSymbols );
};

#endif // CONSOLETOOLS_H
