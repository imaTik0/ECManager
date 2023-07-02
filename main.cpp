#include <bits/stdc++.h>
#include <fstream>
//#include "Encryptor.h"
#include "Huffman.h"
using namespace std;

int main()
{
    Huffman HUF;
    int choice,choice2;
    string line;
    cout<<"Witaj w menedzerze kodowania plikow!"<<endl;
    while(1)
    {
        cout<<"Co chcesz zrobic?"<<endl;
        cout<<"1. Szyfrowanie za pomoca szyfru Playfaira (konsola)"<<endl;
        cout<<"2. Szyfrowanie za pomoca szyfru Playfaira (plik)"<<endl;
        cout<<"3. Szyfrowanie za pomoca szyfru Cezara (konsola)"<<endl;
        cout<<"4. Szyfrowanie za pomoca szyfru Cezara (plik)"<<endl;
        cout<<"5. Kodowanie za pomoca kodu Morsa (konsola)"<<endl;
        cout<<"6. Kodowanie za pomoca kodu Morsa (plik)"<<endl;
        cout<<"7. Kompresowanie pliku za pomoca kodowania Huffmana"<<endl;
        cout<<"8. Opusc program"<<endl;
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            /*case 1:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    PlayfairEncryptor PLF;
                    cout<<"Podaj slowo kodowe"<<endl;
                    cin>>line;
                    PLF.setKeyword(line);
                    cin.ignore();
                    cout<<"Podaj tekst do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        cout<<PLF.encryptLine(line)<<endl;
                    else
                        cout<<PLF.decryptLine(line)<<endl;
                    break;
                }
            case 2:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    PlayfairEncryptor PLF;
                    cout<<"Podaj slowo kodowe"<<endl;
                    cin>>line;
                    PLF.setKeyword(line);
                    cin.ignore();
                    cout<<"Podaj nazwe pliku do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        PLF.encryptFile(line);
                    else
                        PLF.decryptFile(line);
                    break;
                }
            case 3:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    cin.ignore();
                    CaesarEncryptor CSR;
                    cout<<"Podaj tekst do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        cout<<CSR.encryptLine(line)<<endl;
                    else
                        cout<<CSR.decryptLine(line)<<endl;
                    break;
                }
            case 4:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    cin.ignore();
                    CaesarEncryptor CSR;
                    cout<<"Podaj nazwe pliku do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        CSR.encryptFile(line);
                    else
                        CSR.decryptFile(line);
                    break;
                }
            case 5:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    cin.ignore();
                    MorseEncryptor MC;
                    cout<<"Podaj tekst do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        cout<<MC.encryptLine(line)<<endl;
                    else
                        cout<<MC.decryptLine(line)<<endl;
                    break;
                }
            case 6:
                {
                    cout<<"Chcesz szyfrowac(1) czy deszyfrowac(2)?"<<endl;
                    cin>>choice2;
                    cin.ignore();
                    MorseEncryptor MC;
                    cout<<"Podaj nazwe pliku do zaszyfrowania/odszyfrowania"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        MC.encryptFile(line);
                    else
                        MC.decryptFile(line);
                    break;
                }*/
            case 7:
                {
                    cout<<"Chcesz kompresowac(1) czy dekompresowac(2)? (Uwaga! po zakonczeniu dzialania programu stracisz drzewo Huffmana!)"<<endl;
                    cin>>choice2;
                    cin.ignore();
                    cout<<"Podaj nazwe pliku"<<endl;
                    getline(cin,line);
                    if(choice2==1)
                        HUF.compressFile(line);
                    else
                        HUF.decompressFile(line);
                    break;
                }
            case 8:
                    cout<<"Zegnam!"<<endl;
                    exit(0);
                    break;
            default:
                    cout<<"Niepoprawny wybor!"<<endl;
                    break;




        }
    }
	return 0;
}
