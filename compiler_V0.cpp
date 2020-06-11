#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Modules/Lexer/H_Lexer.h"
#include "Modules/Parser/H_Parser.h"
#include <windows.h>

using namespace std;


string Proverka_fail()
{

    ifstream TextFile("Test/1.txt");           
   string Test;
    char temp;
    if (!TextFile) {
        cerr << "ERROR(-1)! :  ФАЙЛ НЕ НАЙДЕН" << endl;
        return Test;
    }

    TextFile.unsetf(ios::skipws);
    while (TextFile >> temp)                         
    {
        Test += temp;
    }                                           
    TextFile.close();                                     
    
    return Test;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string Testt = Proverka_fail();
    string* mass_strok;
    string ERRORR;
    if (Testt == "")
    {
        cout << "ERROR(0)! :  ФАЙЛ ПУСТОЙ!" << endl;
    }
    else
    {
        
       Testt = lexx_Yberaem_Komments(Testt);
       if (Testt != "ERROR(101): ОТСУТСТВУЕТ КОД!")
       {
           mass_strok = lexx_minys_probelos_plus_mass_strok(Testt);
           ERRORR = lexx_proverka_na_Syntax(mass_strok);
           if (ERRORR == "")
           {
               int Kol_strok = KOL_strok();
               Parser_1(Kol_strok, mass_strok);
           }
           else 
           {
                cout << ERRORR << endl;
           }
       }
    }

    system("pause");
    return 0;
}

