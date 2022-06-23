#pragma once

#include <iostream>
#include <random>
#include <vector>

struct setting
{
    int passwordLength{};
    bool includeSymbol{};
    bool includeNumber{};
    bool includeLowercaseChar{};
    bool includeUppercaseChar{};
};

int randomNumber(int min, int max)
{

    std::random_device rd;
    std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution dist{ min, max };
    return dist(mt);
}

std::string generatePassword(setting settings)
{

    std::string generatedPassword;

    std::string lowerCaseSets = "abcdefghijklmnopqrstuvwxyz";
    std::string upperrCaseSets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numbersSets = "0123456789";
    std::string symbolsSets = " ~!@#$%^&*()-=+[{]}\\;:'""/?.>,<";

    std::string finalCharSet;

    int min = 0, max = 0;


    if (settings.includeNumber == true)
    {
        finalCharSet = finalCharSet + numbersSets;
        max += 10;
    }
    if (settings.includeLowercaseChar == true)
    {
        finalCharSet = finalCharSet + lowerCaseSets;
        max += 26;
    }
    if (settings.includeUppercaseChar == true)
    {
        finalCharSet = finalCharSet + upperrCaseSets;
        max += 26;
    }
    if (settings.includeSymbol == true)
    {
        finalCharSet = finalCharSet + symbolsSets;
        max += 29;
    }

    for (int i = 1; i <= settings.passwordLength; ++i)
    {
        generatedPassword += finalCharSet[randomNumber(min, max)];
    }



    return generatedPassword;
}