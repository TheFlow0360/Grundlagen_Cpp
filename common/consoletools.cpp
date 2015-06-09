#include "consoletools.h"

#include <iostream>
#include <locale>
#include <string>
#include <list>

#define BOXMAXSIZE 60

using namespace std;

ConsoleTools::ConsoleTools()
{
}

list<string> ConsoleTools::textToLines( string const &aText, unsigned int const aCharsPerLine)
{
    size_t curpos = 0;
    size_t nextpos = 0;

    list<string> lines;
    string substr = aText.substr( curpos, aCharsPerLine + 1 );

    while ( substr.length() == aCharsPerLine + 1 && ( nextpos = substr.rfind( ' ' ) ) != aText.npos ) {
        lines.push_back( aText.substr( curpos, nextpos ) );
        curpos += nextpos + 1;
        substr = aText.substr( curpos, aCharsPerLine + 1 );
    }

    if ( curpos != aText.length() )
        lines.push_back( aText.substr( curpos, aText.npos ) );

    return lines;
}

void ConsoleTools::printBox( string const &aTitle, char const aBorderSymbol )
{
    ConsoleTools::printBox( aTitle, "", BorderSymbols( aBorderSymbol ) );
}

void ConsoleTools::printBox( string const &aTitle, BorderSymbols const aBorderSymbols )
{
    ConsoleTools::printBox( aTitle, "", aBorderSymbols );
}

void ConsoleTools::printBox( string const &aTitle, string const &aText, char const aBorderSymbol )
{
    ConsoleTools::printBox( aTitle, aText, BorderSymbols( aBorderSymbol ) );
}

void ConsoleTools::printBox(const string &aTitle, const string &aText, const BorderSymbols aBorderSymbols)
{
    unsigned int width = min( BOXMAXSIZE, ( int ( max( aTitle.size(), aText.size() ) ) ) );
    unsigned int boxWidth = width + 4;
    list<string> lines = ConsoleTools::textToLines(aText, width);
    unsigned int boxHeight = 3 + ( lines.size() > 0 ? lines.size() + 1 : 0 );

    for ( unsigned int i = 0; i < boxHeight; i++ ) {
        if ( i == 0 ) {
            cout << aBorderSymbols.corners.topLeft;
            for ( unsigned int j = 1; j < ( boxWidth - 1 ); j++ ) {
                cout << aBorderSymbols.top;
            }
            cout << aBorderSymbols.corners.topRight << endl;
        } else if ( i == ( boxHeight - 1 ) ) {
            cout << aBorderSymbols.corners.bottomLeft;
            for ( unsigned int j = 1; j < ( boxWidth - 1 ); j++ ) {
                cout << aBorderSymbols.bottom;
            }
            cout << aBorderSymbols.corners.bottomRight << endl;
        } else {
            cout << aBorderSymbols.left << " ";

            if ( i == 1 ) {
                unsigned int k = 0;
                while ( k < ( width - aTitle.size() ) / 2 ) {
                    cout << " ";
                    k++;
                }
                cout << aTitle;
                k += aTitle.size();
                while ( k < width ) {
                    cout << " ";
                    k++;
                }
            } else if ( i == 2 ) {
                for ( unsigned int k = 0; k < width; k++ ) {
                    cout << " ";
                }
            } else {
                string line = lines.front();
                unsigned int k = line.size();
                cout << line;
                while ( k < width ) {
                    cout << " ";
                    k++;
                }
                lines.pop_front();
            }

            cout << " " << aBorderSymbols.right << endl;
        }
    }
    cout << endl;
}


BorderSymbols::BorderSymbols(char const symbol) :
    corners( CornerSymbols( symbol ) ),
    top( symbol ),
    left( symbol ),
    bottom( symbol ),
    right( symbol )
{}

BorderSymbols::BorderSymbols(char const borderSymbol, char const cornerSymbol) :
    corners( CornerSymbols( cornerSymbol ) ),
    top( borderSymbol ),
    left( borderSymbol ),
    bottom( borderSymbol ),
    right( borderSymbol )
{}

BorderSymbols::BorderSymbols(char const borderSymbol, CornerSymbols const cornerSymbols) :
    corners( cornerSymbols ),
    top( borderSymbol ),
    left( borderSymbol ),
    bottom( borderSymbol ),
    right( borderSymbol )
{}

BorderSymbols::BorderSymbols(char const verticalBorderSymbol, char const horizontalBorderSymbol, char const cornerSymbol) :
    corners( CornerSymbols( cornerSymbol ) ),
    top( horizontalBorderSymbol ),
    left( verticalBorderSymbol ),
    bottom( horizontalBorderSymbol ),
    right( verticalBorderSymbol )
{}

BorderSymbols::BorderSymbols(char const verticalBorderSymbol, char const horizontalBorderSymbol, CornerSymbols const cornerSymbols) :
    corners( cornerSymbols ),
    top( horizontalBorderSymbol ),
    left( verticalBorderSymbol ),
    bottom( horizontalBorderSymbol ),
    right( verticalBorderSymbol )
{}

BorderSymbols::BorderSymbols(char const topBorderSymbol, char const leftBorderSymbol, char const bottomBorderSymbol, char const rightBorderSymbol, char const cornerSymbol) :
    corners( CornerSymbols( cornerSymbol ) ),
    top( topBorderSymbol ),
    left( leftBorderSymbol ),
    bottom( bottomBorderSymbol ),
    right( rightBorderSymbol )
{}

BorderSymbols::BorderSymbols(char const topBorderSymbol, char const leftBorderSymbol, char const bottomBorderSymbol, char const rightBorderSymbol, CornerSymbols const cornerSymbols) :
    corners( cornerSymbols ),
    top( topBorderSymbol ),
    left( leftBorderSymbol ),
    bottom( bottomBorderSymbol ),
    right( rightBorderSymbol )
{}
