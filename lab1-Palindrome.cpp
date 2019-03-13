#include<string>
#include<iostream>

using namespace std;

bool is_palindrome(string str)
{
    int size=str.size();
    for (int i=0; i<size; i++)
    {
        if (str.at(i)!=str.at(size-1-i)) return false;
    }
    return true; 
}

int main()
{
    short choice;
    string phraseToCheck;
    while(1)
    {
        cout <<"[1] Sprawdź palindrom" << endl;
        cout <<"[2] Wyjście" << endl;
        cout <<"Twój wybór:";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cin >> phraseToCheck;
                if (is_palindrome(phraseToCheck)) 
                {
                    cout<<"Sprawdzane słowo jest palindromem" << endl;
                }
                else
                {
                    cout<<"Sprawdzane słowo NIE jest palindromem" << endl;
                }
                
                break;
            case 2:
                exit(0);
                break;
        }
    }
}