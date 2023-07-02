#ifndef CAESARENCRYPTOR_H
#define CAESARENCRYPTOR_H

#include <Encryptor.h>


class CaesarEncryptor : public Encryptor
{
    public:
        CaesarEncryptor();
        virtual ~CaesarEncryptor();
        std::string encryptLine(std::string line) override;
        std::string decryptLine(std::string line) override;
        std::string encryptLine(std::string line, int tmpModifier);
        std::string decryptLine(std::string line, int tmpModifier);
        void setDefaultModifier(int _mod);
    private:
        int mod;
};

#endif // CAESARENCRYPTOR_H
