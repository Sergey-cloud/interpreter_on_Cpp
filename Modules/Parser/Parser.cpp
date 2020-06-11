#include "H_Parser.h"
#include "Parser_string/H_Parser_string.h"

int P_kol_strok;
int P_ERROR = 10;

string Parser_1(int kols_strok, string* Tests)
{
    P_kol_strok = kols_strok;
    int Kostl_IF = 0, Kostl_IF_2 = 0;
    int Kostl_WHILE = 999, Kostl_WHILE_2 = 0, Kostl_BREAK_ = 0, Kostl_END_BODY = 0;
    int result = 0;
    string Stroka_komands_rardelitel;
    string Kostl_IF_2_tt;
    stringstream ss;
    for (int i = 0; i < P_kol_strok; i++)
    {
        ss.str(Tests[i]);
        ss >> Stroka_komands_rardelitel;
        if (P_ERROR == 10)
        {
            if (Stroka_komands_rardelitel == "COUT")
            {
                result = Parser_COUT(Tests[i]);
                if (result == 404)
                {
                    Kostl_IF--;
                }
            }
            else if (Stroka_komands_rardelitel == "ASSIGN")
            {
                result = Parser_ASSIGN(Tests[i]);
                if (result == 404)
                {
                    Kostl_IF--;
                }
            }
            else if (Stroka_komands_rardelitel == "~")
            {
                result = Parser_STROKA(Tests[i]);
                if (result == 404)
                {
                    Kostl_IF--;
                }
            }
            else if (Stroka_komands_rardelitel == "IF")
            {
                Kostl_IF_2 = Kostl_IF++;
                P_ERROR = Parser_IF(Tests[i]);

            }
            else if (Stroka_komands_rardelitel == "WHILE")
            {
                Kostl_BREAK_ = Kostl_IF;
                P_ERROR = Parser_WHILE(Tests[i]);
                if (P_ERROR == 10)
                {
                    Kostl_END_BODY = Kostl_IF;
                    Kostl_WHILE_2 = i;
                    Kostl_IF = Kostl_IF++;
                    Kostl_IF_2 = Kostl_IF++;
                    Kostl_WHILE = 1;

                }
                else
                {
                    Kostl_IF_2 = Kostl_IF;
                    Kostl_IF++;
                    Kostl_WHILE = 0;
                }
            }
            else if (Stroka_komands_rardelitel == "END_BODY" && Kostl_WHILE != 0)
            {
                Kostl_IF = Kostl_END_BODY;
                i = Kostl_WHILE_2;
            }

            else if (Stroka_komands_rardelitel == "BREAK" && Kostl_WHILE != 0)
            {

                Kostl_IF = Kostl_BREAK_;
                Kostl_WHILE = 0;
                P_ERROR = 5;
            }
        }
        else
        {
            stringstream s_2;
            s_2.str(Tests[i]);
            while (s_2 >> Kostl_IF_2_tt)
            {
                if (Kostl_IF_2_tt == "}")
                {
                    Kostl_IF--;
                }
                else if (Kostl_IF_2_tt == "{")
                {
                    Kostl_IF++;
                }

                if (Kostl_IF_2 == Kostl_IF)
                {
                    P_ERROR = 10;
                    Stroka_komands_rardelitel = '\0';
                }
            }
        }

        if (Kostl_WHILE == 1 && Kostl_IF == 0)
        {
            i = Kostl_WHILE_2 - 1;
            P_ERROR = 10;
            Stroka_komands_rardelitel = '\0';
        }

    }
    return "";
}