#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define red "\x1b[31m"
#define cyan "\x1b[36m"
#define bold "\x1b[1m"
#define black "\x1b[30m"
#define italic "\x1b[3m"
#define magneta "\x1b[35m"
#define resetfont "\x1b[0m"
#define whiteback "\x1b[47m"

void bye(); // BYE BYE 🗣️🗣️ (it's over for you)
void age();
void calendar();
void Conversion();
void bornWeekDay(int);
void AdMonthFinder(int);
void conversiongregorian();
void persianmonthname(int);
void lunarmonthfinder(int);
void gregoriantolunar(int, int, int);
void persianmonthnameconversion(int);

int roundit(double);
int adleapfinder(int);
int persianleapfinder(int);
int weekdayfinder(int, int, int);

int returnornot = 1;

int main()
{
    system("cls");

    printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
    printf("----------------------------\n");

    if (returnornot)
    {
        printf(magneta "welcome to mini calendar" resetfont "\n");
        returnornot = 0;
    }
    else
    {
        printf(magneta "      back to menu !" resetfont "\n");
    }

    printf("----------------------------\n");
    printf(cyan "[0] Quit" resetfont "\n");
    printf(cyan "[1] Calendar" resetfont "\n");
    printf(cyan "[2] Age" resetfont "\n");
    printf(cyan "[3] Conversion" resetfont "\n");
    printf("----------------------------\n");

    int input, input2;

    printf(bold italic "Select an option: " resetfont);

    scanf("%d", &input);

    switch (input)
    {
    case 0:
        bye();
        break;
    case 1:
        calendar();
        break;
    case 2:
        age();
        break;
    case 3:
        system("cls");
        printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
        printf("----------------------------\n");
        printf(cyan "[0] Return to main menu" resetfont "\n");
        printf(cyan "[1] Persian Calendar" resetfont "\n");
        printf(cyan "[2] Gregorian Calendar" resetfont "\n");
        printf("----------------------------\n");
        printf(bold italic "Select an option: " resetfont);
        scanf("%d", &input2);

        if (input2 == 1)
            Conversion();
        else if (input2 == 2)
            conversiongregorian();
        else if (input2 == 0)
            main();
        break;
    default:
        printf("invalid input!\n");
        main();
        break;
    }
    printf("\n");
}

int weekdayfinder(int year, int month, int day)
{
    int i = 1214, iteration = 0;
    if (month == 1)
    {
        day = day - 1;
    }
    else if (month <= 6)
    {
        day = 30 + ((month - 2) * 31) + day;
    }
    else
    {
        day = (6 * 31) + ((month - 8) * 30) + day + 1;
    }

    if (year > 1206)
    {
        if (year > 1210)
        {
            day += 1;
        }
        while (i < year)
        {
            day += 1;
            if (iteration % 7 == 0)
            {
                i += 5;
            }
            else
            {
                i += 4;
            }
            iteration++;
        }

        day += 365 + ((year - 1207) * 365);
    }

    if (year >= 1384 && year <= 1401)
    {
        day++;
    }

    return day;
}

int persianleapfinder(int year)
{
    int pattern[] = {0, 4, 8, 12, 16, 20, 24, 29, 33, 37, 41, 45, 49, 53, 57, 62, 66, 70, 74, 78, 82, 86, 90, 95, 99, 103, 107, 111, 115, 119, 124};
    int mod = year % 128;
    switch (year)
    {
    case 1209:
    case 1242:
    case 1436:
    case 1469:
        mod++;
        break;
    case 1210:
    case 1243:
    case 1437:
    case 1470:
        mod--;
    case 1403:
        return 1;
        break;
    case 1404:
        return 0;
        break;
    default:
        break;
    }
    for (int i = 0; i < 31; i++)
    {
        if ((mod) == pattern[i])
        {
            return 1;
            break;
        }
    }
    return 0;
}

int adleapfinder(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    return 0;
}

int roundit(double value)

{
    if (value < 0)
    {
        return (int)(value - 0.5);
    }
    else
    {
        return (int)(value + 0.5);
    }
}

void age()
{
    int thisYear, thisMonth, thisDay;
    int birthYear, birthMonth, birthDay;
    int ageYear, ageMonth, ageDay;
    int y_ad, m_ad, d_ad;
    int daysInMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int totaldays, oneMoreTime, invaliddate;

    do
    {
        system("cls");

        printf("\n");
        printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
        printf("----------------------------\n");
        printf(cyan "[0] Return to main menu" resetfont "\n");
        printf("----------------------------\n");

        if (invaliddate == 1)
        {
            invaliddate = 0;
            printf("Invalid Input ! try again\n\n");
        }

        printf("which year is it now? : ");
        scanf("%d", &thisYear);
        if (thisYear == 0)
        {
            main();
            break;
        }
        else if (thisYear < 1206 || thisYear > 1498)
        {
            invaliddate = 1;
            age();
            break;
        }

        printf("which month of year is it now? : ");
        scanf("%d", &thisMonth);
        if (thisMonth == 0)
        {
            age();
            break;
        }
        else if (thisMonth > 12 || thisMonth < 1)
        {
            invaliddate = 1;
            age();
            break;
        }

        printf("and which day of month is it today? : ");
        scanf("%d", &thisDay);
        if (thisDay == 0)
        {
            age();
            break;
        }
        else if (thisDay > 31 || thisDay < 1)
        {
            invaliddate = 1;
            age();
            break;
        }

        printf("which year you were born? : ");
        scanf("%d", &birthYear);
        if (birthYear == 0)
        {
            main();
            break;
        }
        else if (birthYear < 1206 || birthYear > 1498)
        {
            invaliddate = 1;
            age();
            break;
        }
        printf("which month you were born? : ");
        scanf("%d", &birthMonth);
        if (birthMonth == 0)
        {
            main();
            break;
        }
        else if (birthMonth > 12 || birthMonth < 1)
        {
            invaliddate = 1;
            age();
            break;
        }
        printf("and which day you were born? : ");
        scanf("%d", &birthDay);
        if (birthDay == 0)
        {
            main();
            break;
        }
        else if (birthDay > 31 || birthDay < 1)
        {
            invaliddate = 1;
            age();
            break;
        }

        ageYear = thisYear - birthYear;
        ageMonth = thisMonth - birthMonth;
        ageDay = thisDay - birthDay;

        if (ageDay < 0)
        {
            ageMonth--;
            ageDay += daysInMonth[thisMonth - 2];
        }

        if (ageMonth < 0)
        {
            ageYear--;
            ageMonth += 12;
        }

        printf("\nyou are " bold cyan "%d year" resetfont, ageYear);
        if (ageYear > 1)
        {
            printf(bold cyan "s" resetfont);
        }

        if (ageMonth != 0)
        {
            printf(" and " bold cyan "%d month" resetfont, ageMonth);
            if (ageMonth > 1)
            {
                printf(bold cyan "s" resetfont);
            }
        }

        if (ageDay != 0)
        {
            printf(" and " bold cyan "%d day" resetfont, ageDay);
            if (ageDay > 1)
            {
                printf(bold cyan "s" resetfont);
            }
        }
        printf(" old.");
        printf("\n");

        totaldays = (ageYear * 365) + (ageMonth * 30) + ageDay;
        for (int i = birthYear; i <= thisYear; i++)
        {
            if (persianleapfinder(i))
            {
                totaldays++;
            }
        }
        if (birthMonth < 7)
        {
            totaldays += (7 - birthMonth);
        }

        printf("Equevelant to " bold cyan "%d day" resetfont, totaldays);
        if (ageDay > 1)
        {
            printf(bold cyan "s" resetfont);
        }
        printf(".");

        printf("\nyou were born on a ");
        bornWeekDay(weekdayfinder(birthYear, birthMonth, birthDay));
        printf(".");

        if (persianleapfinder(birthYear))
        {
            birthDay -= 1;
            if (birthMonth >= 1 && (birthMonth < 10 || (birthMonth == 10 && birthDay <= 11)))
            {
                y_ad = birthYear + 621;
            }
            else
            {
                y_ad = birthYear + 622;
            }
        }
        else
        {
            if (birthMonth >= 1 && (birthMonth < 10 || (birthMonth == 10 && birthDay <= 10)))
            {
                y_ad = birthYear + 621;
            }
            else
            {
                y_ad = birthYear + 622;
            }
        }

        m_ad = birthMonth + 2;
        d_ad = birthDay + 21;

        switch (birthMonth)
        {
        case 5:
        case 6:
        case 7:
        case 8:
            d_ad += 2;
        case 1:
        case 2:
        case 11:
            d_ad--;
            break;
        case 12:
            d_ad -= 2;
            break;
        default:
            break;
        }

        if (m_ad > 12)
        {
            m_ad -= 12;
        }

        switch (m_ad)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while (d_ad > 31)
            {
                d_ad -= 31;
                m_ad++;
            }
            break;
        case 2:
            if (adleapfinder(y_ad))
            {
                while (d_ad > 29)
                {
                    d_ad -= 29;
                    m_ad++;
                }
            }
            else
            {
                while (d_ad > 28)
                {
                    d_ad -= 28;
                    m_ad++;
                }
            }
        default:
            while (d_ad > 30)
            {
                d_ad -= 30;
                m_ad++;
            }
            break;
        }

        printf("\n\nYour birth date in Gregorian calendar: \n");

        printf("\n%d | %d (", y_ad, m_ad);
        AdMonthFinder(m_ad);
        printf(") | %d", d_ad);
        printf("\n");

        printf("\nYour birth date in Islamic calendar: \n\n");

        gregoriantolunar(y_ad, m_ad, d_ad);

        printf("\n----------------------------\n");

        printf(cyan "[1] Wanna try again? " resetfont);
        scanf("%d", &oneMoreTime);

    } while (oneMoreTime == 1);
    main();
}

void bye()
{
    system("cls");
    printf(cyan "(\\(\\\n" resetfont);
    printf(cyan "(-.-)\n" resetfont);
    printf(cyan "o_(\")(\")\n" resetfont);
    printf(cyan "\nPeace!\n" resetfont);
    system("pause");
    exit(0);
}

void calendar()
{
    int year, month, day, numberOfDaysofMonth, kabiseh, justMonth = 0;

    system("cls");

    printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
    printf("----------------------------\n");
    printf(cyan "[0] Return to main menu" resetfont "\n");
    printf("----------------------------\n");
    do
    {
        if (!justMonth)
        {
            printf("Enter the year : ");
            scanf("%d", &year);
            if (!year)
            {
                main();
                break;
            }
            else if (year < 1206 || year > 1498)
            {
                system("cls");
                printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
                printf("----------------------------\n");
                printf(cyan "[0] Return to main menu" resetfont "\n");
                printf("----------------------------\n");
                printf("Invalid Input ! \n");
                continue;
            }
        }

        printf("Enter the month (1-12) : ");
        scanf("%d", &month);

        kabiseh = persianleapfinder(year);

        if (!month)
        {
            main();
            break;
        }

        if (month > 12 || month < 1)
        {
            system("cls");
            printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
            printf("----------------------------\n");
            printf(cyan "[0] Return to main menu" resetfont "\n");
            printf("----------------------------\n");
            printf("Invalid Input\n");
            justMonth = 1;
            continue;
        }
        else if (month <= 6)
        {
            numberOfDaysofMonth = 31;
            justMonth = 0;
        }
        else
        {
            justMonth = 0;
            if (month != 12 || kabiseh)
            {
                numberOfDaysofMonth = 30;
            }
            else
            {
                numberOfDaysofMonth = 29;
            }
        }

        day = weekdayfinder(year, month, 1);

        system("cls");

        printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
        printf("----------------------------\n");
        printf(cyan "[0] Return to main menu" resetfont "\n");
        printf("----------------------------\n");
        persianmonthname(month);
        printf(bold "of %d\n" resetfont, year);
        printf("----------------------------\n");
        printf(whiteback black " Sh  Ye  Do  Se  Ch  Pa  Jo\n" resetfont);

        if (day % 7 >= 2)
        {
            for (int i = 1; i <= (day % 7) - 2; i++)
            {
                printf("    ");
            }
        }
        else
        {
            for (int i = 1; i <= (day % 7) + 5; i++)
            {
                printf("    ");
            }
        }

        for (int i = 1; i <= numberOfDaysofMonth; i++)
        {
            printf(" %02d ", i);
            if ((i + day - 1) % 7 == 1)
            {
                printf("\n");
            }
        }
        printf("\n\n");

    } while (1);
}

void Conversion()
{
    int wanted;

    do
    {
        system("cls");

        printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
        printf("----------------------------\n");
        printf(cyan "[0] Return to main menu" resetfont "\n");
        printf("----------------------------\n");

        int y_shamsi, m_shamsi, d_shamsi, y_ad, m_ad, d_ad, m_miladi, d_miladi;

        printf("Enter the year : ");
        scanf("%d", &y_shamsi);

        if (y_shamsi == 0)
        {
            main();
            break;
        }
        else if (y_shamsi > 1498 || y_shamsi < 1206)
        {
            printf("invalid input\n");
            Conversion();
            break;
        }
        printf("Enter the month : ");
        scanf("%d", &m_shamsi);
        if (m_shamsi == 0)
        {
            main();
            break;
        }
        else if (m_shamsi > 12 || m_shamsi < 1)
        {
            printf("Invalid input\n");
            Conversion();
            break;
        }
        printf("Enter the day : ");
        scanf("%d", &d_shamsi);
        if (d_shamsi == 0)
        {
            main();
            break;
        }
        else if (d_shamsi > 31 || d_shamsi < 0)
        {
            printf("invalid input\n");
            Conversion();
            break;
        }

        if (persianleapfinder(y_shamsi))
        {
            d_shamsi -= 1;
            if (m_shamsi >= 1 && (m_shamsi < 10 || (m_shamsi == 10 && d_shamsi <= 11)))
            {
                y_ad = y_shamsi + 621;
            }
            else
            {
                y_ad = y_shamsi + 622;
            }
        }
        else
        {
            if (m_shamsi >= 1 && (m_shamsi < 10 || (m_shamsi == 10 && d_shamsi <= 10)))
            {
                y_ad = y_shamsi + 621;
            }
            else
            {
                y_ad = y_shamsi + 622;
            }
        }

        m_ad = m_shamsi + 2;
        d_ad = d_shamsi + 21;

        switch (m_shamsi)
        {
        case 5:
        case 6:
        case 7:
        case 8:
            d_ad += 2;
        case 1:
        case 2:
        case 11:
            d_ad--;
            break;
        case 12:
            d_ad -= 2;
            break;
        default:
            break;
        }

        if (m_ad > 12)
        {
            m_ad -= 12;
        }

        switch (m_ad)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while (d_ad > 31)
            {
                d_ad -= 31;
                m_ad++;
            }
            break;
        case 2:
            if (adleapfinder(y_ad))
            {
                while (d_ad > 29)
                {
                    d_ad -= 29;
                    m_ad++;
                }
            }
            else
            {
                while (d_ad > 28)
                {
                    d_ad -= 28;
                    m_ad++;
                }
            }
        default:
            while (d_ad > 30)
            {
                d_ad -= 30;
                m_ad++;
            }
            break;
        }

        printf("\n%d | %d (", y_ad, m_ad);
        AdMonthFinder(m_ad);
        printf(") | %d", d_ad);
        printf("\n");

        gregoriantolunar(y_ad, m_ad, d_ad);

        printf("\n----------------------------\n");

        printf(cyan "[1] Wanna try again? " resetfont);
        scanf("%d", &wanted);

    } while (wanted == 1);
    main();
}

void bornWeekDay(int day)
{
    day %= 7;
    switch (day)
    {
    case 0:
        printf(bold cyan "Thursday" resetfont);
        break;
    case 1:
        printf(bold cyan "Friday" resetfont);
        break;
    case 2:
        printf(bold cyan "saturday" resetfont);
        break;
    case 3:
        printf(bold cyan "Sunday" resetfont);
        break;
    case 4:
        printf(bold cyan "Monday" resetfont);
        break;
    case 5:
        printf(bold cyan "tuesday" resetfont);
        break;
    case 6:
        printf(bold cyan "Wednesday" resetfont);
        break;
    default:
        break;
    }
}

void conversiongregorian()
{
    int wanted;
    do
    {
        system("cls");

        printf(red "mhyr X ebi project ver. 2.1" resetfont "\n");
        printf("----------------------------\n");
        printf(cyan "[0] Return to main menu" resetfont "\n");
        printf("----------------------------\n");
        int thisMonth, thisMonthShamsi, thisYearShamsi, thisDayShamsi, thisYear, thisDay;
        printf("Enter Year : ");
        scanf("%d", &thisYear);
        if (thisYear == 0)
        {
            main();
            break;
        }
        else if (thisYear > 2120 || thisYear < 1827)
        {
            printf("invalid input\n");
            conversiongregorian();
            break;
        }

        printf("Enter Month : ");
        scanf("%d", &thisMonth);
        if (thisMonth == 0)
        {
            main();
            break;
        }
        else if (thisMonth > 12 || thisMonth < 1)
        {
            printf("Invalid input\n");
            conversiongregorian();
            break;
        }

        printf("Enter Day : ");
        scanf("%d", &thisDay);
        if (thisDay == 0)
        {
            main();
            break;
        }
        else if (thisDay > 31 || thisDay < 0)
        {
            printf("invalid input\n");
            Conversion();
            break;
        }

        if (thisMonth > 6 || (thisMonth == 6 && thisDay > 21))
        {
            thisYearShamsi = thisYear - 621;
        }
        else
        {
            thisYearShamsi = thisYear - 622;
        }

        if (thisMonth > 3 || (thisMonth == 3 && thisDay > 21))
        {
            thisMonthShamsi = thisMonth - 3;
        }
        else
        {
            thisMonthShamsi = thisMonth + 9;
        }

        thisDayShamsi = thisDay + 9;

        if (thisMonthShamsi > 12)
        {
            for (thisMonthShamsi; thisMonthShamsi > 12; thisMonthShamsi -= 12)
            {
                thisYearShamsi++;
            }
        }
        if (thisMonthShamsi > 6 && thisDayShamsi > 30)
        {
            while (thisDayShamsi > 30)
            {
                thisDayShamsi -= 30;
                thisMonthShamsi++;
            }
        }
        else if (thisMonthShamsi <= 6 && thisDayShamsi > 31)
        {
            while (thisDayShamsi < 31)
            {
                thisDayShamsi - 31;
                thisMonthShamsi++;
            }
        }
        printf("\n%d | %02d ", thisYearShamsi, thisMonthShamsi);
        persianmonthnameconversion(thisMonthShamsi);
        printf(" | %02d", thisDayShamsi);
        printf("\n");
        gregoriantolunar(thisYear, thisMonth, thisDay);

        printf("\n----------------------------\n");

        printf(cyan "[1] Wanna try again? " resetfont);
        scanf("%d", &wanted);

    } while (wanted == 1);
    main();
}

void AdMonthFinder(int m_ad)
{
    switch (m_ad)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        break;
    }
}

void persianmonthname(int month)
{
    switch (month)
    {
    case 1:
        printf(bold "     Farvardin " resetfont);
        break;
    case 2:
        printf(bold "     Ordibehesht " resetfont);
        break;
    case 3:
        printf(bold "     Khordad " resetfont);
        break;
    case 4:
        printf(bold "     Tir " resetfont);
        break;
    case 5:
        printf(bold "     Mordad " resetfont);
        break;
    case 6:
        printf(bold "     Shahrivar " resetfont);
        break;
    case 7:
        printf(bold "     Mehr " resetfont);
        break;
    case 8:
        printf(bold "     Aban " resetfont);
        break;
    case 9:
        printf(bold "     Azar " resetfont);
        break;
    case 10:
        printf(bold "     Dey " resetfont);
        break;
    case 11:
        printf(bold "     Bahman " resetfont);
        break;
    case 12:
        printf(bold "     Esfand " resetfont);
        break;
    default:
        break;
    }
}

void lunarmonthfinder(int lMonth)
{
    switch (lMonth)
    {
    case 1:
        printf(" (Muharram)");
        break;
    case 2:
        printf(" (Safar)");
        break;
    case 3:
        printf("(Rabi' al-awwal)");
        break;
    case 4:
        printf(" (Rabi' al-thani)");
        break;
    case 5:
        printf(" (Jumadil Awwal)");
    case 6:
        printf(" (Jumadil Tsaniy)");
        break;
    case 7:
        printf(" (Rajab)");
        break;
    case 8:
        printf(" (Sha'ban)");
        break;
    case 9:
        printf(" (Ramadhan)");
        break;
    case 10:
        printf(" (Syawal)");
        break;
    case 11:
        printf(" (Dzulqa'dah)");
        break;
    case 12:
        printf(" (Dzulhijjah)");
        break;
    default:
        break;
    }
}

void gregoriantolunar(int year, int month, int day)
{
    int juliandate;

    if (year > 1582 || (year == 1582 && (month > 10 || (month == 10 && day >= 15))))
    {
        juliandate = roundit((1461 * (year + 4800 + roundit((month - 14) / 12))) / 4) + roundit((367 * (month - 2 - 12 * roundit((month - 14) / 12))) / 12) - roundit((3 * roundit((year + 4900 + roundit((month - 14) / 12)) / 100)) / 4) + day - 32075;
    }
    else
    {
        juliandate = 367 * year - roundit((7 * (year + 5001 + roundit((month - 9) / 7))) / 4) + roundit((275 * month) / 9) + day + 1729777;
    }

    int l = juliandate - 1948440 + 10632;
    int n = roundit((l - 1) / 10631);
    l = l - 10631 * n + 354;

    int j = (roundit((10985 - l) / 5316)) * (roundit((50 * l) / 17719)) + (roundit(l / 5670)) * (roundit((43 * l) / 15238));

    l = l - (roundit((30 - j) / 15)) * (roundit((17719 * j) / 50)) - (roundit(j / 16)) * (roundit((15238 * j) / 43)) + 29;

    int lMonth = roundit((24 * l) / 709);
    int lDay = l - roundit((709 * lMonth) / 24);
    int lYear = 30 * n + j - 30;
    printf("%d | %02d", lYear, lMonth);
    lunarmonthfinder(lMonth);
    printf(" | %d", lDay);
}

void persianmonthnameconversion(int thisMonthShamsi)
{
    switch (thisMonthShamsi)
    {
    case 1:
        printf("(Farvardin)");

        break;
    case 2:
        printf("(Ordibehesht)");
        break;
    case 3:
        printf("(Khordad)");
        break;
    case 4:
        printf("(Tir)");
        break;
    case 5:
        printf("(Mordad)");
        break;
    case 6:
        printf("(Shahrivar)");
        break;
    case 7:
        printf("(Mehr)");
        break;
    case 8:
        printf("(Aban)");
        break;
    case 9:
        printf("(Azar)");
        break;
    case 10:
        printf("(Dey)  ");

        break;
    case 11:
        printf("(Bahman)");

        break;
    case 12:
        printf("(Esfand)");
        break;
    default:
        break;
    }
}

// wanna see something?
//  ⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠛⠋⠉⠈⠉⠉⠉⠉⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⡏⣀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿
//  ⣿⣿⣿⢏⣴⣿⣷⠀⠀⠀⠀⠀⢾⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿
//  ⣿⣿⣟⣾⣿⡟⠁⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣷⢢⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿
//  ⣿⣿⣿⣿⣟⠀⡴⠄⠀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿
//  ⣿⣿⣿⠟⠻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⢴⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⣿⣿⣿
//  ⣿⣁⡀⠀⠀⢰⢠⣦⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⡄⠀⣴⣶⣿⡄⣿⣿
//  ⣿⡋⠀⠀⠀⠎⢸⣿⡆⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⠗⢘⣿⣟⠛⠿⣼⣿
//  ⣿⣿⠋⢀⡌⢰⣿⡿⢿⡀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣧⢀⣼⣿
//  ⣿⣿⣷⢻⠄⠘⠛⠋⠛⠃⠀⠀⠀⠀⠀⢿⣧⠈⠉⠙⠛⠋⠀⠀⠀⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣧⠀⠈⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⠀⠀⠀⠀⢀⢃⠀⠀⢸⣿⣿⣿⣿⣿⣿
//  ⣿⣿⡿⠀⠴⢗⣠⣤⣴⡶⠶⠖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡸⠀⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⡀⢠⣾⣿⠏⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠉⠀⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣧⠈⢹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⡄⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⣦⣄⣀⣀⣀⣀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠙⣿⣿⡟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠁⠀⠀⠹⣿⠃⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢐⣿⣿⣿⣿⣿⣿⣿⣿⣿
//  ⣿⣿⣿⣿⠿⠛⠉⠉⠁⠀⢻⣿⡇⠀⠀⠀⠀⠀⠀⢀⠈⣿⣿⡿⠉⠛⠛⠛⠉⠉
//  ⣿⡿⠋⠁⠀⠀⢀⣀⣠⡴⣸⣿⣇⡄⠀⠀⠀⠀⢀⡿⠄⠙⠛⠀⣀⣠⣤⣤⠄⠀
