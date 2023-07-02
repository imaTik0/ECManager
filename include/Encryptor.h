#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <bits/stdc++.h>

class Encryptor
{
    public:
        Encryptor();
        virtual ~Encryptor();
        virtual std::string encryptLine(std::string line) = 0;
        virtual std::string decryptLine(std::string line) = 0;
        void encryptFile(std::string fileName);
        void decryptFile(std::string fileName);

    protected:
        std::string extension;
};

#endif // ENCRYPTOR_H
