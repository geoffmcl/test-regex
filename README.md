# test-regex project

Some test apps using boost regex library...

Project uses [cmake](https://cmake.org/install/) configuration and generation to find the installed boost regex library, and header `<boost/regex.hpp>`, and will fail if **not** found.

#### Build

Unix: Assume using (default) `Unix Makefiles` generator

    $ cd build
    $ cmake .. -DCMAKE_BUILD_TYPE=Release [options]
    $ make
    
Windows: Assume using a MSVC install

    $ cd build
    $ cmake .. [options]
    $ cmake --build . --config Release
    

#### Licence

Licence GNU GPL v.2.0 - see [LICENCE.txt](https://github.com/geoffmcl/test-regex/blob/master/LICENSE.txt)


Geoff.  
20180508

; eof

