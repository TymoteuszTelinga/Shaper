
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <map>

using std::cout;
using std::cerr;
using std::string;

const string single = ".,:;()[]{}&|";
const string doubleOperators = "-+*/%=!<>";

//zwraca true jeśli podane słowo jest słowem kluczowym
bool checkForKeyWord(const string& word)
{
    if (word == "void")
    {
        
        return true;
    }

    if (word == "bool")
    {
        return true;
    }

    if (word == "int")
    {
        return true;
    }

    if (word == "long")
    {
        return true;
    }

    if (word == "char")
    {
        return true;
    }

    if (word == "float")
    {
        return true;
    }

    if (word == "double")
    {
        return true;
    }

    if (word == "color")
    {
        return true;
    }

    if (word == "struct")
    {
        return true;
    }

    if (word == "array")
    {
        return true;
    }

    if (word == "list")
    {
        return true;
    }

    if (word == "const")
    {
        return true;
    }

    if (word == "if")
    {
        return true;
    }

    if (word == "elif")
    {
        return true;
    }

    if (word == "else")
    {
        return true;
    }

    if (word == "switch")
    {
        return true;
    }

    if (word == "case")
    {
        return true;
    }

    if (word == "default")
    {
        return true;
    }

    if (word == "while")
    {
        return true;
    }

    if (word == "for")
    {
        return true;
    }

    if (word == "continue")
    {
        return true;
    }

    if (word == "break")
    {
        return true;
    }

    if (word == "return")
    {
        return true;
    }
    
    return false;
}
//wypisuje występowania poszczegulnych keywordow
void printCounter(const std::map<string, int>& counter)
{
    for (auto& keyword : counter)
    {
        cout<<keyword.first <<": " <<keyword.second<<"\n";
    }
}
//zapisuje słowo do listy wyrażeń
void saveToken(std::vector<string>& t,string& word)
{
    if (word.size() == 0)
    {
        return;
    }

    t.push_back(word);

    word.clear();
}
//zapisuje znak do listy wyrażeń
void saveToken(std::vector<string>& t,char c)
{
    t.push_back(string(1,c));
}
//odczytuje następny znak z słowa
char next(const string& line, const int pos)
{
    if (pos >= line.size())
    {
        return -1;
    }

    return line[pos+1];
}
//zwraca liste zawierającą poszczegolne "wyrażenia"
std::vector<string> createTokensFromFile(const string& src)
{
    std::vector<string> tokens;
    std::map<string,int> counter;

    std::ifstream file(src);
    if (!file.is_open())
    {
        cerr<<"error: "<<src<<": No such file or directory\n";
        return tokens;
    }
    
    uint32_t lineIndex = 0;
    string line;
    string word="";
    char c;

    while (std::getline(file,line))
    {
        lineIndex++;
        for (size_t i = 0; i < line.size(); i++)
        {
            c = line[i];

            if (isdigit(c) || isalpha(c))
            {
                word+=c;
                continue;
            }
            //zliczanie slow kluczowych
            if(checkForKeyWord(word))
            {
                ++counter[word];
            }

            //zapis do tej pory utworzonego słowa
            saveToken(tokens,word);
            //spacja lub koniec lini
            if (c == ' ' || c == '\n')
            {
                continue;
            }
            //jest to pojedyńczy operator to zapisz
            if (single.find(c) != string::npos)
            {
                saveToken(tokens,c);
                continue;
            }
            //jest to jeden z operatorów podwójnych
            if (doubleOperators.find(c) != string::npos)
            {
                char n = next(line,i);
                if (n == '=')
                {
                    string s;
                    s+=c,s+=n;
                    saveToken(tokens,s);
                    i++;
                    continue;
                }

                if (c == '+' && n == '+')
                {
                    string s;
                    s+=c,s+=n;
                    saveToken(tokens,s);
                    i++;
                    continue;
                }

                if (c == '-' && n == '-')
                {
                    string s;
                    s+=c,s+=n;
                    saveToken(tokens,s);
                    i++;
                    continue;
                }

                if (c == '/' && n == '/')
                {
                    break;
                }

                saveToken(tokens,c);
                continue;
            }
             
            cerr<<src<<':'<<lineIndex<<':'<<i<<" warning: "<<c<<": invalid character\n";         
        }
    }

    file.close();

    printCounter(counter);

    return tokens;
}

int main(int argc, char* argv[])
{

    if (argc == 1)
    {
        cerr<<"fatal error: no input files\n";
        return -1;
    }

    string src(argv[1]);
    std::vector<string>tokens = createTokensFromFile(src);
    if (tokens.size() == 0)
    {
        return -1;
    }

    string outSrc = "out.txt";
    if (argc == 3)
    {
        outSrc = string(argv[2]);
    }
        
    std::ofstream outFile(outSrc);
    if (!outFile.is_open())
    {
        return -1;
    }
    for (auto &w : tokens)
    {
        outFile<<w<<'\n';
    }
    outFile.close();
    
    // cout<<"\n\nEND\n"; 
    return 0;
}