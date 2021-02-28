/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                          Overloading Operators                          **/
/** ----------------------------------------------------------------------- **/
/** FILE: main.cpp                                                          **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** main.cpp description.                                                   **/
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

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include "OverloadingOps.hpp"

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

int main(int argc, char const* argv[])
{
    // Calls: Overloaded constructor.
    Text tom {"Tom"};
    // Calls: Default constructor.
    Text copy_of_tom;
    // Calls: Overloaded copy assignment operator.
    copy_of_tom = tom;

    // Calls: Overloaded constructor.
    Text daniel {"Daniel"};
    // Calls: Overloaded constructor then overloaded move assignment operator.
    daniel = Text{"Hello"};



    // Calls: Overloaded constructor.
    Vector3D vec_1 {5, 7, 2};
    // Calls: Overloaded constructor.
    Vector3D vec_2 {-1, 2, 15};
    // Calls: Default constructor.
    Vector3D vec_3;

    // Calls: Overloaded addition operator.
    vec_3 = vec_1 + vec_2;
    // Calls: Overloaded subtraction operator.
    vec_3 = vec_1 - vec_2;
    // Calls: Overloaded multiplication operator.
    vec_3 = vec_1 * vec_2;
    // Calls: Overloaded division operator.
    vec_3 = vec_1 / vec_2;
    // Calls: Overloaded pre-increment operator.
    ++vec_1;
    // Calls: Overloaded post-increment operator.
    vec_1++;
    // Calls: Overloaded pre-decrement operator.
    --vec_2;
    // Calls: Overloaded post-decrement operator.
    vec_2--;

    // Calls: Overloaded extraction operator.
    std::cout << "Vector_1: " << vec_1 << std::endl;
    std::cout << "Vector_2: " << vec_1 << std::endl;
    std::cout << "Vector_3: " << vec_1 << std::endl;

    return 0;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/
