#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int month = 0;
    bool jx = true;
    char months[12][30];
    memset(months,0,sizeof(months)); 
    //cout << sizeof(months) <<endl;

    strcpy(months[0],"January!");strcpy(months[1],"Febrary!");strcpy(months[2],"March!");
    strcpy(months[3],"April!");strcpy(months[4], "May!");strcpy(months[5],"June!");
    strcpy(months[6],"July!");strcpy(months[7],"August!");strcpy(months[8],"September!");
    strcpy(months[9],"October!");strcpy(months[10],"November!");strcpy(months[11],"December!");

    string strMonth[12]={"January!", "Febrary!", "March!", "April!", "May!", "June!",
                          "July!", "August!", "September!", "October!", "November!",
                          "December!"
                         };
    //memset(strMonth,0,sizeof(strMonth));不可用memset
    
    //cout <<sizeof(strMonth) <<endl;
    while(jx)
    {
        cout << "请输入月份:";
        cin >> month;
        //法一
        // cout << "if!" <<endl;
        // if(month == 1) cout << "January!" <<endl;
        // else if(month ==2) cout << "Febrary!" <<endl;
        // else if(month ==3) cout << "March!" <<endl;
        // else if(month ==4) cout << "April!" <<endl;
        // else if(month ==5) cout << "May!" <<endl;
        // else if(month ==6) cout << "June!" <<endl;
        // else if(month ==7) cout << "July!" <<endl;
        // else if(month ==8) cout << "August!" <<endl;
        // else if(month ==9) cout << "September!" <<endl;
        // else if(month ==10) cout << "October!" <<endl;
        // else if(month ==11) cout << "November!" <<endl;
        // else if(month ==12) cout << "December!" <<endl;
        // else cout << "输入的数字不合法!" <<endl;

        //法二
        // cout <<"swith!" <<endl;
        // switch(month)
        // {
        //     case 1:cout << "January!" <<endl;break;
        //     case 2:cout << "Febrary!" <<endl;break;
        //     case 3:cout << "March!" <<endl;break;
        //     case 4:cout << "April!" <<endl;break;
        //     case 5:cout << "May!" <<endl;break;
        //     case 6:cout << "June!" <<endl;break;
        //     case 7:cout << "July!" <<endl;break;
        //     case 8:cout << "August!" <<endl;break;
        //     case 9:cout << "September!" <<endl;break;
        //     case 10:cout << "October!" <<endl;break;
        //     case 11:cout << "November!" <<endl;break;
        //     case 12:cout << "December!" <<endl;break;
        //     default:cout << "输入的数字不合法!" <<endl;
        // }
        
        //法三
        cout << "c风格!" <<endl;
        if (month >=1 && month <=12)
            cout << months[month-1] <<endl;
        else 
            cout << "输入的数字不合法!"<<endl;

        cout <<"c++风格!" <<endl;
        if (month >=1 && month <=12)
            cout << strMonth[month-1] <<endl;
        else 
            cout << "输入的数字不合法!"<<endl;

        cout << "是否继续(1-继续,0-结束):";
        cin >> jx;
    }
}