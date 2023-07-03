#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <bits/stdc++.h>

class Encryptor
{
    public:
        Encryptor();
        virtual ~Encryptor();
        virtual void encryptLine(char* buffer, int bufferSize) = 0;
        virtual void decryptLine(char* buffer, int bufferSize) = 0;
        void encryptFile(std::string fileName);
        void decryptFile(std::string fileName);

    protected:
        std::string extension;
};

#endif // ENCRYPTOR_H
