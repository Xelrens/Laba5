#include <iostream>
#include <fstream>
#include "String.h"
#include <string>
using namespace std;

int main()
{
    //Усовершенствовать (или разработать) класс «строка». 
    //Разработать программу переводчик, которая берет исходный файл 
    //и, с помощью файла-словаря, записывает перевод в целевой файл.

    ofstream fout("Translate.txt"); 
    setlocale(LC_ALL, "rus"); 
    ifstream fin1("Text.txt"); 
    ifstream fin2("Dictionary.txt");

   

    
    String word;
    String mbtranslate_word;
    String translate_word;

  
    while (fin1.peek() != '\n')
    {
        fin1 >> word;
        while (fin2.peek() != '\n')
        {
            fin2 >> mbtranslate_word;
            if (word == mbtranslate_word)
            {
                fin2 >> translate_word;
                fout << translate_word << " ";
                break;
            }
            else
            {
                fin2 >> mbtranslate_word;
            }
        }
        fin2.clear();
        fin2.seekg(0);
    }

 
    fin1.close();
    fin2.close();
    fout.close();
}
