
# CMakeLists.txt, generated gencmake.pl, on 2018/05/08 14:41:17
# Lots of things to know about...

cmake_minimum_required( VERSION 2.6 )

project( test-regex )

# The version number.
set( trv_MAJOR 3 )
set( trv_MINOR 0 )
set( trv_POINT 0 )


# Allow developer to select is Dynamic or static library built
set( LIB_TYPE STATIC )  # set default static
option( BUILD_SHARED_LIB "Build Shared Library" OFF )

if(CMAKE_COMPILER_IS_GNUCXX)
    set( WARNING_FLAGS -Wall )
endif(CMAKE_COMPILER_IS_GNUCXX)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") 
   set( WARNING_FLAGS "-Wall -Wno-overloaded-virtual" )
endif() 

if(WIN32 AND MSVC)
    # turn off various warnings - none needed in this compile
    set(WARNING_FLAGS "${WARNING_FLAGS} /wd4996")
    # foreach(warning 4244 4251 4267 4275 4290 4786 4305)
    #     set(WARNING_FLAGS "${WARNING_FLAGS} /wd${warning}")
    # endforeach(warning)
    set( MSVC_FLAGS "-DNOMINMAX -D_USE_MATH_DEFINES -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D__CRT_NONSTDC_NO_WARNINGS" )
    # to distinguish between debug and release lib
    set( CMAKE_DEBUG_POSTFIX "d" )
else()
    # unix stuff
endif()

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${WARNING_FLAGS} ${MSVC_FLAGS} -D_REENTRANT" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} ${MSVC_FLAGS} -D_REENTRANT" )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MSVC_LD_FLAGS}" )

# config
### set(Boost_DEBUG ON)
set(Boost_USE_STATIC_LIBS ON) 
### set(Boost_USE_MULTITHREADED ON)  
### set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED COMPONENTS regex)
message(STATUS "*** Found Boost inc ${Boost_INCLUDE_DIRS}, lib ${Boost_LIBRARIES}")
include_directories( ${Boost_INCLUDE_DIRS} )
list(APPEND add_LIBS ${Boost_LIBRARIES} )
# add_definitions( -DHAVE_CONFIG_H )

if(BUILD_SHARED_LIB)
   set(LIB_TYPE SHARED)
   message(STATUS "*** Building DLL library ${LIB_TYPE}")
else(BUILD_SHARED_LIB)
   message(STATUS "*** Option BUILD_SHARED_LIB is OFF ${LIB_TYPE}")
endif(BUILD_SHARED_LIB)

# src EXECUTABLE from [/home/geoff/projects/tests/test-regex/src],
# have 1 C/C++ sources, 0 headers
set(name test-regex)
set(dir src)
set(${name}_SRCS
    ${dir}/${name}.cxx
    )
add_executable( ${name} ${${name}_SRCS} )
if (add_LIBS)
    target_link_libraries( ${name} ${add_LIBS} )
endif ()
if (MSVC)
    set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
endif ()
# deal with install, if any...
#install( TARGETS ${name} DESTINATION bin )

set(name test-regex2)
set(dir src)
set(${name}_SRCS
    ${dir}/${name}.cxx
    )
add_executable( ${name} ${${name}_SRCS} )
if (add_LIBS)
    target_link_libraries( ${name} ${add_LIBS} )
endif ()
if (MSVC)
    set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
endif ()
# deal with install, if any...
#install( TARGETS ${name} DESTINATION bin )

set(name test-regex3)
set(dir src)
set(${name}_SRCS
    ${dir}/${name}.cxx
    )
add_executable( ${name} ${${name}_SRCS} )
if (UNIX)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 11)
endif ()
if (add_LIBS)
    target_link_libraries( ${name} ${add_LIBS} )
endif ()
if (MSVC)
    set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
endif ()
# deal with install, if any...
#install( TARGETS ${name} DESTINATION bin )

if (BUILD_JGREP_APP)
    # when the compile is fixed
    set(name jgrep)
    set(dir src)
    set(${name}_SRCS
        ${dir}/${name}.cpp
        ${dir}/${name}.h
        ${dir}/jmain.cpp
        )
    add_executable( ${name} ${${name}_SRCS} )
    if (add_LIBS)
        target_link_libraries( ${name} ${add_LIBS} )
    endif ()
    if (MSVC)
        set_target_properties( ${name} PROPERTIES DEBUG_POSTFIX d )
    endif ()
    # deal with install, if any...
    #install( TARGETS ${name} DESTINATION bin )
endif ()


# eof

