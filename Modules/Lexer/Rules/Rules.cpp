#include "H_Rules.h"

string Massiv_Peremen;
string Massiv_ARFM = " > < = ";
string Massiv_ARFM_PLYS = " + - * / ";

///////////////////Dictionary///////////////////
const string ID_Operators[7] = { "IF",         // Условный оператор 
                           "WHILE",	  	 // Оператор вызова цикла while
                           "BREAK",      // Оператор для выхода из цикла, не дожидаясь его конца
                           "END_BODY",   // Оператор для пропуска остального тела цикла  и перехода в начало цикла
                           "COUT",       // Оператор вывода
                           "~",       // Вычислительная строка
                           "ASSIGN"   // Оператор объявления переменой
};
////////////////////////////////////////////////

int Rule_COUT(string Tests)
{
    int kostl_1 = 0;

    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;

    if (TIN_PEREMENOE[0] == '"')
    {
        for (int i = 1; i < TIN_PEREMENOE.length(); i++)
        {
            if (TIN_PEREMENOE[i] == '"')
            {
                ss >> TIN_PEREMENOE;
                if (TIN_PEREMENOE == ";")
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == "}")
                    {
                        return 404;
                    }
                    return 555;
                }
                else
                {
                    return  1021;
                }
            }
        }

    }

    else if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
    {
        for (int i = 1; i < TIN_PEREMENOE.length(); i++)
        {
            if ((TIN_PEREMENOE[i] >= '0' && TIN_PEREMENOE[i] <= '9') || (TIN_PEREMENOE[i] == '.')) 
            {
                if ((TIN_PEREMENOE[i] == '.') && (kostl_1 == 0))
                {
                    kostl_1++;
                }
                else if ((TIN_PEREMENOE[i] == '.') && kostl_1 != 0)
                {
                    return  1022;
                }
            }
            else
            {
                return  1023; 
            }
        }
        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE == ";") 
        {
            ss >> TIN_PEREMENOE;
            if (TIN_PEREMENOE == "}")
            {
                return 404;
            }
            return 555;
        }
        else
        {
            return  1021;
        }
    }


    else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
    {
        stringstream ss_2;
        string word;
        ss_2.str(Massiv_Peremen);
        while (ss_2 >> word)
        {
            if (word == TIN_PEREMENOE)
            {
                ss >> TIN_PEREMENOE;
                if (TIN_PEREMENOE == ";")
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == "}")
                    {
                        return 404;
                    }
                    return 555;
                }
                else
                {
                    return 2046;
                }
            }
        }
        return 1024;
    }
    else if (TIN_PEREMENOE[0] == '.') 
    {
        return 3999; 
    }
    return 2031;
}

int Rule_ASSIGN(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;

    if (TIN_PEREMENOE == "INT")
    {
        ss >> TIN_PEREMENOE;
        for (int i = 0; i < TIN_PEREMENOE.length(); i++)
        {
            if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
            {
                if ((TIN_PEREMENOE[i] >= 'a' && TIN_PEREMENOE[i] <= 'z') || (TIN_PEREMENOE[i] >= 'A' && TIN_PEREMENOE[i] <= 'Z') || (TIN_PEREMENOE[i] >= '0' && TIN_PEREMENOE[i] <= '9'))
                {
                    continue;
                }
                else
                {
                    return 2044;
                }
            }
            else
            {
                return 2043;
            }
        }

        stringstream ss_2_1;
        string word_2_1;
        ss_2_1.str(Massiv_Peremen);
        while (ss_2_1 >> word_2_1)
        {
            if (word_2_1 == TIN_PEREMENOE)
            {
                return 2048;
            }
        }
        Massiv_Peremen += TIN_PEREMENOE + " "; 
        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE == "=")
        {
            ss >> TIN_PEREMENOE;
            long long chislo = atoll(TIN_PEREMENOE.c_str());
            if (chislo >= INT_MIN && chislo <= INT_MAX)
            {
                ss >> TIN_PEREMENOE;
                if (TIN_PEREMENOE == ";")
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == "}")
                    {
                        return 404;
                    }
                    return 555;
                }
                else
                {
                    return 2046;
                }
            }
            else
            {
                return 2045;
            }
        }
        else if (TIN_PEREMENOE == "==")
        {
            ss >> TIN_PEREMENOE;
            stringstream ss_2;
            string word;
            ss_2.str(Massiv_Peremen);
            while (ss_2 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == ";")
                    {
                        ss >> TIN_PEREMENOE;
                        if (TIN_PEREMENOE == "}")
                        {
                            return 404;
                        }
                        return 555;
                    }
                    else
                    {
                        return 2046;
                    }
                }
            }
            return 2047;
        }
        else
        {
            return 2042;
        }
    }

    else if (TIN_PEREMENOE == "FLOAT")
    {
        ss >> TIN_PEREMENOE;
        for (int i = 0; i < TIN_PEREMENOE.length(); i++)
        {
            if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
            {
                if ((TIN_PEREMENOE[i] >= 'a' && TIN_PEREMENOE[i] <= 'z') || (TIN_PEREMENOE[i] >= 'A' && TIN_PEREMENOE[i] <= 'Z') || (TIN_PEREMENOE[i] >= '0' && TIN_PEREMENOE[i] <= '9'))
                {
                    continue;
                }
                else
                {
                    return 2044;
                }
            }
            else
            {
                return 2043;
            }
        }
        stringstream ss_2_1;
        string word_2_1;
        ss_2_1.str(Massiv_Peremen);
        while (ss_2_1 >> word_2_1)
        {
            if (word_2_1 == TIN_PEREMENOE)
            {
                return 2048;
            }
        }
        Massiv_Peremen += TIN_PEREMENOE + " ";
        ss >> TIN_PEREMENOE;

        if (TIN_PEREMENOE == "=")
        {
            ss >> TIN_PEREMENOE;
            float chislo = atof(TIN_PEREMENOE.c_str());
            if (chislo >= _I32_MIN && chislo <= _UI32_MAX)
            {
                ss >> TIN_PEREMENOE;
                if (TIN_PEREMENOE == ";")
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == "}")
                    {
                        return 404;
                    }
                    return 555;
                }
                else
                {
                    return 2046;
                }
            }
            else
            {
                return 2045;
            }
        }

        else if (TIN_PEREMENOE == "==")
        {
            ss >> TIN_PEREMENOE;
            stringstream ss_2;
            string word;
            ss_2.str(Massiv_Peremen);
            while (ss_2 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss >> TIN_PEREMENOE;
                    if (TIN_PEREMENOE == ";")
                    {
                        ss >> TIN_PEREMENOE;
                        if (TIN_PEREMENOE == "}")
                        {
                            return 404;
                        }
                        return 555;
                    }
                    else
                    {
                        return 2046;
                    }
                }
            }
            return 2047;
        }
        else
        {
            return 2042;
        }
    }
    else
    {
        return 2041;
    }
    cout << endl;
    return 2031;
}

int Rule_IF(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    if (TIN_PEREMENOE == "(")
    {
        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
        {
            long long chislo = atoll(TIN_PEREMENOE.c_str());
            if ((chislo >= INT_MIN && chislo <= INT_MAX))
            {
                ss >> TIN_PEREMENOE;
                stringstream ss_2;
                string word;
                ss_2.str(Massiv_ARFM);
                while (ss_2 >> word)
                {
                    if (word == TIN_PEREMENOE)
                    {
                        ss >> TIN_PEREMENOE;
                        if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
                        {
                            chislo = atoll(TIN_PEREMENOE.c_str());
                            if ((chislo >= INT_MIN && chislo <= INT_MAX))
                            {
                                ss >> TIN_PEREMENOE;
                                if (TIN_PEREMENOE != ")")
                                {
                                    return 2050;
                                }
                                ss >> TIN_PEREMENOE;
                                if (TIN_PEREMENOE == "{")
                                {
                                    return 555;
                                }
                            }
                            else
                            {
                                return 2051;
                            }
                        }

                        else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
                        {
                            ss_2.str(Massiv_Peremen);
                            while (ss_2 >> word)
                            {
                                if (word == TIN_PEREMENOE)
                                {
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE != ")")
                                    {
                                        return 2050;
                                    }
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE == "{")
                                    {
                                        return 555;
                                    }
                                }
                            }

                        }

                    }
                }
            }
            else
            {
                return 2051;
            }
        }

        else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
        {
            stringstream ss_2;
            string word;
            ss_2.str(Massiv_Peremen);
            while (ss_2 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss >> TIN_PEREMENOE;
                    ss_2.str(Massiv_ARFM);
                    while (ss_2 >> word)
                    {
                        if (word == TIN_PEREMENOE)
                        {
                            ss >> TIN_PEREMENOE;
                            if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
                            {
                                long long chislo = atoll(TIN_PEREMENOE.c_str());
                                if ((chislo >= INT_MIN && chislo <= INT_MAX))
                                {
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE != ")")
                                    {
                                        return 2050;
                                    }
                                    ss >> TIN_PEREMENOE;

                                    if (TIN_PEREMENOE == "{")
                                    {
                                        return 555; 
                                    }
                                }
                                else
                                {
                                    return 2051;
                                }
                            }

                            else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
                            {
                                ss_2.str(Massiv_Peremen);
                                while (ss_2 >> word)
                                {
                                    if (word == TIN_PEREMENOE)
                                    {
                                        ss >> TIN_PEREMENOE;
                                        if (TIN_PEREMENOE != ")")
                                        {
                                            return 2050;
                                        }
                                        ss >> TIN_PEREMENOE;
                                        if (TIN_PEREMENOE == "{")
                                        {
                                            return 555; 
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 2050;
}

int Rule_STROKA(string Tests)
{
    int kostl = 0;
    int kostl_1 = 0;
    int kostl_2 = 0;
    int kostl_3 = 0;
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    stringstream ss_2;
    string word;
    ss_2.str(Massiv_Peremen);
    while (ss_2 >> word)
    {
        if (word == TIN_PEREMENOE)
        {
            ss >> TIN_PEREMENOE;
            if (TIN_PEREMENOE == "=")
            {
                while (ss >> TIN_PEREMENOE)
                {

                    if (TIN_PEREMENOE == ";") 
                    {
                        if (kostl_2 == 0)
                        {
                            ss >> TIN_PEREMENOE;
                            if (TIN_PEREMENOE == "}")
                            {
                                return 404;
                            }
                            return 555;
                        }
                        else
                        {
                            return 2061;
                        }
                    }
                    else if (TIN_PEREMENOE == "(" || TIN_PEREMENOE == ")")
                    {
                        if (TIN_PEREMENOE == "(")
                        {
                            kostl_2++;
                        }
                        else
                        {
                            kostl_2--;
                        }
                    }

                    else if (kostl % 2 != 0)
                    {
                        ss_2.str(Massiv_ARFM_PLYS);
                        while (ss_2 >> word)
                        {
                            kostl++;
                            break;
                        }
                        if (kostl % 2 != 0)
                        {
                            return 2060;
                        }
                    }

                    else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
                    {
                        ss_2.str(Massiv_Peremen);
                        kostl_3 == 0;
                        while (ss_2 >> word)
                        {
                            if (word == TIN_PEREMENOE)
                            {
                                kostl_3++;
                                kostl++;
                                break;
                            }
                        }
                        if (kostl_3 == 0)
                        {
                            return 2060;
                        }
                        continue;
                    }

                    else if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
                    {
                        for (int i = 1; i < TIN_PEREMENOE.length(); i++)
                        {
                            if ((TIN_PEREMENOE[i] >= '0' && TIN_PEREMENOE[i] <= '9') || (TIN_PEREMENOE[i] == '.'))
                            {
                                if ((TIN_PEREMENOE[i] == '.') && (kostl_1 == 0))
                                {
                                    kostl_1++;
                                }
                                else if ((TIN_PEREMENOE[i] == '.') && kostl_1 != 0)
                                {
                                    return  1022;
                                }
                            }
                            else
                            {
                                return  1023;
                            }
                        }
                        kostl++;
                    }
                }
            }
        }
    }
    return 2060;
}

int Rule_WHILE(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE >> TIN_PEREMENOE;
    if (TIN_PEREMENOE == "(")
    {
        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
        {
            long long chislo = atoll(TIN_PEREMENOE.c_str());
            if ((chislo >= INT_MIN && chislo <= INT_MAX))
            {
                ss >> TIN_PEREMENOE;
                stringstream ss_2;
                string word;
                ss_2.str(Massiv_ARFM);
                while (ss_2 >> word)
                {
                    if (word == TIN_PEREMENOE)
                    {
                        ss >> TIN_PEREMENOE;
                        if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
                        {
                            chislo = atoll(TIN_PEREMENOE.c_str());
                            if ((chislo >= INT_MIN && chislo <= INT_MAX))
                            {
                                ss >> TIN_PEREMENOE;
                                if (TIN_PEREMENOE != ")")
                                {
                                    return 2050;
                                }
                                ss >> TIN_PEREMENOE;
                                if (TIN_PEREMENOE == "{")
                                {
                                    return 555;
                                }
                            }
                            else
                            {
                                return 2051;
                            }
                        }

                        else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
                        {
                            ss_2.str(Massiv_Peremen);
                            while (ss_2 >> word)
                            {
                                if (word == TIN_PEREMENOE)
                                {
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE != ")")
                                    {
                                        return 2050;
                                    }
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE == "{")
                                    {
                                        return 555;
                                    }
                                }
                            }

                        }

                    }
                }
            }
            else
            {
                return 2051;
            }
        }

        else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
        {
            stringstream ss_2;
            string word;
            ss_2.str(Massiv_Peremen);
            while (ss_2 >> word)
            {
                if (word == TIN_PEREMENOE)
                {
                    ss >> TIN_PEREMENOE;
                    ss_2.str(Massiv_ARFM);
                    while (ss_2 >> word)
                    {
                        if (word == TIN_PEREMENOE)
                        {
                            ss >> TIN_PEREMENOE;
                            if (TIN_PEREMENOE[0] >= '0' && TIN_PEREMENOE[0] <= '9')
                            {
                                long long chislo = atoll(TIN_PEREMENOE.c_str());
                                if ((chislo >= INT_MIN && chislo <= INT_MAX))
                                {
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE != ")")
                                    {
                                        return 2050; 
                                    }
                                    ss >> TIN_PEREMENOE;
                                    if (TIN_PEREMENOE == "{")
                                    {
                                        return 555;
                                    }
                                }
                                else
                                {
                                    return 2051;
                                }
                            }

                            else if ((TIN_PEREMENOE[0] >= 'a' && TIN_PEREMENOE[0] <= 'z') || (TIN_PEREMENOE[0] >= 'A' && TIN_PEREMENOE[0] <= 'Z'))
                            {
                                ss_2.str(Massiv_Peremen);
                                while (ss_2 >> word)
                                {
                                    if (word == TIN_PEREMENOE)
                                    {
                                        ss >> TIN_PEREMENOE;
                                        if (TIN_PEREMENOE != ")")
                                        {
                                            return 2050; 
                                        }
                                        ss >> TIN_PEREMENOE;
                                        if (TIN_PEREMENOE == "{")
                                        {
                                            return 555;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 2050; 
}

int Rule_BREAK(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE;

    if (TIN_PEREMENOE == ";")
    {
        if (TIN_PEREMENOE == "}")
        {
            return 404;
        }
        return 555;
    }
    return 2060;
}

int Rule_END_BODY(string Tests)
{
    stringstream ss;
    string TIN_PEREMENOE;
    ss.str(Tests);
    ss >> TIN_PEREMENOE >> TIN_PEREMENOE;

    if (TIN_PEREMENOE == ";")
    {
        ss >> TIN_PEREMENOE;
        if (TIN_PEREMENOE == "}")
        {
            return 404;
        }
        return 555;
    }
    return 2046;
}
