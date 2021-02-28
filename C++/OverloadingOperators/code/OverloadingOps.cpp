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

#include <cstring>
#include <iostream>

#include "OverloadingOps.hpp"

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

/************************************ Text ***********************************/

Text::Text() :
str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

Text::Text( const char *s ) :
str{nullptr}
{
    if ( s == nullptr )
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[ std::strlen(s) + 1 ];
        std::strcpy(str, s);
    }
}

Text::Text( const Text &obj ) :
str{nullptr}
{
    str = new char[ std::strlen(obj.str) + 1 ];
    std::strcpy(str, obj.str);
}

Text::~Text()
{
    delete [] str;
}

// Overloading copy assignment operator:
Text& Text::operator=(const Text &obj)
{
    std::cout << "Copy assignment operator" << std::endl;
    if (this == &obj)
        return *this;

    delete [] this->str;
    str = new char[ std::strlen(obj.str) + 1 ];
    std::strcpy(this->str, obj.str);
    return *this;
}

// Overloading move assignment operator:
Text& Text::operator=(Text &&obj)
{
    std::cout << "Move assignment operator" << std::endl;
    if (this == &obj)
        return *this;

    delete [] this->str;
    str = obj.str;
    obj.str = nullptr;
    return *this;
}

/********************************** Vector3D *********************************/

Vector3D::Vector3D() :
Vector3D{0, 0, 0}
{
}

Vector3D::Vector3D(const int &x, const int &y, const int &z) :
x{x}, y{y}, z{z}
{
}

Vector3D::Vector3D(const Vector3D &obj) :
Vector3D{obj.x, obj.y, obj.z}
{
}

Vector3D Vector3D::operator+(const Vector3D &obj)
{
    return Vector3D(x + obj.x, y + obj.y, z + obj.z);
}

Vector3D Vector3D::operator-(const Vector3D &obj)
{
    return Vector3D(x - obj.x, y - obj.y, z - obj.z);
}

Vector3D Vector3D::operator*(const Vector3D &obj)
{
    return Vector3D(x * obj.x, y * obj.y, z * obj.z);
}

Vector3D Vector3D::operator/(const Vector3D &obj)
{
    return Vector3D(x / obj.x, y / obj.y, z / obj.z);
}

Vector3D& Vector3D::operator++()
{
    this->x += 1;
    this->y += 1;
    this->z += 1;
    return *this;
}

Vector3D& Vector3D::operator++(int)
{
    this->x += 1;
    this->y += 1;
    this->z += 1;
    return *this;
}

Vector3D& Vector3D::operator--()
{
    this->x -= 1;
    this->y -= 1;
    this->z -= 1;
    return *this;
}

Vector3D& Vector3D::operator--(int)
{
    this->x -= 1;
    this->y -= 1;
    this->z -= 1;
    return *this;
}

std::ostream &operator<<(std::ostream &s_out, const Vector3D &obj)
{
    s_out << "x: " << obj.x << ", y: " << obj.y << ", z: " << obj.z;
    return s_out;
}

/*****************************************************************************/
/**                                END OF FILE                              **/
/*****************************************************************************/