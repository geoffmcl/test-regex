
/*
    from : https://stackoverflow.com/questions/5804453/c-regular-expressions-with-boost-regex
 */

#include <iostream> // for cout
#include <string>
#include <list>
#include <boost/regex.hpp>
typedef std::string::const_iterator ConstIt;

int main()
{
    // input text, expected result, & proper address pattern
    const std::string sInput
    (
            "192.168.0.1 10.0.0.255 abc 10.5.1.00"
            " 1.2.3.4a 168.72.0 0.0.0.0 5.4.3.2"
    );
    const std::string asExpected[] =
    {
        "192.168.0.1",
        "10.0.0.255",
        "0.0.0.0",
        "5.4.3.2"
    };
    boost::regex regexIPs
    (
        "(^|[ \t])("
        "(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])[.]"
        "(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])[.]"
        "(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])[.]"
        "(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])"
        ")($|[ \t])"
    );
    std::cout << "parse '" << sInput << "' for valid IP's." << std::endl;
    std::cout << "do regex_search and store results. Expect 4..." << std::endl;
    boost::smatch what;
    std::list<std::string> ns;
    ConstIt end = sInput.end();
    for (ConstIt begin = sInput.begin();
                boost::regex_search(begin, end, what, regexIPs);
                begin = what[0].second)
    {
        ns.push_back(std::string(what[2].first, what[2].second));
    }

    size_t max = ns.size();
    std::cout << "check " << max << " results and return errors... should be zero..." << std::endl;
    int iErrors = 0;
    int i = 0;
    // NOTE: This 'for' construct requires c++11
    for (std::string & s : ns) {
        std::string fnd = asExpected[i++];
        std::cout << i << " " << fnd << " ";
        if (s == fnd) 
        {
            std::cout << "ok";
        }
        else
        {
            std::cout << "FAILED";
            ++ iErrors;
        }
        std::cout << std::endl;
   
    }
    std::cout << "number of errors " << iErrors << std::endl;
    return iErrors;
}

/* eof */

