/********************************
*Автор:  Темуров Назирхон       *
*дата:    12.11.21              *
*Название:Частота повторений    *
********************************/
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <vector>

using namespace std;

//Структура для однобуквенных
struct withOneLetterValue {
  char letterName;
  int intLetter;
};
vector < withOneLetterValue > arrayWithOneLetter;

//Структура для двухбуквенных
struct withTwoLetterValue {
  string letterName;
  int intLetter;
};

vector < withTwoLetterValue > arrayWithTwoLetter;

// Преобразование прописных букв в строчные
string toLowerText(string text) {
  char character;
  int letter = 0;

  ofstream createProcessingFile("toLowerText.txt");

  while (text[letter]) { // пока не конец строки
    character = text[letter];
    createProcessingFile << (char) tolower(character); // преоброзование прописных букв в строчные
    ++letter; // инкремент индекса символов в строке
  }

  createProcessingFile.close();

  ifstream openProcessingFile("toLowerText.txt");
  string processingText;
  getline(openProcessingFile, processingText);
  
  openProcessingFile.close();

  return processingText;

}

// подсчитываем количество символов в тексте, без пробелов
int iTextLength(string str) {
  const char * stringArray = str.c_str();
  int strLength = strlen(stringArray);
  int spaces = 0;
  for (int arrayIndex = 0; stringArray[arrayIndex]; ++arrayIndex) {
    if (stringArray[arrayIndex] == ' ') { 
      ++spaces;
    }
  }

  int character = strLength - spaces;
  return character;
}

//обработка однобуквенных значение
void VSingleLetter(const char * convertToChar, int textSize) {

  for (int oneLetterindex = 0; oneLetterindex < arrayWithOneLetter.size(); ++oneLetterindex) {
    arrayWithOneLetter[oneLetterindex].intLetter = 0;
  };

  for (int charIndex = 0; convertToChar[charIndex]; ++charIndex) {
    if (convertToChar[charIndex] != ' ') {
      char one = convertToChar[charIndex];
      arrayWithOneLetter.push_back(withOneLetterValue());

      for (int indexOfOneLetterArr = 0; indexOfOneLetterArr < arrayWithOneLetter.size(); ++indexOfOneLetterArr) {
        if (arrayWithOneLetter[indexOfOneLetterArr].intLetter > 0) {
          if (arrayWithOneLetter[indexOfOneLetterArr].letterName == one) {
            int countLetterCopy = arrayWithOneLetter[indexOfOneLetterArr].intLetter;
            arrayWithOneLetter[indexOfOneLetterArr].intLetter = countLetterCopy + 1;
            break;
          }
        } else if (arrayWithOneLetter[indexOfOneLetterArr].intLetter == 0) {
          arrayWithOneLetter[indexOfOneLetterArr].letterName = one;
          arrayWithOneLetter[indexOfOneLetterArr].intLetter = 1;
          break;
        }
      }
    }
  }

}

//обработка двухбуквенных значение
void VTwoLetter(const char * convertToChar, int textSize) {

  for (int charIndex = 0; convertToChar[charIndex]; ++charIndex) {
    if (convertToChar[charIndex] != ' ' && convertToChar[charIndex + 1] != ' ') {
      char two[2] = {
        convertToChar[charIndex],
        convertToChar[charIndex + 1]
      };

      arrayWithTwoLetter.push_back(withTwoLetterValue());

      for (int indexOfTwoLetterArr = 1; indexOfTwoLetterArr < arrayWithTwoLetter.size(); ++indexOfTwoLetterArr) {
        if (arrayWithTwoLetter[indexOfTwoLetterArr].letterName != "" && arrayWithTwoLetter[indexOfTwoLetterArr].intLetter > 0) {
          if (arrayWithTwoLetter[indexOfTwoLetterArr].letterName == string(two)) {
            int countLetterCopy = arrayWithTwoLetter[indexOfTwoLetterArr].intLetter;
            arrayWithTwoLetter[indexOfTwoLetterArr].intLetter = countLetterCopy + 1;
            break;
          }
        } else if (arrayWithTwoLetter[indexOfTwoLetterArr].letterName == "" && arrayWithTwoLetter[indexOfTwoLetterArr].intLetter == 0) {
          int countLetterCopy = arrayWithTwoLetter[indexOfTwoLetterArr].intLetter;
          arrayWithTwoLetter[indexOfTwoLetterArr].letterName = string(two);
          arrayWithTwoLetter[indexOfTwoLetterArr].intLetter = countLetterCopy + 1;
          break;
        }
      }
    }
  }
}

// вывод частота повторения однобуквенного значения
void printSingleLetter() {
  cout << "Частота повторения однобуквенного значения: " << endl;

  for (int oneLetterindex = 0; oneLetterindex < arrayWithOneLetter.size(); ++oneLetterindex) {
    if (arrayWithOneLetter[oneLetterindex].intLetter != 0 && arrayWithOneLetter[oneLetterindex].intLetter > 1) {
      cout << "\"" << arrayWithOneLetter[oneLetterindex].letterName << "\"" << " = " << arrayWithOneLetter[oneLetterindex].intLetter << "; ";
    }
  }
}

//выыод частоту повторение двухбуквенных значение
void printTwoLetter() {
  cout << endl << "Частоту повторение двухбуквенных значение: " << endl;
  for (int twoLetterIndex = 0; twoLetterIndex < arrayWithTwoLetter.size(); ++twoLetterIndex) {
    if (arrayWithTwoLetter[twoLetterIndex].letterName != "" && arrayWithTwoLetter[twoLetterIndex].intLetter > 1) {
      cout << "\"" << arrayWithTwoLetter[twoLetterIndex].letterName << "\"" << " = " << arrayWithTwoLetter[twoLetterIndex].intLetter << "; ";
    }
  }
}

int main() {

  setlocale(LC_ALL, "rus");

  ofstream InformationFile("information.txt");
  InformationFile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit&*99r8343989998989834837AAjjd";
  InformationFile.close();

  ifstream OpenInformationFile("information.txt");
  string str;
  getline(OpenInformationFile, str);
  cout << str << endl << endl;

  string text = toLowerText(str); // Преобразование прописных букв в строчные
  const char * convertToChar = text.c_str();

  VSingleLetter(convertToChar, iTextLength(str)); //обработка однобуквенных значение
  VTwoLetter(convertToChar, iTextLength(str) * 2); //обработка двухбуквенных значение
  printSingleLetter(); // вывод частота повторения однобуквенного значения
  printTwoLetter(); //выыод частоту повторение двухбуквенных значение

  OpenInformationFile.close();
  // 	system("pause");
  return 0;
}