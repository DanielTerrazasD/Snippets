/*****************************************************************************/
/** Copyright (c) 2021, Daniel Terrazas                                     **/
/** ----------------------------------------------------------------------- **/
/**                          Overloading Operators                          **/
/** ----------------------------------------------------------------------- **/
/** FILE: OverloadingOps.hpp                                                **/
/** ----------------------------------------------------------------------- **/
/** DESCRIPTION:                                                            **/
/** OverloadingOps.hpp description.                                         **/
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

// Guard to prevent recursive inclusion
#ifndef FILE_OVERLOADING_OPS_HPP
#define FILE_OVERLOADING_OPS_HPP

/*****************************************************************************/
/**                                  Includes                               **/
/*****************************************************************************/

#include <iostream>

/*****************************************************************************/
/**                               Public Macros                             **/
/*****************************************************************************/

/*****************************************************************************/
/**                             Public Data Types                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Constants                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Variables                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                              Public Functions                           **/
/*****************************************************************************/

/*****************************************************************************/
/**                               Public Classes                            **/
/*****************************************************************************/

class Text
{
private:

    char *str;

public:

    Text();                             // Default constructor
    Text( const char *s );              // Overloaded constructor
    Text( const Text &obj );            // Copy constructor
    ~Text();                            // Destructor

    Text& operator=(const Text &obj);   // Overloaded copy assignment operator (=)
    Text& operator=(Text &&obj);        // Overloaded move assignment operator (=)
};

class Vector3D
{
    // Overloaded extraction operator (<<)
    friend std::ostream& operator<<(std::ostream &s_out, const Vector3D &obj);

private:

    int x;
    int y;
    int z;

public:

    Vector3D();
    Vector3D(const int &x, const int &y, const int &z);
    Vector3D(const Vector3D &obj);

    Vector3D operator+(const Vector3D &obj);    // Overloaded addition operator (+)
    Vector3D operator-(const Vector3D &obj);    // Overloaded subtraction operator (-)
    Vector3D operator*(const Vector3D &obj);    // Overloaded multiplication operator (*)
    Vector3D operator/(const Vector3D &obj);    // Overloaded division operator (/)
    Vector3D& operator++();                     // Overloaded pre-increment operator (++)
    Vector3D& operator++(int);                  // Overloaded post-increment operator (++)
    Vector3D& operator--();                     // Overloaded pre-decrement operator (--)
    Vector3D& operator--(int);                  // Overloaded post-decrement operator (--)

};

#endif // FILE_OVERLOADING_OPS_HPP

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/