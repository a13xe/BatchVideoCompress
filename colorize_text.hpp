#ifndef COLORIZE_HPP
#define COLORIZE_HPP
#include <iostream>
#include <string>


// ANSI color codes
enum Color 
{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    BRIGHT_BLACK = 90,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN,
    BRIGHT_WHITE
};


// Print colorized text
void colorized_print(const std::string& message, Color textColor, Color bgColor, int boldness)
{
    std::string colorCode = "\033[";

    if (boldness == 1)
    {
        colorCode += "1;";
    }

    colorCode += std::to_string(textColor) + ";" + std::to_string(bgColor + 10) + "m";

    std::cout << colorCode << message << "\033[0m";
}


#endif // COLORIZE_HPP
