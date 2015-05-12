#ifndef  RANDOMCHAR_H
#define RANDOMCHAR_H

#include <cstdlib>
#include <string>

/// Just for picking a random char from an array of chars.
// also contains errors to fix, see program.cpp for instructions
// SUPER OPTIONAL BONUS: write a better random char generator. ;)
class RandomChar
{
private:
    static int const m_Length;
    static std::string const m_AllPossibleChars;
public:
    RandomChar();
    ~RandomChar();

    static char const getRandomChar()
    {
        return m_AllPossibleChars[rand() % m_Length];
    }
};

#endif // ! RANDOMCHAR_H
