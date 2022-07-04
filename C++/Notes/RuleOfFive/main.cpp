#include <iostream>

using namespace std;

// Rule of Zero
/// TODO:

// Rule of 3
// If a class requires a user-defined destructor, copy-constructor, or
// copy-assignment operator, it almost certainly requires all three.
// - Destructor
// - Copy-Constructor
// - Copy-Assignment

// Rule of 5
// Because of the presence of a user-defined (or =default or =delete)
// destructor, copy-constructor, or copy-assignment operator prevents implicit
// definition of the move constructor and move assignment operator, any class
// for which move semantics are desirable, has to declare all five special
// member functions.
// - Destructor
// - Copy-Constructor
// - Move-Constructor
// - Copy-Assignment
// - Move-Assignment

class X
{
public:

    X();                        // default constructor
    X(int);                     // Overloaded constructor
    X(const X&);                // copy-constructor
    X(X&&) noexcept;            // move-constructor
    X& operator=(const X&);     // copy-assignment: clean up target and copy
    X& operator=(X&&) noexcept; // move-assignment: clean up target and move
    ~X();                       // destructor
};


X::X()
{
    std::cout << "Default Constructor - X::X()\n";
}

X::X(int x)
{
    std::cout << "Overloaded Constructor - X::X(int)\n";
}

X::X(const X&)
{ 
    std::cout << "Copy Constructor - X::X(const X&)\n";
}

X::X(X&&) noexcept
{
    std::cout << "Move Constructor - X::X(X&&)\n";
}

X& X::operator=(const X&)
{
    std::cout << "Copy Assignment - X& X::operator=(const X&)\n";
    return *this;
}

X& X::operator=(X&& source) noexcept
{
    std::cout << "Move Assignment - X& X::operator=(X&&)\n";
    return *this;
}

X::~X()
{
    std::cout << "X::~X()\n";
}

int main()
{
    X x1;                       // Default Constructor
    X x2(1);                    // Overloaded Constructor

    X x3{ x1 };                 // Copy Constructor
    x3 = x1;                    // Copy Assignment
    
    for (size_t i = 0; i < 80; i++) { cout << "-"; } cout << "\n";

    X x4;                       // Default Constructor
    X x5(std::move(x4));        // Move Constructor
    x4 = X(2);                  // Overloaded Constructor and Move Assignment

    for (size_t i = 0; i < 80; i++) { cout << "-"; } cout << "\n";
    return 0;
}