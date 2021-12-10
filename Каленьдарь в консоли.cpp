/***********************************************
 * Автор:    Темуров Н.                        *
 * Дата:     02.12.2021                        *
 * Название: Каледарь в консоли                *
 ***********************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

int monthNumber = 0;
int stepByWeeks = 0;
int dayOnWeek = 1;
int dayOfFirstWeek = 1;
int dayOfSecondWeek = 1;
int dayOfThirdWeek = 1;
int dayOfFourthWeek = 1;

const char * month[] = {
  "Январь",
  "Февраль",
  "Март",
  "Апрель",
  "Май",
  "Июнь",
  "Июль",
  "Август",
  "Сентябрь",
  "Октябрь",
  "Ноябрь",
  "Декабрь"
};

void printSpacesBefore(int weekDay) {
  for (int j = 0; j < weekDay; j++) cout << setw(3) << " ";
}

void printSpacesAfter(int weekDay) {
  weekDay += 1;
  for (int j = 1; j <= 7 - weekDay; j++) {
    cout << setw(3) << " ";
  }
}
void printMonthName(int monthNumber) {
  int Month = monthNumber;
  
  if (monthNumber == 0 || monthNumber == 4 || monthNumber == 8) {
    int space = strlen(month[Month]) / 2;
    
    cout  << setw(23 + space) << month[Month];
    
    Month = Month + 1;
    
    int space1 = strlen(month[Month]) / 2;
    
    cout << " " << setw(23 + space1) << month[Month];
    
    Month = Month + 1;
    
    int space2 = strlen(month[Month]) / 2;
    
    cout << " " << setw(23 + space2) << month[Month];
    
    Month = Month + 1;
    
    int space3 = strlen(month[Month])/2;
    
    cout << " " << setw(23 + space3) << month[Month] << endl;
    
    cout << "_______________________";
    cout << " " << "_______________________";
    cout << " " << "_______________________";
    cout << " " << "_______________________" << endl;
    cout <<        " ВС ПН ВТ СР ЧТ ПТ СБ  ";
    cout << " " << " ВС ПН ВТ СР ЧТ ПТ СБ  ";
    cout << " " << " ВС ПН ВТ СР ЧТ ПТ СБ  ";
    cout << " " << " ВС ПН ВТ СР ЧТ ПТ СБ  " << endl;;
    cout << "_______________________";
    cout << " " << "_______________________";
    cout << " " << "_______________________";
    cout << " " << "_______________________" << endl;
  }
}

int main() {
  setlocale(LC_ALL, "Russian");
  
  time_t now;
  struct tm * timeinfo;
  
  int year;

  cout << "ГОД: ";
  cin >> year;
 
  time( & now);
  timeinfo = localtime( & now);

  timeinfo -> tm_year = year - 1900;
  timeinfo -> tm_mon = 0;

  monthNumber = 0;
  stepByWeeks = 0;
  dayOnWeek = 1;
  dayOfFirstWeek = 1;
  dayOfSecondWeek = 1;
  dayOfThirdWeek = 1;
  dayOfFourthWeek = 1;
  
  bool endOfColumn1 = false, endOfColumn2 = false, endOfColumn3 = false, endOfColumn4=false;
  
  for (int strokeOfMonths = 0; strokeOfMonths < 3; ++strokeOfMonths) {
    printMonthName(monthNumber);

    timeinfo -> tm_mon = monthNumber;
    timeinfo -> tm_mday = 1;
    mktime(timeinfo);
    for (int strokeOfWeeks = 1; strokeOfWeeks <= 6; ++strokeOfWeeks) {
      for (int columnOfMonth = 1; columnOfMonth <= 4; ++columnOfMonth) {

        int today = 0, tomorrow = 0;

        for (int day = dayOnWeek; day <= 31; day++) {
          timeinfo -> tm_mon = monthNumber;
          timeinfo -> tm_mday = day + 1;
          mktime(timeinfo);
          
          tomorrow = timeinfo -> tm_mday;

          timeinfo -> tm_mon = monthNumber;
          timeinfo -> tm_mday = day;
          mktime(timeinfo);
          
          today = timeinfo -> tm_mday;

          if (today == 1) {
            printSpacesBefore(timeinfo -> tm_wday);
          }

          if ((endOfColumn1 == true && columnOfMonth == 1) || 
          (endOfColumn2 == true && columnOfMonth == 2) || 
          (endOfColumn3 == true && columnOfMonth == 3) || 
          (endOfColumn4 == true && columnOfMonth == 4)) {
            cout << setw(3) << " ";
          } else {
            cout << setw(3) << timeinfo -> tm_mday;

          }

          if (today == 28 && tomorrow == 1) {

            printSpacesAfter(timeinfo -> tm_wday);

            if (columnOfMonth == 1) {
              dayOfFirstWeek = 1;
              dayOnWeek = dayOfSecondWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn1 = true;
              
              break;

            } else if (columnOfMonth == 2) {
              dayOfSecondWeek = 1;
              dayOnWeek = dayOfThirdWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn2 = true;
              
              break;
              
            } else if (columnOfMonth == 3) {
              dayOfThirdWeek = 1;
              dayOnWeek = dayOfFourthWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn3 = true;
              
              break;
              
            } else if (columnOfMonth == 4) {
              dayOfFourthWeek = 1;
              dayOnWeek = dayOfFirstWeek;
              monthNumber -= 3;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              endOfColumn4 = true;
              cout << endl;
              
              break;
              
            }
          } else if (today == 29 && tomorrow == 1) {

            printSpacesAfter(timeinfo -> tm_wday);

            if (columnOfMonth == 1) {
              dayOfFirstWeek = 1;
              dayOnWeek = dayOfSecondWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn1 = true;
              
              break;

            } else if (columnOfMonth == 2) {
              dayOfSecondWeek = 1;
              dayOnWeek = dayOfThirdWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn2 = true;
              
              break;
              
            } else if (columnOfMonth == 3) {
              dayOfThirdWeek = 1;
              dayOnWeek = dayOfFourthWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn3 = true;
              
              break;
              
            } else if (columnOfMonth == 4) {
              dayOfFourthWeek = 1;
              dayOnWeek = dayOfFirstWeek;
              monthNumber -= 3;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              endOfColumn4 = true;
              cout << endl;
              
              break;
              
            }
          } else if (today == 30 && tomorrow == 1) {

            printSpacesAfter(timeinfo -> tm_wday);

            if (columnOfMonth == 1) {
              dayOfFirstWeek = 1;
              dayOnWeek = dayOfSecondWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn1 = true;
              
              break;

            } else if (columnOfMonth == 2) {
              dayOfSecondWeek = 1;
              dayOnWeek = dayOfThirdWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn2 = true;
              
              break;
              
            } else if (columnOfMonth == 3) {
              dayOfThirdWeek = 1;
              dayOnWeek = dayOfFourthWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn3 = true;
              
              break;
              
            } else if (columnOfMonth == 4) {
              dayOfFourthWeek = 1;
              dayOnWeek = dayOfFirstWeek;
              monthNumber -= 3;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              endOfColumn4 = true;
              cout << endl;
              
              break;
              
            }
          } else if (today == 31 && tomorrow == 1) {

            printSpacesAfter(timeinfo -> tm_wday);

            if (columnOfMonth == 1) {
              dayOfFirstWeek = 1;
              dayOnWeek = dayOfSecondWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn1 = true;
              
              break;

            } else if (columnOfMonth == 2) {
              dayOfSecondWeek = 1;
              dayOnWeek = dayOfThirdWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn2 = true;
              
              break;
              
            } else if (columnOfMonth == 3) {
              dayOfThirdWeek = 1;
              dayOnWeek = dayOfFourthWeek;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              cout << setw(3) << " ";
              endOfColumn3 = true;
              
              break;
              
            } else if (columnOfMonth == 4) {
              dayOfFourthWeek = 1;
              dayOnWeek = dayOfFirstWeek;
              monthNumber -= 3;
              timeinfo -> tm_mon = monthNumber + 1;
              timeinfo -> tm_mday = dayOnWeek;
              mktime(timeinfo);
              endOfColumn4 = true;
              cout << endl;
              
              break;
              
            }
          }

          if (timeinfo -> tm_wday == 6 && columnOfMonth == 1) {
            dayOfFirstWeek = day + 1;
            dayOnWeek = dayOfSecondWeek;
            timeinfo -> tm_mon = monthNumber + 1;
            timeinfo -> tm_mday = dayOnWeek;
            mktime(timeinfo);

            cout << setw(3) << " ";

            break;

          } else if (timeinfo -> tm_wday == 6 && columnOfMonth == 2) {
            dayOfSecondWeek = day + 1;
            dayOnWeek = dayOfThirdWeek;
            timeinfo -> tm_mon = monthNumber + 1;
            timeinfo -> tm_mday = dayOnWeek;
            mktime(timeinfo);
            cout << setw(3) << " ";
            
            break;

          } else if (timeinfo -> tm_wday == 6 && columnOfMonth == 3) {
            dayOfThirdWeek = day + 1;
            dayOnWeek = dayOfFourthWeek;
            timeinfo -> tm_mon = monthNumber + 1;
            timeinfo -> tm_mday = dayOnWeek;
            mktime(timeinfo);
            cout << setw(3) << " ";
            
            break;

          } else if (timeinfo -> tm_wday == 6 && columnOfMonth == 4) {
            dayOfFourthWeek = day + 1;
            dayOnWeek = dayOfFirstWeek;
            monthNumber -= 4;
            timeinfo -> tm_mon = monthNumber + 1;
            timeinfo -> tm_mday = dayOnWeek;
            mktime(timeinfo);
            cout << endl;
            
            break;

          }

        }
        ++monthNumber;
     
      }

      if (strokeOfWeeks == 6) {
        dayOnWeek = 1;
        dayOfFirstWeek = 1;
        dayOfSecondWeek = 1;
        dayOfThirdWeek = 1;
        dayOfFourthWeek = 1;
        monthNumber += 3;
        endOfColumn1 = false;
        endOfColumn2 = false;
        endOfColumn3 = false;
        endOfColumn4 = false;
        break;
      }
    }

  }

  return 0;
}


