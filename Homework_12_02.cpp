/*
    2. Проблема даного коду полягає у наданні функції SomeFunction() в якості
       аргументу об'єкт класу Rectangle, а не Shape, який вимагає ця функція.
*/

void SomeFunction(Shape);
Shape *pRect = new Rectangle;
SomeFunction(*pRect);
