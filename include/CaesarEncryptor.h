#ifndef CAESARENCRYPTOR_H
#define CAESARENCRYPTOR_H

#include <Encryptor.h>


class CaesarEncryptor : public Encryptor
{
    public:
        CaesarEncryptor();
        virtual ~CaesarEncryptor();
        void encryptLine(char* buffer, int bufferSize) override;
        void decryptLine(char* buffer, int bufferSize) override;
        void encryptLine(char* buffer, int bufferSize, int tmpModifier);
        void decryptLine(char* buffer, int bufferSize, int tmpModifier);
        void setDefaultModifier(int _mod);
    private:
        int mod=3;
};

#endif // CAESARENCRYPTOR_H
