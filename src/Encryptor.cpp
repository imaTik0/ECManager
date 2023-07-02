#include "Encryptor.h"

Encryptor::Encryptor()
{
}

Encryptor::~Encryptor()
{
}

void Encryptor::encryptFile(std::string fileName)
{
    std::ifstream input(fileName);
    std::ofstream output(fileName + '.' + extension);
    std::string line;

    if (input.is_open() && output.is_open())
    {
        while (getline(input, line))
            output<< encryptLine(line) << std::endl;
    }

    input.close();
    output.close();
}

void Encryptor::decryptFile(std::string fileName)
{
    if (fileName.substr(fileName.find_last_of(".") + 1) != extension)
    {
        std::cout << "Niepoprawny rodzaj pliku!" << std::endl;
    }
    else
    {
        std::ifstream input(fileName);
        std::ofstream output(fileName.substr(0, fileName.length() - extension.length()));
        std::string line;

        if (input.is_open() && output.is_open())
        {
            while (getline(input, line))
            {
                output << decryptLine(line) << std::endl;
            }
        }

        input.close();
        output.close();
    }
}
