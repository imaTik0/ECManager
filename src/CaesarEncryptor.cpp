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

void CaesarEncryptor::encryptLine(char* buffer, int bufferSize, int tmpModifier)
{
    for (int i = 0; i < bufferSize; i++)
    {
        buffer[i] += tmpModifier;
    }
}

void CaesarEncryptor::decryptLine(char* buffer, int bufferSize, int tmpModifier)
{
    for (int i = 0; i < bufferSize; i++)
    {
        buffer[i] -= tmpModifier;
    }
}

void CaesarEncryptor::encryptLine(char* buffer, int bufferSize)
{
    return encryptLine(buffer,bufferSize, mod);
}

void CaesarEncryptor::decryptLine(char* buffer, int bufferSize)
{
    return decryptLine(buffer,bufferSize, mod);
}
