/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                            Move Constructors                            **/
/** ----------------------------------------------------------------------- **/
/** FILE: MoveCtors.hpp                                                     **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** MoveCtors.hpp description.                                              **/
/** ----------------------------------------------------------------------- **/
/**                                                                         **/
/** Permission is hereby granted, free of charge, to any person obtaining a **/
/** copy of this software and associated documentation files                **/
/** (the "Software") to deal in the Software without restriction, including **/
/** without limitation the rights to use, copy, modify, merge, publish,     **/
/** distribute, sublicense, and/or sell copies of the Software, and to      **/
/** permit persons to whom the Software is furnished to do so, subject to   **/
/** the following conditions:                                               **/
/**                                                                         **/
/** The above copyright notice and this permission notice shall be included **/
/** in all copies or substantial portions of the Software.                  **/
/**                                                                         **/
/** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS **/
/** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              **/
/** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **/
/** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **/
/** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **/
/** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **/
/** SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **/
/**                                                                         **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Preprocessors                             **/
/*****************************************************************************/

#include <iostream>

#include "MoveCtors.hpp"

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                   Macros                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Data Types                              **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Constants                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                 Variables                               **/
/*****************************************************************************/

/*****************************************************************************/
/**                                  Classes                                **/
/*****************************************************************************/

/*****************************************************************************/
/**                            Function Prototypes                          **/
/*****************************************************************************/

/*****************************************************************************/
/**                            Function Definitions                         **/
/*****************************************************************************/

Person::Person(std::string new_name, int new_age) :
name{new_name}
{
    age = new int;
    *age = new_age;
    std::cout << "Constructor for " << new_name << std::endl;
}

Person::Person(const Person &source_obj) :
Person{source_obj.name, *source_obj.age}
{
    std::cout << "Copy constructor - Deep copy for " << source_obj.name << std::endl;
}

Person::Person(Person &&source_obj) :
name{source_obj.name}, age{source_obj.age}
{
    // 'Steal' the data "age{source_obj.age}" and null out the source pointer.
    source_obj.age = nullptr;
    std::cout << "Move constructor - Move for " << source_obj.name << std::endl;
}

Person::~Person()
{
    std::cout << "Deconstructor for " << name << std::endl;
    delete age;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/