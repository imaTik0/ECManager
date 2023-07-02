#include "CaesarEncryptor.h"

CaesarEncryptor::CaesarEncryptor()
{
    extension = "CSR";
}

CaesarEncryptor::~CaesarEncryptor()
{
}

void CaesarEncryptor::setDefaultModifier(int _mod)
{
    mod = _mod;
}

std::string CaesarEncryptor::encryptLine(std::string line, int tmpModifier)
{
    for (int i = 0; i < line.length(); i++)
    {
        line[i] += tmpModifier;
    }

    return line;
}

std::string CaesarEncryptor::decryptLine(std::string line, int tmpModifier)
{
    for (int i = 0; i < line.length(); i++)
    {
        line[i] -= tmpModifier;
    }

    return line;
}

std::string CaesarEncryptor::encryptLine(std::string line)
{
    return encryptLine(line, mod);
}

std::string CaesarEncryptor::decryptLine(std::string line)
{
    return decryptLine(line, mod);
}
