/*\
 * test-regex2.cxx
 *
 * Copyright (c) 2018 - Geoff R. McLane
 * Licence: GNU GPL version 2
 *
 * boost regex example
 * from: https://ubuntuforums.org/archive/index.php/t-1674703.html
 * got an error "undefined reference to `boost::re_detail::perl_matcher..." and other things...
 * but in that case seemed it was solved adding '-lboost_regex'
 * I also do not have a problem compiling this...
 *
\*/
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

