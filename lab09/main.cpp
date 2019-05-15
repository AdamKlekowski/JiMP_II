#include <iostream>
using ::std::cout;
using ::std::endl;
#include <vector>
#include <memory>

#include "Student.h"
#include "StudentRepository.h"
#include "Query.h"
#include "ByFirstName.h"
#include "ByLastName.h"
#include "ByOneOfPrograms.h"
#include "ByYearLowerOrEqualTo.h"
#include "OrQuery.h"
#include "AndQuery.h"

void useQuery(StudentRepository const &repository, std::unique_ptr<Query> &query)
{
    std::vector<Student>result = repository.FindByQuery(*query);
    cout << "Found students: " <<endl;
    for (auto foundStudent : result)
    {
        cout << foundStudent << endl;
    }
}

int main()
{
    StudentRepository repository;
    repository.LoadDataBaseFromFile("database.txt");
    //repository.Print();

    std::vector<std::unique_ptr<Query>> vectorOfQueries_1;
    vectorOfQueries_1.push_back(std::make_unique <ByFirstName> ("Adam"));
    std::vector<string> fieldsOfStudy_1 = {"Law", "PE"};
    vectorOfQueries_1.push_back(std::make_unique <ByOneOfPrograms> (fieldsOfStudy_1));

    std::unique_ptr<Query> orQuery = std::make_unique <OrQuery> (vectorOfQueries_1);
    useQuery(repository, orQuery);


    std::vector<std::unique_ptr<Query>> vectorOfQueries_2;
    vectorOfQueries_2.push_back(std::make_unique <ByLastName> ("Kowalczyk"));
    vectorOfQueries_2.push_back(std::make_unique <ByYearLowerOrEqualTo>(2));
    std::vector<string> fieldsOfStudy_2 = {"Law", "IT"};
    vectorOfQueries_2.push_back(std::make_unique <ByOneOfPrograms> (fieldsOfStudy_2));

    std::unique_ptr<Query> andQuery = std::make_unique <AndQuery> (vectorOfQueries_2);
    useQuery(repository, andQuery);
}