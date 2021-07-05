#ifndef Arquivo_hpp
#define Arquivo_hpp

#include <vector>
#include <iostream>

using namespace std;

class Arquivo{
    private:
        string local;
    public:
        Arquivo(string local_);
        bool read_lines(int n, vector<string> &linha);
};

#endif