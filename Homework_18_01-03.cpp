#include <iostream>
#include "string.h"

// 1. Оголошення класу Animal зі змінно-членом класу String.
class Animal
{
    String itsAge = {};
};

// 2. Оголошення класу BoundedArray, який є масивом.
class BoundedArray: public Array {};

// 3. Оголошення класу Set, який виконується лише в межах класу BoundedArray.
class Set: private BoundedArray {};
