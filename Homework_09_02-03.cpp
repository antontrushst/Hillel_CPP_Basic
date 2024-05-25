/* 2 - 3. В моєму випадку компілятор генерує помилку:
          рядок 12 - спроба змінити значення за постійним вказівником;
          
          Жодних попереджень мій компілятор чомусь не згенерував. */

int main()
{
    const int *pointer = new const int(5);
    int varOne;
    pointer = &varOne;
    varOne = 6;
    *pointer = 7;
    int varTwo;
    pointer = &varTwo;

    return 0;
}
