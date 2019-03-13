#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

string findIndexInSquare(char charToFind)
{
    if (charToFind=='J') charToFind='I';
    string index="";
    char PolybiusSquare[5][5]={{'A', 'B', 'C', 'D', 'E'},
                                {'F', 'G', 'H', 'I', 'K'},
                                {'L', 'M', 'N', 'O', 'P'},
                                {'Q', 'R', 'S', 'T', 'U'},
                                {'V', 'W', 'X', 'Y', 'Z'}};
    for (int j=0; j<5; j++)
    {
        for(int k=0; k<5; k++)
        {
            if (PolybiusSquare[j][k]== charToFind )
            {
                index.push_back((j+1)+'0');
                index.push_back((k+1)+'0');
                return index;
            }
        }
    }
}

string PolybiusCrypt(string message)
{
    string result;
    for (int i=0; i<message.length(); i++)
    {
        result.append(findIndexInSquare(message.at(i)));
    }
    return result;

}
string PolybiusDecrypt(string crypted)
{
    string result; 
    char newChar;
    char PolybiusSquare[5][5]={{'A', 'B', 'C', 'D', 'E'},
                                {'F', 'G', 'H', 'I', 'K'},
                                {'L', 'M', 'N', 'O', 'P'},
                                {'Q', 'R', 'S', 'T', 'U'},
                                {'V', 'W', 'X', 'Y', 'Z'}};
    for (int i=0; i<crypted.length(); i+=2)
    {
        int row=crypted.at(i)-'0';
        int column=crypted.at(i+1)-'0';
        newChar=PolybiusSquare[row-1][column-1];
        result.push_back(newChar);
    }
    return result;     
}

int main(int argc, char *argv[])
{   
    fstream inputFile(argv[1], ios::in);
    fstream outputFile(argv[2], ios::out);

    string text;
    getline(inputFile, text);

    short choice=short(*argv[3]-'0');
    switch (choice)
    {
        case 0:
            text=PolybiusCrypt(text);
            break;
    
        case 1:
            text=PolybiusDecrypt(text);
            break;
    }
    outputFile<<text;

    inputFile.close();
    outputFile.close();
}