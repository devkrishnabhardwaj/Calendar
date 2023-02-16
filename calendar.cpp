#include<bits/stdc++.h>
using namespace std;
bool leapCheck(int year){
    if((year%400==0)||(year%4==0&&year%100!=0)){
        return true;
    }
    return false;
}
void sheet(int day,int month,int year){
    string w_day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    string monthName[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER"
    ,"OCTOBER","NOVEMBER","DECEMBER"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int odds[]={0,3,3,6,1,4,6,2,5,0,3,5};
    if(leapCheck(year)){
        monthDays[1]=29;
        int oddsLeap[]={0,3,4,0,2,5,7,3,6,1,4,6};
        day =(day + oddsLeap[month]+1)%7;
    }
    else{
        day = (day+odds[month]+1)%7;
    }
    int week=0;
    cout<<"\n"<<"\t\t"<<monthName[month]<<" "<<year<<"\n\n";
    for(int i=0;i<7;i++){
        cout<<w_day[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<day;i++){
        cout<<"     ";
        week++;
    }
    for(int i=1;i<=monthDays[month];i++){
        printf(" %2d  ",i);
        week++;
        if(week%7==0){
            cout<<endl;
        }
    }
    cout<<endl;
}
int oddDays(int year){
    year--;
    int dec,cen;
    dec = year%100;
    cen = year/100;
    cen = cen%4;
    switch(cen){
        case 0: cen=0; break;
        case 1: cen=5; break;
        case 2: cen=3; break;
        case 3: cen=1; break;
    }    
    dec = (dec) + (dec)/4;
    return ((cen+dec)%7);
}
int main(){
    int y,m;
    cout<<"Enter Year : ";
    AGAIN:
    cin>>y;
    if(y<1||y>10000){
        cout<<"INVALID YEAR\n";
        cout<<"Enter Year Again :";
        goto AGAIN;
    }
    int o=oddDays(y);
    for(int i=0;i<12;i++){
        sheet(o,i,y);
    }
    return 0;
}