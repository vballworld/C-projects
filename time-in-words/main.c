//
//  main.c
//  TimeInWords Revised
//
//  Created by Joe Pak on 8/24/15.
//  Copyright (c) 2015 Joe Pak. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//convert hour & minute values to words
char *hourToWords(int hour, char hourInWords[]);
char *minutesToWords(int minutes, char minutesInWords[]);

//print time in words in proper format
void oClock(char *pHour);
void minutesPast(char *pHour, char *pMin);
void quarterPast(char *pHour);
void halfPast(char *pHour);
void minutesTo(char *pHour, char *pMin);
void quarterTo(char *pHour);


int main()
{
    //store user input hour & minute values into variables
    int hour, minutes;
    scanf("%d %d", &hour, &minutes);
    
    //create & initialize arrays to hold strings for hour & minute values
    char hourInWords[20] = "";
    char minutesInWords[20] = "";
    
    //print x o'clock
    if (minutes == 0)
    {
        char *pHour = hourToWords(hour, hourInWords);
        oClock(pHour);
    }
    
    //print x minutes past y
    else if (((minutes >= 1) && (minutes <= 29)) && (minutes != 15))
    {
        char *pHour = hourToWords(hour, hourInWords);
        char *pMin = minutesToWords(minutes, minutesInWords);
        minutesPast(pHour, pMin);
    }
    
    //print quarter past x
    else if (minutes == 15)
    {
        char *pHour = hourToWords(hour, hourInWords);
        quarterPast(pHour);
    }
    
    //print half past x
    else if (minutes == 30)
    {
        char *pHour = hourToWords(hour, hourInWords);
        halfPast(pHour);
    }
    
    //print quarter to x
    else if (minutes == 45)
    {
        char *pHour = hourToWords(hour == 12 ? 1 : hour + 1, hourInWords);          //account for 12 going into 1
        quarterTo(pHour);
    }
    
    //print x to y
    else if ((minutes >= 31 && minutes <= 45) || (minutes >= 46 && minutes <= 59))  //account for 12 going into 1
    {
        char *pHour = hourToWords(hour == 12 ? 1 : hour + 1, hourInWords);
        char *pMin = minutesToWords(60 - minutes, minutesInWords);
        minutesTo(pHour, pMin);
    }
    else
        printf("");
    
    return 0;
}

char *hourToWords(int hour, char hourInWords[])
{
    switch (hour)
    {
        case 1:
            strcat(hourInWords, "one ");
            break;
        case 2:
            strcat(hourInWords, "two ");
            break;
        case 3:
            strcat(hourInWords, "three ");
            break;
        case 4:
            strcat(hourInWords, "four ");
            break;
        case 5:
            strcat(hourInWords, "five ");
            break;
        case 6:
            strcat(hourInWords, "six ");
            break;
        case 7:
            strcat(hourInWords, "seven ");
            break;
        case 8:
            strcat(hourInWords, "eight ");
            break;
        case 9:
            strcat(hourInWords, "nine ");
            break;
        case 10:
            strcat(hourInWords, "ten ");
            break;
        case 11:
            strcat(hourInWords, "eleven ");
            break;
        case 12:
            strcat(hourInWords, "twelve ");
            break;
        default:
            break;
    }
    
    return hourInWords;
}

char *minutesToWords(int minutes, char minutesInWords[])
{
    if ((minutes >= 10) && (minutes <= 19))
    {
        switch (minutes)
        {
            case 10:
                strcat(minutesInWords, "ten ");
                break;
            case 11:
                strcat(minutesInWords, "eleven ");
                break;
            case 12:
                strcat(minutesInWords, "twelve ");
                break;
            case 13:
                strcat(minutesInWords, "thirteen ");
                break;
            case 14:
                strcat(minutesInWords, "fourteen ");
                break;
            case 15:
                strcat(minutesInWords, "fifteen ");
                break;
            case 16:
                strcat(minutesInWords, "sixteen ");
                break;
            case 17:
                strcat(minutesInWords, "seventeen ");
                break;
            case 18:
                strcat(minutesInWords, "eighteen ");
                break;
            case 19:
                strcat(minutesInWords, "nineteen ");
                break;
            default:
                break;
        }
    }
    
    else
    {
        switch ((minutes / 10) % 10)
        {
            case 2:
                strcat(minutesInWords, "twenty ");
                break;
            case 3:
                strcat(minutesInWords, "thirty ");
                break;
            default:
                break;
        }
        
        switch (minutes % 10)
        {
            case 1:
                strcat(minutesInWords, "one ");
                break;
            case 2:
                strcat(minutesInWords, "two ");
                break;
            case 3:
                strcat(minutesInWords, "three ");
                break;
            case 4:
                strcat(minutesInWords, "four ");
                break;
            case 5:
                strcat(minutesInWords, "five ");
                break;
            case 6:
                strcat(minutesInWords, "six ");
                break;
            case 7:
                strcat(minutesInWords, "seven ");
                break;
            case 8:
                strcat(minutesInWords, "eight ");
                break;
            case 9:
                strcat(minutesInWords, "nine ");
                break;
            default:
                break;
        }
    }
    return minutesInWords;
}

void oClock(char *pHour)
{
    printf("%so' clock\n", pHour);
}

void minutesPast(char *pHour, char *pMin)
{
    printf("%sminute%s past %s\n", pMin, (strcmp(pMin, "one ")) == 0 ? "" : "s", pHour);    //account for plural "s"
}

void quarterPast(char *pHour)
{
    printf("quarter past %s\n", pHour);
}

void halfPast(char *pHour)
{
    printf("half past %s\n", pHour);
}

void minutesTo(char *pHour, char *pMin)
{
    printf("%sminute%s to %s\n", pMin, (strcmp(pMin, "one ")) == 0 ? "" : "s", pHour);      //account for plural "s"
}

void quarterTo(char *pHour)
{
    printf("quarter to %s\n", pHour);
}
