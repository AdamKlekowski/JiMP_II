#include <vector>
//#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>

using ::std::string;
using ::std::vector;

unsigned int ToMinutes(string time_HH_MM)
{
    if (std::regex_match (time_HH_MM, std::regex("[1-2][0-9]:[0-5][0-9]") ))
    {
        string hour="";
        hour.push_back(time_HH_MM.at(0));
        hour.push_back(time_HH_MM.at(1));
        int h=stoi(hour);

        string minutes="";
        minutes.push_back(time_HH_MM.at(3));
        minutes.push_back(time_HH_MM.at(4));
        int min=stoi(minutes);

        return 60*h+min;
    }
    else if (std::regex_match (time_HH_MM, std::regex("[0-9]:[0-5][0-9]") ))
    {
        string hour="";
        hour.push_back(time_HH_MM.at(0));
        int h=stoi(hour);

        string minutes="";
        minutes.push_back(time_HH_MM.at(2));
        minutes.push_back(time_HH_MM.at(3));
        int min=stoi(minutes);

        return 60*h+min;    
    }
}

unsigned int MinimalTimeDifference(vector<string> times)
{
    unsigned int tmp;
    vector<unsigned int> timesInMin;
    for (int i=0; i<times.size(); i++)
    {
        tmp=ToMinutes(times.at(i));
        timesInMin.push_back(tmp);
    }

    unsigned int minDif=abs(timesInMin.at(0)-timesInMin.at(1));
    unsigned int currentDif;
    for (int i=0; i<timesInMin.size(); i++)
    {
        for(int k=i+1; k<timesInMin.size(); k++)
        {
            currentDif=abs(timesInMin.at(i)-timesInMin.at(k));
            if (currentDif<minDif) minDif=currentDif;
        }
    }
    return minDif;
}

int main()
{
    vector<string> times;
    times.push_back("10:00");
    times.push_back("2:40");
    times.push_back("11:10");
    times.push_back("10:40");
    times.push_back("20:11");

    std::cout << "Minimal time difference = "<< MinimalTimeDifference(times) << std::endl;
}