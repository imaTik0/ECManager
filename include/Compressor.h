#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <bits/stdc++.h>




class Compressor
{
    public:
        Compressor();
        virtual ~Compressor();
		virtual std::string encode(char *text, int size) = 0;
        virtual std::string decode(std::string &text) = 0;
        void writeBit(std::ofstream &out, char bit);
        void writeBits(std::ofstream &out, std::string bits);
        std::string readBitsFromFile(std::ifstream &file,int bufferSize);
    protected:
        std::string extension;
};

#endif // COMPRESSOR_H
