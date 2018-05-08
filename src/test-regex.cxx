#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <boost/config.hpp>

using boost::regex;
using boost::regex_match;

int main(int argc, char **argv) {
    std::string input;
    //regex gdreg(R"(g[a-z]+d)");
    std::string sre("(g[a-z]+d)");
    regex re;
    try {
        // Set up the regular expression for case-insensitivity
        re.assign(sre, boost::regex_constants::icase);
    }
    catch (boost::regex_error& e)
    {
        std::cout << sre << " is not a valid regular expression: \""
            << e.what() << "\"" << std::endl;
        return 1;
    }
    
    std::cout << "Enter a word to be matched to the regex '" << sre << "', case insensative." << std::endl;
    std::cout << "Enter just 'q' to exit..." << std::endl;
    
    while(true)
    {
        std::cout << "Give me a word: ";
        std::cin >> input;
        if(input == "q") {
            break;
        }
        // if(regex_match(input, gdreg))
        if(regex_match(input, re))
            std::cout << "It's a 'g...d' word!" << std::endl;
        else
            std::cout << "Nooooooo! Does not start with 'g', and end with 'd', with only 'a-z' between!" << std::endl;
    }
    return 0;
}

/* eof */

