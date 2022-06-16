
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "VM.hpp"

using std::string;

int* loadProgram(const string& src, Parameters &params)
{
    std::ifstream file(src, std::ios::binary);
    if (file.is_open())
    {
        file.seekg (0, std::ios::end);
        int length = file.tellg();
        file.seekg (0, std::ios::beg);
        char *buffer = new char[length-4];
        // int offset;
        file.read((char*)&params.memOffset,4);
        //  = offset;
        file.read(buffer,length);
        file.close();
        return (int*)buffer;
    }
    std::cerr<<"error: unable to load file "<<src<<'\n';
    return nullptr;
}

// main filename [-w width | -h height | -fps fps | -d | -m memSize | -s stackSize] 
// saving frames?
int main(int argc, char *argv[])
{

    if (argc <= 1)
    {
        std::cerr<<"fatal error: no input files\n";
        return -1;
    }
    string src(argv[1]);

    std::vector<string> options;

    for (size_t i = 2; i < argc; i++)
    {
        options.push_back(string(argv[i]));
    }

    Parameters params;

    auto itr = std::find(options.begin(), options.end(), "-fps");
    if (itr != options.end())
    {
        params.fps = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-w");
    if (itr != options.end())
    {
        params.width = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-h");
    if (itr != options.end())
    {
        params.height = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-d");
    if (itr != options.end())
    {
        params.debug = true;
    }

    itr = std::find(options.begin(), options.end(), "-m");
    if (itr != options.end())
    {
        params.memSize = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-s");
    if (itr != options.end())
    {
        params.stackSize = std::stoi(*(++itr));
    }

    int *program = loadProgram(src, params);

    VM svm(program,0,params);
    svm.execute();
    
    std::cout<<"END\n";
    return 0;
}