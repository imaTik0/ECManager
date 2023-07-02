#include "Compressor.h"

Compressor::Compressor()
{
    //ctor
}

Compressor::~Compressor()
{
    //dtor
}

void Compressor::writeBit(std::ofstream &out, char bit)
{
	static char buf = 0;
    static int pos = 7;

    buf |= (bit & 1) << pos;
    pos--;

    if (pos < 0)
    {
        out.write(&buf,1);
        buf = 0;
        pos = 7;
    }
}

void Compressor::writeBits(std::ofstream &out, std::string bits)
{
    for (int i = 0; i < bits.length(); i++)
    {
        writeBit(out, bits[i]);
    }
}

std::string Compressor::readBitsFromFile(std::ifstream &file,int bufferSize)
{
    std::stringstream bitstream;
    char c;
    if (file.is_open())
    {
        char buffer[bufferSize];
        file.read(buffer, sizeof(buffer));
        for(int i=0; i<file.gcount();i++)
        {
            for (int j = 7; j >= 0; j--)
            {
                bitstream<<((buffer[i] &(1 << j)) ? '1' : '0');
            }

        }
    }
    return bitstream.str();
}
