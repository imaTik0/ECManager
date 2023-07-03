#include "Encryptor.h"

Encryptor::Encryptor()
{
}

Encryptor::~Encryptor()
{
}

void Encryptor::encryptFile(std::string fileName)
{
    std::ifstream input(fileName, std::ios::binary);
    std::ofstream output(fileName + '.' + extension, std::ios::binary);
    std::string line;
    char * buffer = new char[1024];

    if (input.is_open() && output.is_open())
    {
        /*while (getline(input, line))
            output<< encryptLine(line) << std::endl;*/
            while(!input.eof())
            {
                input.read(buffer,sizeof(buffer));
                //line=buffer;
                //printf("%s",buffer);
                //std::cout<<line;
                //line=encryptLine(line);
                //strcpy(buffer, line.c_str());
                encryptLine(buffer,1024);
                output.write(buffer,sizeof(buffer));
            }
    }

    input.close();
    output.close();
}

void Encryptor::decryptFile(std::string fileName)
{
    if (fileName.substr(fileName.find_last_of(".") + 1) != extension)
    {
        std::cerr << "Niepoprawny rodzaj pliku!" << std::endl;
    }
    else
    {
        std::ifstream input(fileName,std::ios::binary);
        std::ofstream output(fileName.substr(0, fileName.length() - extension.length()),std::ios::binary);
        std::string line;
        char * buffer = new char[1024];

        if (input.is_open() && output.is_open())
        {
            while(!input.eof())
            {
                input.read(buffer,sizeof(buffer));
                //line=buffer;
                //line=decryptLine(line);
                //strcpy(buffer, line.c_str());
                decryptLine(buffer,1024);
                output.write(buffer,sizeof(buffer));
            }
            /*while (read(input, line))
            {
                output << decryptLine(line) << std::endl;
            }*/
        }

        input.close();
        output.close();
    }
}
