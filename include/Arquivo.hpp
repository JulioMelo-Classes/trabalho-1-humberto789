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
        void write_ln(string texto);
        vector<string> read_lines(int n);
};

#endif