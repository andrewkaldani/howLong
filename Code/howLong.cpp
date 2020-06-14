#include <iostream>
#include <string>
#include<cmath>
#include <ctime>
using namespace std;
bool is_leap_year(int year){
  if(year%4==0&&year%100==0&&year%400==0){
        return true;
  }
  else if(year%4!=0){
    return false;
  }
  else if(year%4==0&&year%100==0&&year%400!=0){
    return false;
  }
  return true;
}

void howLong(int bmonth, int bday, int byear){
  time_t t = time(NULL);
  tm* tPtr = localtime(&t);
  int currAge, dage , fyear, dyear;
  int fday, fmonth;
  
if(bmonth>12){
    cout<<"ENTER VALID MONTH"<<endl;
    exit(0);
}
if(bday>31){
    cout<<"ENTER VALID DAY"<<endl;
    exit(0);
}
if(bmonth==2&&bday>=28){
    if(!(is_leap_year(byear))){
        cout<<"Enter valid day!"<<endl;
       exit(0);
    }
}
if(bmonth ==4||bmonth == 6 || bmonth == 9 || bmonth ==11 ){
    if(bday > 30){
        cout<<"Enter valid date!"<<endl;
        exit(0);
    }
}

  cout<<"What is your current age? "<<endl;
  cin>>currAge;
  cout<<"How long till I turn...?"<<endl;
  cin>>dage;
  fyear = dage - currAge;
  dyear = byear + dage;
  dyear-=(tPtr->tm_year)+1900;
  if((tPtr->tm_mon)+1 < bmonth){
    if((tPtr->tm_mday) < bday){
        dyear+=1;
    }
  }

if((tPtr->tm_mon)+1 == bmonth){
    if((tPtr->tm_mday) == bday){
        cout<<"you will turn "<<dage<<" in "<<fyear<<" years."<<endl;
    }
    else if((tPtr->tm_mday) < bday){
        //fyear+=1-1;
        fday = bday - (tPtr->tm_mday);
        if(dyear == 0){
            fyear = 0;
        }
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fday<<" days."<<endl;
    }
    else if((tPtr->tm_mday) > bday){
       // fyear-=1;
       dyear-=1;
        fmonth = 11;
        fday = 31-(tPtr->tm_mday);
        fday += bday;
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;
    }
}
else if((tPtr->tm_mon)+1 < bmonth){
    fmonth = bmonth - ((tPtr->tm_mon)+1);
     if((tPtr->tm_mday) == bday){
         fday =0;
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;
    }
    if((tPtr->tm_mday) < bday){
        fday  = bday - (tPtr->tm_mday);
        dyear-=1;
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;

    }
    if((tPtr->tm_mday) > bday){
        fday = 31 - (tPtr->tm_mday);
        fday+=bday;
        fmonth--;
        if(bmonth==5||bmonth==7||bmonth==10||bmonth==12){
            fday = fday-1;
         }
         cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;

    } 
}
else if((tPtr->tm_mon)+1 > bmonth){
    fmonth = 12- ((tPtr->tm_mon)+1);
    fmonth += bmonth;
    dyear--;
     if((tPtr->tm_mday) == bday){
         fday =0;
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;
    }
      if((tPtr->tm_mday) < bday){
        fday  = bday - (tPtr->tm_mday);
        //dyear-=1;
        cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;

    }
     if((tPtr->tm_mday) > bday){
        fday = 31 - (tPtr->tm_mday);
        fday+=bday;
        fmonth--;
        if(bmonth == 3){
            fday-=3;
        }
        if(bmonth==5||bmonth==7||bmonth==10||bmonth==12){
            fday = fday-1;
         }
         cout<<"you will turn "<<dage<<" in "<<dyear<<" years "<<fmonth<<" months, "<<fday<<" days."<<endl;

    } 

}




}


int main(){
howLong(2,7,1996);

}
