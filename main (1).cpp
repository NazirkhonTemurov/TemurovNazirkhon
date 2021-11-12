/******************************
* Автор:    Темуров Н.        *
* Дата:     01.11.2021        *
* Название: Работа с файлами  *
* *****************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

  setlocale(LC_ALL, "ru");

  string path = "wine.txt";

  ofstream wineVault;
  wineVault.open(path,ifstream::app);//ofstream::app после удаление данных текст остаётся

  if (!wineVault.is_open()) {
    cout << "Ошибка открытия файла!" << endl;
  } else {
    wineVault << "\n Cреднее стоимость вина в погребе 1500$";
  }

  wineVault.close();

  ifstream vault;
  vault.open(path);

  if (!vault.is_open()) {
    cout << "ошибка окрытия файла" << endl;
  } else {
    cout << "\n Файл открыт!" << endl;
    char ch;
    while (vault.get(ch)) {
      cout << ch;
    }
  }
/*
int n;
int a=2000,b=3000,c=300,d=1500,i=250,f=1770;

fstream vault ("wine.txt");
int a,b,c,d,i,f,sum=0;
int n=0;
while(vault>>x)
{
   sum+=x;
   n++;
}
cout<<sum/n;
*/

  vault.close();

  return 0;
}

