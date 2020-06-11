#include "H_Lexer.h"
#include "Rules/H_Rules.h"

int kol_strok;
int ERROR;
///////////////////Dictionary///////////////////
const string ID_Operators[7] = { "IF",         // Условной оператор 
                           "WHILE",	  	 // Оператор вызова цикла while
                           "BREAK",      // Оператор для выхода из цикла, не дожидаясь его конца
                           "END_BODY",   // Оператор для пропуска остального тела цикла  и перехода в начало цикла
                           "COUT",       // Оператор вывода
                           "~",       // Оператор вывода
                           "ASSIGN"   // Оператор объявления переменой
};
////////////////////////////////////////////////

string lexx_Yberaem_Komments(string Tests)
{
    string Testt_Komment = "";
    int kostil = 0;
    for (int i = 0; i < Tests.size(); i++)
    {
        if (Tests[i] == ';' && (kostil % 2 == 0))
        {
            kol_strok++;
        }
        if (Tests[i] == '{')
        {
            kol_strok++;
        }
        if (Tests[i] == '#')
        {
            kostil++;
        }
        else if (kostil % 2 == 0)
        {
            Testt_Komment += Tests[i];
        }
    }
    if (kostil % 2 != 0)
    {
        cout << "ERROR(1000)! : НЕ ЗАКРЫТ КОМЕНТАРИЙ" << endl;
        return "ERROR";
    }
    return Testt_Komment;
}


string* lexx_minys_probelos_plus_mass_strok(string Testt)
{
    string word;
    string* dinamich_array = new string[kol_strok];
    stringstream ss;
    ss.str(Testt);
    int kostil, kostil_2 = 0, kostil_3 = 0;
    while (ss >> word)
    {
        string word_2;
        if (word == "(")
        {
            dinamich_array[kostil_2] += word + " ";
        }
        else  if (word == ")")
        {
            dinamich_array[kostil_2] += word + " ";
        }
        else
        {
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == '(')
                {
                    word_2 += "( ";
                }
                else if (word[i] == ')')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " ) ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " )";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += ") ";
                    }
                }
                else if (word[i] == '+')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " + ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " +";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "+ ";
                    }
                }
                else if (word[i] == '-')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " - ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " -";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "- ";
                    }
                }
                else if (word[i] == '*')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " * ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " *";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "* ";
                    }
                }
                else if (word[i] == '/')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " / ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " /";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "/ ";
                    }
                }
                else if (word[i] == '>')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " > ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " >";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "> ";
                    }
                }
                else if (word[i] == '<')
                {
                    if (i != 0)
                    {
                        if (word[i - 1] != ' ' && word[i + 1] != ' ')
                        {
                            word_2 += " < ";
                        }
                        else if (word[i - 1] != ' ')
                        {
                            word_2 += " <";
                        }
                    }
                    else if (word[i + 1] != ' ')
                    {
                        word_2 += "< ";
                    }
                }
                else if (word[i] == '=')
                {
                    if (word[i] == '=' && word[i + 1] == '=')
                    {
                        if (i != 0)
                        {
                            if (word[i - 1] != ' ' && word[i + 1] != ' ')
                            {
                                word_2 += " == ";
                            }
                            else if (word[i - 1] != ' ')
                            {
                                word_2 += " ==";
                            }
                        }
                        else if (word[i + 2] != ' ')
                        {
                            word_2 += "== ";
                        }
                    }
                    else
                    {
                        if (i != 0)
                        {
                            if (word[i - 1] != '=')
                            {
                                if (word[i - 1] != ' ' && word[i + 1] != ' ')
                                {
                                    word_2 += " = ";
                                }
                                else if (word[i - 1] != ' ')
                                {
                                    word_2 += " =";
                                }
                            }
                        }
                        else if (word[i + 1] != ' ')
                        {
                            word_2 += "= ";
                        }
                    }
                }
                else if (word[i] == '{')
                {
                    word_2 += "{";
                }
                else if (word[i] == '}')
                {
                    word_2 += "} ";
                }
                else
                {
                    word_2 += word[i];
                }
            }
            if (word_2[word_2.size() - 1] != ' ')
            {
                if (word_2 == ";")
                {
                    dinamich_array[kostil_2++] += word_2;
                    continue;
                }
                else if (word_2[word_2.size() - 1] == '{')
                {
                    word_2[word_2.size() - 1] = ' ';
                    dinamich_array[kostil_2++] += word_2 + "{";
                    continue;
                }
                else if (word_2[word_2.size() - 1] == '}')
                {
                    word_2[word_2.size() - 1] = ' ';
                    dinamich_array[kostil_2] += word_2 + " }";
                    continue;
                }
                else if (word_2[word_2.size() - 1] == ';')
                {
                    word_2[word_2.size() - 1] = ' ';
                    dinamich_array[kostil_2++] += word_2 + " ;";
                    continue;
                }

                dinamich_array[kostil_2] += word_2 + " ";
            }
            else
            {
                if (word_2 == "{ ")
                {
                    dinamich_array[kostil_2++] += word_2;
                    continue;
                }
                else if (word_2[word_2.size() - 2] == '{')
                {
                    word_2[word_2.size() - 1] = ' ';
                    dinamich_array[kostil_2++] += word_2 + "{";
                    continue;
                }
                else if (word_2 == "} ")
                {
                    kostil_2 = kostil_2 - 1;
                    dinamich_array[kostil_2++] += " " + word_2;
                    continue;
                }
                else if (word_2[word_2.size() - 2] == '}')
                {
                    if (word_2[word_2.size() - 1] == ' ')
                    {
                        if (word_2[word_2.size() - 3] == ';')
                        {
                            word_2[word_2.size() - 2] = ' ';
                            word_2[word_2.size() - 3] = ' ';
                            dinamich_array[kostil_2++] += word_2 + " ; }";
                            continue;
                        }
                        word_2[word_2.size() - 2] = ' ';
                        dinamich_array[kostil_2++] += word_2 + " }";
                        continue;
                    }
                    else
                    {
                        word_2[word_2.size() - 1] = ' ';
                        dinamich_array[1 - kostil_2++] += word_2 + " }";
                        continue;
                    }
                }
                else
                {
                    dinamich_array[kostil_2] += word_2;
                }
            }
        }
    }
    return dinamich_array;
}



string lexx_proverka_na_Syntax(string* Tests)
{
    int Kostl_IF = 0;
    string Stroka_komands_rardelitel;
    stringstream ERROR_str;
    for (int i = 0; i < kol_strok; i++)
    {
        ERROR = 1020;
        stringstream ss;
        ss.str(Tests[i]);
        ss >> Stroka_komands_rardelitel;
        for (int str_Opr = 0; str_Opr < _countof(ID_Operators); str_Opr++)
        {
            if (Stroka_komands_rardelitel == ID_Operators[str_Opr])
            {
                ss >> Stroka_komands_rardelitel;
                if ((Stroka_komands_rardelitel == ":") || (Stroka_komands_rardelitel == ";"))
                {                          
                    if (ID_Operators[str_Opr] == "COUT")
                    {
                        ERROR = Rule_COUT(Tests[i]); 
                    }
                    else if (ID_Operators[str_Opr] == "ASSIGN")
                    {
                        ERROR = Rule_ASSIGN(Tests[i]);
                    }
                    else if (ID_Operators[str_Opr] == "~")
                    {
                        ERROR = Rule_STROKA(Tests[i]);
                    }
                    else if (ID_Operators[str_Opr] == "IF")
                    {
                        Kostl_IF++;
                        ERROR = Rule_IF(Tests[i]);
                    }
                    else if (ID_Operators[str_Opr] == "WHILE")
                    {
                        Kostl_IF++;
                        ERROR = Rule_WHILE(Tests[i]);
                    }
                    else if (ID_Operators[str_Opr] == "BREAK" && Kostl_IF != 0)
                    {
                        ERROR = Rule_BREAK(Tests[i]);
                    }
                    else if (ID_Operators[str_Opr] == "END_BODY" && Kostl_IF != 0)
                    {
                        ERROR = Rule_END_BODY(Tests[i]);
                    }
                    break;
                }
                else
                {
                    ERROR = 1020;
                    break;
                }
            }
        }

        if (ERROR == 404)
        {
            //cout << "Всё ОК! } - закрыта в строке " << i + 1 << endl;
            Kostl_IF--;
        }
        else if (ERROR == 555)
        {
            // cout << "Всё ОК! в строке " << i + 1 << endl;
        }
        else if (ERROR == 1020)
        {
            ERROR_str << "ERROR(1020): В СТРОКЕ [" << i + 1 << "] - НЕТУ ТАКОЙ КОМАНДЫ ИЛИ ОШИБКА С РАЗДЕЛЕНИЕМ КОМАНДЫ (:)";
            return ERROR_str.str();
        }
        else if (ERROR == 1021)
        {
            ERROR_str << "ERROR(1021): В СТРОКЕ [" << i + 1 << "] - НЕТУ (;) ИЛИ НЕ ЗАКРЫТ ВЫВОД";
            return ERROR_str.str();
        }
        else if (ERROR == 1022)
        {
            ERROR_str << "ERROR(1022): В СТРОКЕ [" << i + 1 << "] - БОЛЬШЕ ЧЕМ ОДНА (.)";
            return ERROR_str.str();
        }
        else if (ERROR == 1023)
        {
            ERROR_str << "ERROR(1023): В СТРОКЕ [" << i + 1 << "] - СИНТАКТИЧЕСКАЯ ОШИБКА ";
            return ERROR_str.str();
        }
        else if (ERROR == 1024)
        {
            ERROR_str << "ERROR(1024): В СТРОКЕ [" << i + 1 << "] - НЕТУ ТАКОЙ ПЕРЕМЕННОЙ ДЛЯ ВЫВОДА ";
            return ERROR_str.str();
        }
        else if (ERROR == 3999)
        {
            ERROR_str << "ERROR(3999): В СТРОКЕ [" << i + 1 << "] - ПЕРВЫЙ СИМВОЛ, ДЛЯ ВЫВОДА ЧИСЛА, ТОЧКА";
            return ERROR_str.str();
        }
        else if (ERROR == 2031)
        {
            ERROR_str << "ERROR(2031): В СТРОКЕ [" << i + 1 << "] - НЕПОНЯТНО ЧТО ВЫ ХОТИТЕ ВЫВЕСТИ";
            return ERROR_str.str();
        }
        else if (ERROR == 2041)
        {
            ERROR_str << "ERROR(2041): В СТРОКЕ [" << i + 1 << "] - УКАЗАН НЕ ВЕРНЫЙ ТИП ПЕРЕМЕНОЙ";
            return ERROR_str.str();
        }
        else if (ERROR == 2042)
        {
            ERROR_str << "ERROR(2042): В СТРОКЕ [" << i + 1 << "] - УКАЗАНА НЕВЕРНАЯ АРИФМЕТИКА";
            return ERROR_str.str();
        }
        else if (ERROR == 2043)
        {
            ERROR_str << "ERROR(2043): В СТРОКЕ [" << i + 1 << "] - ПЕРЕМЕНАЯ НАЧИНАЕТСЯ С ЗАПРЕЩЕНОГО СИМВОЛА";
            return ERROR_str.str();
        }
        else if (ERROR == 2044)
        {
            ERROR_str << "ERROR(2044): В СТРОКЕ [" << i + 1 << "] - ПЕРЕМЕНАЯ НАЧИНАЕТСЯ С ЗАПРЕЩЕНОГО СИМВОЛА";
            return ERROR_str.str();
        }
        else if (ERROR == 2045)
        {
            ERROR_str << "ERROR(2045): В СТРОКЕ [" << i + 1 << "] - ПЕРЕМЕНАЯ ВЫХОДИТ ИЗ 32 БИТНОГО ДИАПАЗОНА";
            return ERROR_str.str();
        }
        else if (ERROR == 2046)
        {
            ERROR_str << "ERROR(2046): В СТРОКЕ [" << i + 1 << "] - СТРОКА НЕ КОРРЕКТНО ЗАКОНЧИЛАСЬ (;)";
            return ERROR_str.str();
        }
        else if (ERROR == 2047)
        {
            ERROR_str << "ERROR(2047): В СТРОКЕ [" << i + 1 << "] - НЕТУ ТАКОЙ ПЕРЕМЕНОЙ";
            return ERROR_str.str();
        }
        else if (ERROR == 2048)
        {
            ERROR_str << "ERROR(2048): В СТРОКЕ [" << i + 1 << "] - ПЕРЕМЕНАЯ С ТАКИМ ИМЕНЕМ УЖЕ СУЩЕСТВУЕТ";
            return ERROR_str.str();
        }
        else if (ERROR == 2050)
        {
            ERROR_str << "ERROR(2050): В СТРОКЕ [" << i + 1 << "] - НЕКОРРЕКТНО ЗАДАНО УСЛОВИЕ";
            return ERROR_str.str();
        }
        else if (ERROR == 2051)
        {
            ERROR_str << "ERROR(2051): В СТРОКЕ [" << i + 1 << "] - ЧИСЛО НЕКОРРЕКТНО";
            return ERROR_str.str();
        }
        else if (ERROR == 2060)
        {
            ERROR_str << "ERROR(2060): В СТРОКЕ [" << i + 1 << "] - НЕПОНЯТНО ЧТО ВЫ ХОТИТЕ СДЕЛАТЬ";
            return ERROR_str.str();
        }
        else if (ERROR == 2061)
        {

            ERROR_str << "ERROR(2061): В СТРОКЕ [" << i + 1 << "] - ПРОБЛЕМА СО СКОБКАМИ";
            return ERROR_str.str();
        }
    }
    if (Kostl_IF != 0)
    {
        ERROR_str << "ERROR(9999):    ПРОБЛЕМА СО СКОБКАМИ { }";
        return ERROR_str.str();
    }
    return "";
}

int KOL_strok()
{
    return kol_strok;
}
