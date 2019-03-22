#include <string>
using ::std::string;

class Name {
private:
    string firstName;
    string secondName;
    string thirdName;
    string lastName;

    auto splitNames(const string &namesAndSurname);
 
 public:
    Name(const string &namesAndSurname);
    
    string FirstName() const;
    string SecondName() const;
    string ThirdName() const;
    string Surname() const;
    string ToFullInitials() const;
    string ToFirstNamesInitials() const;
    string ToSurnameNames() const;
    string ToNamesSurname() const;
    bool IsBeforeBySurname(const Name &other) const;
    bool IsBeforeByFirstName(const Name &other) const;
};