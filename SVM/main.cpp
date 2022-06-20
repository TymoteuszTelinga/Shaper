
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
        file.read((char*)&params.memOffset,4);
        file.read(buffer,length);
        file.close();
        return (int*)buffer;
    }
    std::cerr<<"error: unable to load file "<<src<<'\n';
    return nullptr;
}

// main filename [-w width | -h height | -fps fps | -d | -m memSize | -s stackSize]
void ShowHelp()
{
    std::cerr<<"Usage: SVM file [options]\n"
             <<"Options:\n"
             <<"\t-w <arg>   Pass <arg> as window width.\n"
             <<"\t-h <arg>   Pass <arg> as window heigh.\n"
             <<"\t-fps <arg> Pass <arg> as window frame rate limit.\n"
             <<"\t-d         Start program in debug mode.\n"
             <<"\t-m <arg>   Pass <arg> as memory size.\n"
             <<"\t-s <arg>   Pass <arg> as stack max size.\n";
}

int main(int argc, char *argv[])
{
    std::vector<string> options;
    //no args
    if (argc <= 1)
    {
        std::cerr<<"fatal error: no input files\n";
        return -1;
    }

    string src(argv[1]);

    if (src == "--help")
    {
        ShowHelp();
        return 0;
    }

    if (src[0] == '-')
    {
        std::cerr<<"fatal error: no input files\n";
        return -1;
    }
    
    for (size_t i = 2; i < argc; i++)
    {
        options.push_back(string(argv[i]));
    }

    auto itr = std::find(options.begin(), options.end(), "--help");
    if (itr != options.end())
    {
        ShowHelp();
        return 0;
    }

    Parameters params;

    itr = std::find(options.begin(), options.end(), "-fps");
    if (itr != options.end() && itr+1 != options.end())
    {
        params.fps = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-w");
    if (itr != options.end() && itr+1 != options.end())
    {
        params.width = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-h");
    if (itr != options.end() && itr+1 != options.end())
    {
        params.height = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-d");
    if (itr != options.end())
    {
        params.debug = true;
    }

    itr = std::find(options.begin(), options.end(), "-m");
    if (itr != options.end() && itr+1 != options.end())
    {
        params.memSize = std::stoi(*(++itr));
    }

    itr = std::find(options.begin(), options.end(), "-s");
    if (itr != options.end() && itr+1 != options.end())
    {
        params.stackSize = std::stoi(*(++itr));
    }

    int *program = loadProgram(src, params);

    VM svm(program,0,params);
    svm.execute();
    
    std::cout<<"ENDL\n";
    return 0;
}