#include <bits/stdc++.h>
#include <fstream>
#include "CaesarEncryptor.h"
#include "Huffman.h"
using namespace std;

int main()
{
    string choice;
    cout<<"Welcome to the ECManager"<<endl;
    cout<<"type \"help\" to view list of commands"<<endl;
    while(1)
    {
        cin>>choice;
        cin.ignore();
        if(choice=="help")
        {
            cout<<"help                         --- lists commands"<<endl;
            cout<<"ECHuffman [-e][-d] <file>    --- compress[-e] or decompress[-d] <file> using Huffman encoding"<<endl;
            cout<<"ECCaesar [-e][-d] <file>     --- encrypt[-e] or decrypt[-d] <file> using Caesar cipher"<<endl;
            cout<<"exit                         --- exits program"<<endl;
            //cout<<"ECRSA <file> --- encrypt <file> using RSA"<<endl;
        }
        else if(choice == "ECHuffman")
        {
            Huffman HUF;
            string flag;
            string fileName;
            cin>>flag>>fileName;
            if(flag == "-e")
            {
                HUF.compressFile(fileName);
                cout<<"File compressed as "<<fileName<<".HUF"<<endl;
            }
            else if(flag == "-d")
            {
                HUF.decompressFile(fileName);
                cout<<"File decompressed"<<endl;
            }
            else
            {
                cout<<"Wrong syntax"<<endl;
            }
        }
        else if(choice == "ECCaesar")
        {
            CaesarEncryptor CSR;
            string flag;
            string fileName;
            cin>>flag>>fileName;
            if(flag == "-e")
            {
                CSR.encryptFile(fileName);
                cout<<"File encrypted as "<<fileName<<".CSR"<<endl;
            }
            else if(flag == "-d")
            {
                CSR.decryptFile(fileName);
                cout<<"File decrypted"<<endl;
            }
            else
            {
                cout<<"Wrong syntax"<<endl;
            }
        }
        else if(choice == "exit")
        {
            exit(1);
        }
        else
        {
            cout<<"Error! Command does not exist!"<<endl;
        }
    }
	return 0;
}
