#include "Name.h"

#include<iostream>
using ::std::cout;
using ::std::endl;

#include<memory>
using ::std::unique_ptr;
using ::std::make_unique;

int main()
{
    auto myName = make_unique<Name>("Adam Krzsztof Lukasz Klekowski");
    cout << myName->FirstName() << endl;
    cout << myName->SecondName() << endl;
    cout << myName->ThirdName() << endl;
    cout << myName->Surname() << endl;
    cout << myName->ToFullInitials() << endl;
    cout << myName->ToFirstNamesInitials() << endl;
    cout << myName->ToSurnameNames() << endl;
    cout << myName->ToNamesSurname() << endl << endl;;

    auto secondPerson = make_unique<Name>("Elon Reeve Musk");
    cout << secondPerson->FirstName() << endl;
    cout << secondPerson->SecondName() << endl;
    cout << secondPerson->ThirdName() << endl;
    cout << secondPerson->Surname() << endl;
    cout << secondPerson->ToFullInitials() << endl;
    cout << secondPerson->ToFirstNamesInitials() << endl;
    cout << secondPerson->ToSurnameNames() << endl;
    cout << secondPerson->ToNamesSurname() << endl;

    if (myName->IsBeforeBySurname(*secondPerson))
    {
        cout <<"Nazwisko drugiej osoby jest alfabtycznie pierwsze" << endl;
    }
    else
    {
        cout <<"Twoje nazwisko jest alfabtycznie pierwsze" << endl;
    }
    
    if (myName->IsBeforeByFirstName(*secondPerson))
    {
        cout <<"Imię drugiej osoby jest alfabtycznie pierwsze" << endl;
    }
    else
    {
        cout <<"Twoje imię jest alfabtycznie pierwsze" << endl;
    }
}