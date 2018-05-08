
#include <iostream>
#include <string>
#include <boost/regex.hpp> // Boost.Regex lib
#include <boost/config.hpp>

using namespace std;

int main( ) 
{
    std::string s, sre;
    boost::regex re;
    cout << "Enter a regex `expression`, then a 'string' to try..." << endl;
    cout << "Enter 'quit' to exit." << endl;
    while(true)
    {
        cout << "Expression: ";
        cin >> sre;
        if (sre == "quit")
        {
            break;
        }
        cout << "String: ";
        cin >> s;
        try
        {
            // Set up the regular expression for case-insensitivity
            re.assign(sre, boost::regex_constants::icase);
        }
        catch (boost::regex_error& e)
        {
            cout << sre << " is not a valid regular expression: \""
                << e.what() << "\"" << endl;
            continue;
        }
        if (boost::regex_match(s, re))
        {
            cout << re << " matches " << s << endl;
        } 
        else 
        {
            cout << re << " does NOT match " << s << endl;
        }
    }
    return 0;
}

/* eof */

