#include "consoletools.h"

#include <iostream>
#include <string>
#include <list>

#define BOXMAXSIZE 60

using namespace std;

ConsoleTools::ConsoleTools()
{
}

list<string> ConsoleTools::textToLines(const string &aText, const int aCharsPerLine)
{
    size_t curpos = 0;
    size_t nextpos = 0;

    list<string> lines;
    string substr = aText.substr(curpos, aCharsPerLine + 1);

    while (substr.length() == aCharsPerLine + 1 && (nextpos = substr.rfind(' ')) != aText.npos) {
        lines.push_back(aText.substr(curpos, nextpos));
        curpos += nextpos + 1;
        substr = aText.substr(curpos, aCharsPerLine + 1);
    }

    if (curpos != aText.length())
        lines.push_back(aText.substr(curpos, aText.npos));

    return lines;
}

void ConsoleTools::printBox( string const &aTitle, char const aBorderSymbol )
{
     ConsoleTools::printBox( aTitle, "", aBorderSymbol );
}

void ConsoleTools::printBox( string const &aTitle, string const &aText, char const aBorderSymbol )
{
    unsigned int width = min( BOXMAXSIZE, ( int ( max( aTitle.size(), aText.size() ) ) ) );
    unsigned int boxWidth = width + 4;
    list<string> lines = ConsoleTools::textToLines(aText, width);
    unsigned int boxHeight = 3 + ( lines.size() > 0 ? lines.size() + 1 : 0 );

    for ( int i = 0; i < boxHeight; i++ ) {
        if ( ( i == 0 ) || ( i == ( boxHeight - 1 ) ) ) {
            for ( int j = 0; j < boxWidth; j++ ) {
                cout << aBorderSymbol;
            }
            cout << endl;
        } else {
            cout << aBorderSymbol << " ";

            if ( i == 1 ) {
                int k = 0;
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
                for ( int k = 0; k < width; k++ ) {
                    cout << " ";
                }
            } else {
                string line = lines.front();
                int k = line.size();
                cout << line;
                while ( k < width ) {
                    cout << " ";
                    k++;
                }
                lines.pop_front();
            }

            cout << " " << aBorderSymbol << endl;
        }
    }
    cout << endl;
}
