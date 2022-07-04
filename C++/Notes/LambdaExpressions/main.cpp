#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// Lambda Expressions

// A Lambda expression is a simplified notation for defining and using an
// anonymous function object.

// A Lambda consists of a sequence of parts:
// 1. Campture List [] - Can be empty
// 2. Parameter List () - Optional
// 3. mutable specifier - Optional
// 4. noexcept specifier - Optional
// 5. Return type declaration -> - Optional
// 6. Function body {}

// A Lambda introducer can take various forms:
// 1. []: Empty capture list. No local names from the surrounding context can
//          be used in the lambda body. Data is obtained from arguments or
//          nonlocal variables.
// 
// 2. [&]: Capture by reference. All local names can be used.
//          All local variables are accessed by references.
// 
// 3. [=]: Capture by value. All local names can be used.
//          All names refer to copies of the local variables taken at that'
//          point of call of the lambda expression.
// 
// 4. [capture-list]: The capture-list is the list of names of local variables
//          to be captured by reference or by value.
// 
// 5. [&, capture-list]: Capture by reference all local variables with names
//          not mentioned in the list.
// 
// 6. [=, capture-list]:Capture by value all local variables with names not
//          mentioned in the list.

// An object of a class generated from a Lambda is called a closure object or
// simply a closure.

// The capture list can be seen as the initializer list of the closure object

vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void print_modulo(const vector<int>& v, ostream& os, int m)
{
    // output v[i] to os if v[i] % m == 0
    for_each(v.begin(), v.end(), [&os, m](int x)
        {
            if (x % m == 0)
                os << x << ' ';
        });
    os << '\n';
}

auto lambda = [](int m)
{
    for (auto& x : v)
    {
        if (x % m == 0)
            cout << x << " ";
    }
    cout << '\n';
};

int main()
{
    print_modulo(v, std::cout, 2);
    lambda(3);

    return 0;
}