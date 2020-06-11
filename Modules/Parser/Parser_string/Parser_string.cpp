#include "H_Parser_string.h"
#include "Parser_STROKES/Parser_STROKES.h"

string P_Massiv_Peremenn;
string P_Massiv_ARFMM = " > < = ";
string P_Massiv_ARFM_PLYSS = " + - * / ) ( ";
string STROKA_expression;

int Parser_ASSIGN(string Tests)
{
  
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    
    P_Massiv_Peremenn += TIN_PEREMENOE + " ";

        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE == "=")
        {
            ss >> TIN_PEREMENOE;
            P_Massiv_Peremenn += TIN_PEREMENOE + " ";
            ss >> TIN_PEREMENOE >> TIN_PEREMENOE;
            if (TIN_PEREMENOE == "}")
            {
                return 404;
            }           
        }
        else if (TIN_PEREMENOE == "==")
        {
            ss >> TIN_PEREMENOE;
            stringstream ss_2;
            string word;
            ss_2.str(P_Massiv_Peremenn);
            while (ss_2 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss_2 >> word;
                    P_Massiv_Peremenn += word + " ";
                    ss >> TIN_PEREMENOE >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == "}")
                    {
                        return 404;
                    }
                }
            }
        }

    return 1;
}

int Parser_STROKA(string Tests)
{
    string STROKA_expression;
    string KOSTL_STROKA_TIN_PEREMENOE;
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;

    stringstream ss_2;
    stringstream ss_3;
    string word;
    string Massiv_Peremenn_Kastl;
    ss_2.str(P_Massiv_Peremenn);
     while (ss_2 >> word)
     {
         if (word == TIN_PEREMENOE)
         {
             KOSTL_STROKA_TIN_PEREMENOE += word + " ";
             break;
         }
         else
         {
             KOSTL_STROKA_TIN_PEREMENOE += word + " ";
         }

     }
    ss >> TIN_PEREMENOE;
    while (ss >> TIN_PEREMENOE)
    {
        if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
        {
            
            ss_3.str(P_Massiv_Peremenn);
            while (ss_3 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss_3 >> word;
                    STROKA_expression += word;
                    break;
                } 
            }
        }
        else if (TIN_PEREMENOE != ";")
        {
         STROKA_expression += TIN_PEREMENOE;   
        }
    }
    exp_int();
    ss_2 >> word;
    KOSTL_STROKA_TIN_PEREMENOE += to_string(expression(STROKA_expression)) + " ";
    while (ss_2 >> word)
            {
              KOSTL_STROKA_TIN_PEREMENOE += word + " ";
            }

    P_Massiv_Peremenn = KOSTL_STROKA_TIN_PEREMENOE;
    ss >> TIN_PEREMENOE;
    if (TIN_PEREMENOE == "}")
    {
        return 404;
    }
    return 2060;
}

int  Parser_IF(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    long long chislo_1;
    long long chislo_2;

    if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        chislo_1 = atoll(TIN_PEREMENOE.c_str());
        ss >> TIN_PEREMENOE;
    }
    else 
    {
        stringstream ss_2;
        string word;
        ss_2.str(P_Massiv_Peremenn);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss_2 >> word;
               chislo_1 = atoll(word.c_str());
                ss >> TIN_PEREMENOE;
            }
        }
    }

    string P_ARF = TIN_PEREMENOE;
    ss >> TIN_PEREMENOE;

    if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        chislo_2 = atoll(TIN_PEREMENOE.c_str());
        ss >> TIN_PEREMENOE;
    }
    else
    {
        stringstream ss_2;
        string word;
        ss_2.str(P_Massiv_Peremenn);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss_2 >> word;
               chislo_2 = atoll(word.c_str());
                ss >> TIN_PEREMENOE;
            }
        }
    }

    if (P_ARF == "=")
    {
        if (chislo_1 == chislo_2)
        {
            return 10; 
        }
        else
        {
            return 5;
        }
    }
    else if (P_ARF == ">")
    {
        if (chislo_1  > chislo_2)
        {
            return 10;
        }
        else
        {
            return 5;
        }
    }
    else if (P_ARF == "<")
    {
        if (chislo_1 < chislo_2)
        {
            return 10;
        }
        else
        {
            return 5; 
        }
    }
    
    return 1;
}

int  Parser_WHILE(string Tests)
{

    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    long long chislo_1;
    long long chislo_2;

    if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        chislo_1 = atoll(TIN_PEREMENOE.c_str());
        ss >> TIN_PEREMENOE;
    }
    else
    {
        stringstream ss_2;
        string word;
        ss_2.str(P_Massiv_Peremenn);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss_2 >> word;
                chislo_1 = atoll(word.c_str());
                ss >> TIN_PEREMENOE;
            }
        }
    }

    string P_ARF = TIN_PEREMENOE;
    ss >> TIN_PEREMENOE;

    if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        chislo_2 = atoll(TIN_PEREMENOE.c_str());
        ss >> TIN_PEREMENOE;
    }
    else
    {
        stringstream ss_2;
        string word;
        ss_2.str(P_Massiv_Peremenn);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss_2 >> word;
                chislo_2 = atoll(word.c_str());
                ss >> TIN_PEREMENOE;
            }
        }
    }

    if (P_ARF == "=")
    {
        if (chislo_1 == chislo_2)
        {
            return 10; //запускаем IF
        }
        else
        {
            return 5; // не запускаем IF
        }
    }
    else if (P_ARF == ">")
    {
        if (chislo_1 > chislo_2)
        {
            return 10; //запускаем IF
        }
        else
        {
            return 5; // не запускаем IF
        }
    }
    else if (P_ARF == "<")
    {
        if (chislo_1 < chislo_2)
        {
            return 10; //запускаем IF
        }
        else
        {
            return 5; // не запускаем IF
        }
    }

    return 1; //некорректно задано условие
}

int Parser_COUT(string Tests)
{
	stringstream ss;
	string TIN_PEREMENOE;
	ss.str(Tests);
	ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;

    if (TIN_PEREMENOE[0] == '"')
    {
        TIN_PEREMENOE.erase(0, 1);
        TIN_PEREMENOE.erase(TIN_PEREMENOE.length()-1, 1);
        cout<< TIN_PEREMENOE <<endl; 
        ss >> TIN_PEREMENOE >> TIN_PEREMENOE;

            if (TIN_PEREMENOE == "}")
            {
                return 404;
            }
    }
    else if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        cout << TIN_PEREMENOE << endl; 
        ss >> TIN_PEREMENOE >> TIN_PEREMENOE;
            if (TIN_PEREMENOE == "}")
            {
                return 404;
            }
    }
    else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
    {
        stringstream ss_2;
        string word;
        ss_2.str(P_Massiv_Peremenn);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss_2 >> word;
                cout << word <<endl;
                ss >> TIN_PEREMENOE >> TIN_PEREMENOE;
                if (TIN_PEREMENOE == "}")
                {
                    return 404;
                }
            }
        }
    }
    return 1;
}

