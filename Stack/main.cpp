#include <iostream>
#include "Stack.h"

int main()
{
    using std::cout;
    using std::endl;

    Stack<int> s;

    try
    {
        s.push(5);
        s.push(10);
        s.push(23);
        s.push(465);

        cout << "Stack: " << endl << s << endl << endl;

        s.clear();

        cout << "Stack after cleaning: " << endl << s << endl;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}