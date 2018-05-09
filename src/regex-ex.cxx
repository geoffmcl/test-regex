/*\
 * regex-ex.cxx
 *
 * Copyright (c) 2017 - Geoff R. McLane
 * Licence: GNU GPL version 2
 *
 * boost regex examples
 * from : https://theboostcpplibraries.com/boost.regex
 *
\*/

#include <stdio.h>
#include <boost/regex.hpp>
#include <string>
#include <iostream>
#include <locale> // for 8.8

// static const char *module = "regex-ex";

void example_8_1()
{
    std::cout << "Example 8.1. Comparing strings with boost::regex_match()" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{"\\w+\\s\\w+"};
    std::cout << "string: '" << s << "', regexe: '" << expr << "'" << std::endl;
    std::cout << "Expect: 'true' - " << std::boolalpha << boost::regex_match(s, expr) << std::endl;
}

void example_8_2()
{
    std::cout << "Example 8.2. Searching strings with boost::regex_search()" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{ "(\\w+)\\s(\\w+)" };
    boost::smatch what;
    std::cout << "string: '" << s << "', regexe: '" << expr << "'" << std::endl;
    if (boost::regex_search(s, what, expr))
    {
        std::cout << "what[0]         = " << what[0] << std::endl;
        std::cout << "what[1]_what[2] = " << what[1] << "_" << what[2] << std::endl;
    }
    else {
        std::cout << "Search FAILED!" << std::endl;
    }
}

void example_8_3()
{
    std::cout << "Example 8.3. Replacing characters in strings with boost::regex_replace()" << std::endl;
    std::string s = " Boost Libraries ";
    boost::regex expr{ "\\s" };
    std::string fmt{ "_" };
    std::cout << "string: '" << s << "', regexe: '" << expr << "', repl: '" << fmt << "'" << std::endl;
    std::cout << "results: '" << boost::regex_replace(s, expr, fmt) << "'" << std::endl;

}

void example_8_4()
{
    std::cout << "Example 8.4. Format with references to groups in regular expressions" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{ "(\\w+)\\s(\\w+)" };
    std::string fmt{ "\\2 \\1" };
    std::cout << "string: '" << s << "', regexe: '" << expr << "', format: '" << fmt << "'" << std::endl;
    std::cout << "results: '" << boost::regex_replace(s, expr, fmt) << "'" << std::endl;
}

void example_8_5()
{
    std::cout << "Example 8.5. Flags for formats" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{ "(\\w+)\\s(\\w+)" };
    std::string fmt{ "\\2 \\1" };
    std::cout << "string: '" << s << "', regexe: '" << expr << "', format: '" << fmt << "'" << std::endl;
    std::cout << "results: '" << boost::regex_replace(s, expr, fmt,
        boost::regex_constants::format_literal) << "'\n";
}

void example_8_6()
{
    std::cout << "Example 8.6. Iterating over strings with boost::regex_token_iterator" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{ "\\w+" };
    std::cout << "string: '" << s << "', regexe: '" << expr << "'" << std::endl;
    boost::regex_token_iterator<std::string::iterator> it{ s.begin(), s.end(), expr };
    boost::regex_token_iterator<std::string::iterator> end;
    int cnt = 0;
    while (it != end) {
        cnt++;
        std::cout << cnt << " '" << *it++ << "'\n";
    }
}

void example_8_7()
{
    std::cout << "Example 8.7. Accessing groups with boost::regex_token_iterator" << std::endl;
    std::string s = "Boost Libraries";
    boost::regex expr{ "(\\w)\\w+" };
    std::cout << "string: '" << s << "', regexe: '" << expr << "'" << std::endl;
    boost::regex_token_iterator<std::string::iterator> it{ s.begin(), s.end(), expr, 1 };
    boost::regex_token_iterator<std::string::iterator> end;
    int cnt = 0;
    while (it != end) {
        cnt++;
        std::cout << cnt << " '" << *it++ << "'\n";
    }
}

void example_8_8()
{
    bool setloc = true;
    std::cout << "Example 8.8. Linking a locale to a regular expression" << std::endl;
    std::string s = "Boost k\xfct\xfcphaneleri";
    boost::basic_regex<char, boost::cpp_regex_traits<char>> expr;
#ifdef WIN32
    expr.imbue(std::locale{ "Turkish" });
#else
    try
    {
        expr.imbue(std::locale{ "tr_TR" });
    }
    catch(std::exception const& e)
    {
        std::cout << "Exception: 'tr_TR' " << e.what() << "\n";
        setloc = false;
    }    
#endif
    expr = "\\w+\\s\\w+";
    std::cout << "string: '" << s << "', regexe: '" << expr << "'" << std::endl;
    if (setloc) {
        std::cout << "Expect: 'true' - " << std::boolalpha << boost::regex_match(s, expr) << '\n';
    } else {
        std::cout << "'imbue' failed as above! Expect: 'false' - " << std::boolalpha << boost::regex_match(s, expr) << '\n';
    }
}


int main()
{
    std::cout << "Examples taken from:  https://theboostcpplibraries.com/boost.regex" << std::endl;
    std::cout << std::endl;
    example_8_1();
    std::cout << std::endl;
    example_8_2();
    std::cout << std::endl;
    example_8_3();
    std::cout << std::endl;
    example_8_4();
    std::cout << std::endl;
    example_8_5();
    std::cout << std::endl;
    example_8_6();
    std::cout << std::endl;
    example_8_7();
    std::cout << std::endl;
    example_8_8();
    std::cout << std::endl;
    return 0;
}

// eof = regex-ex.cxx
