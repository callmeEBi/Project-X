#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bare_aval = 1;
void age();
void kitty();
void calendar();
void Conversion();
int intPart(double);
void bornWeekDay(int);
void conversionMiladi();
void AdMonthFinder(int);
int ADKabisehFinder(int);
void MonthNameShamsi(int);
void MonthNameShamsiForconversion(int);
void gamariMonthFinder(int);
int ShamsiKabisehFinder(int);
void MiladiToLunar(int, int, int);
int chand_shanbe_finder(int, int, int);

int main()
{
    int choice, choiceWhichDate;
    system("cls");
    if (bare_aval)
    {
        printf("\033[35m welcome to mini calendar\033[0m\n");
        bare_aval = 0;
    }
    else
    {
        printf("\033[34m      back to menu !\033[0m\n");
    }
    printf("\033[33m--------------------------\033[0m\n");
    printf("\033[32m[\033[0m");
    printf("\033[31m01\033[0m");
    printf("\033[32m]\033[0m");
    printf(" Calendar       \n");
    printf("\033[32m[\033[0m");
    printf("\033[31m02\033[0m");
    printf("\033[32m]\033[0m");
    printf(" Age   \n");
    printf("\033[32m[\033[0m");
    printf("\033[31m03\033[0m");
    printf("\033[32m]\033[0m");
    printf(" Conversion   \n"); //! gamari and ad to eachother
    printf("\033[32m[\033[0m");
    printf("\033[31m00\033[0m");
    printf("\033[32m]\033[0m");
    printf(" Quit   \n");
    printf("\033[33m--------------------------\033[0m\n");
    printf("\033[3menter your choice : \033[0m");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        kitty();
        break;
    case 1:
        calendar();
        break;
    case 2:
        age();
        break;
    case 3:
        system("cls");
        printf("1. Shamsi\n");
        printf("2. Miladi\n");
        printf("enter your choice : ");
        scanf("%d", &choiceWhichDate);
        if (choiceWhichDate == 1)
            Conversion();
        else if (choiceWhichDate == 2)
            conversionMiladi();
        break;
    default:
        printf("invalid input!\n");
        main();
        break;
    }
    printf("\n");
    system("pause");
    exit(0);
}
//////////////////////////////////////////////پایان تابع اصلی منو
void calendar()
{
    int year, month, day, numberOfDaysofMonth, kabiseh, justMonth = 0;
    system("cls");
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
                printf("Invalid Input ! \n");
                continue;
            }
        }
        printf("Enter the month (1-12) : ");
        scanf("%d", &month);
        kabiseh = ShamsiKabisehFinder(year);
        if (!month)
        {
            main();
            break;
        }
        if (month > 12 || month < 1)
        {
            system("cls");
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
        day = chand_shanbe_finder(year, month, 1);
        system("cls");
        printf("\n ---------------------------\n|");
        MonthNameShamsi(month);
        printf(" ---------------------------\n");
        printf(" sh  ye  do  se  ch  pa  jo\n");
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
////////////////////////////////////////////////////////////////*پایان تابع اصلی تقویم*/
int ShamsiKabisehFinder(int year)
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

int chand_shanbe_finder(int year, int month, int day)
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

    ////////////////////////////////////////////استثنا
    if (year >= 1384 && year <= 1401)
    {
        day++;
    }
    return day;
}

void bornWeekDay(int day)
{
    day %= 7;
    switch (day)
    {
    case 0:
        printf("Thursday");
        break;
    case 1:
        printf("Friday");
        break;
    case 2:
        printf("saturday");
        break;
    case 3:
        printf("Sunday");
        break;
    case 4:
        printf("Monday");
        break;
    case 5:
        printf("tuesday");
        break;
    case 6:
        printf("Wednesday");
        break;
    default:
        break;
    }
}
void MonthNameShamsi(int month)
{
    printf("         ");
    switch (month)
    {
    case 1:
        printf(" Farvardin        |");

        break;
    case 2:
        printf("Ordibehesht        |");
        break;
    case 3:
        printf("  Khordad         |");
        break;
    case 4:
        printf("    Tir           |");
        break;
    case 5:
        printf("  Mordad          |");
        break;
    case 6:
        printf(" Shahrivar        |");
        break;
    case 7:
        printf("   Mehr           |");
        break;
    case 8:
        printf("   Aban           |");
        break;
    case 9:
        printf("   Azar           |");
        break;
    case 10:
        printf("   Dey            |");

        break;
    case 11:
        printf("  Bahman          |");

        break;
    case 12:
        printf("  Esfand          |");
        break;
    default:
        break;
    }
    printf("\n");
}

void age()
{
    srand(time(0));
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    int thisYear = localTime->tm_year + 1900;
    int thisMonth = localTime->tm_mon + 1;
    int thisDay = localTime->tm_mday;
    int birthYear, birthMonth, birthDay, thisYearShamsi, thisMonthShamsi, thisDayShamsi;
    int oneMoreTime, ageYear, ageMonth, ageDay, daysLived, invalidAge;
    int remained = rand() % 20 + 1;
    do
    {
        system("cls");
        if (invalidAge == 1)
        {
            invalidAge = 0;
            printf("Invalid Input ! try again\n\n");
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
            invalidAge = 1;
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
            invalidAge = 1;
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
            invalidAge = 1;
            age();
            break;
        }
        ///////////////////////////تبدیل سال
        if (thisMonth > 6 || (thisMonth == 6 && thisDay > 21))
        {
            thisYearShamsi = thisYear - 621; // اختلاف شمسی و میلادی
        }
        else
        {
            thisYearShamsi = thisYear - 622; // اختلاف شمسی و میلادی
        }
        //! ///////////////////////////تبدیل ماه
        if (thisMonth > 3 || (thisMonth == 3 && thisDay > 21))
        {
            thisMonthShamsi = thisMonth - 3;
        }
        else
        {
            thisMonthShamsi = thisMonth + 9;
        }
        //////////////////////////تبدیل روز
        thisDayShamsi = thisDay + 9;
        //////////////////////برای اینکه ماه و روز رو بیشتر از حد نیاره
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
        if ((birthYear > thisYearShamsi) || (birthYear == thisYearShamsi && birthMonth > thisMonthShamsi) || (birthYear == thisYearShamsi && birthMonth == thisMonthShamsi && birthDay > thisDayShamsi))
        {
            invalidAge = 1;
            age();
            break;
        }
        else if (birthMonth > thisMonthShamsi)
        {
            thisYearShamsi--;
            thisMonthShamsi += 12;
        }
        else if (birthDay > thisDayShamsi)
        {
            if (thisMonthShamsi > 6)
            {
                thisMonthShamsi--;
                thisDayShamsi += 30;
            }
            else
            {
                thisMonthShamsi--;
                thisDayShamsi += 31;
            }
        }

        ageYear = thisYearShamsi - birthYear;
        ageMonth = thisMonthShamsi - birthMonth;
        ageDay = thisDayShamsi - birthDay;
        ///////////////////////////////////////////محاسبه تعداد روزهای زندگی کرده
        daysLived = (ageYear * 365) + (ageMonth * 30) + ageDay;
        for (int i = birthYear; i <= thisYearShamsi; i++)
        {
            if (ShamsiKabisehFinder(i))
            {
                daysLived++;
            }
        }
        if (birthMonth < 7)
        {
            daysLived += (7 - birthMonth);
        }
        //////////////////////////////////////////پرینت نتیجه غایی
        printf("\n------------------------------------------\n");
        printf("you are %d year", ageYear);
        if (ageYear > 1)
        {
            printf("s");
        }
        printf(", %d month", ageMonth);
        if (ageMonth > 1)
        {
            printf("s");
        }
        printf(" and %d day", ageDay);
        if (ageDay > 1)
        {
            printf("s");
        }
        printf(" old");
        printf("\n");
        printf("you lived %d days\n", daysLived);
        printf("you were born on a ");
        bornWeekDay(chand_shanbe_finder(birthYear, birthMonth, birthDay));
        printf("\n");
        printf("you have %d years left, time is running...", remained);
        printf("\n------------------------------------------\n\n");
        printf("want to try again? press 1, if not, press 0 : ");
        scanf("%d", &oneMoreTime);
    } while (oneMoreTime == 1);
    ;
    main();
}

int ADKabisehFinder(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    return 0;
}

void kitty()
{
    system("cls");
    srand(time(0));
    int a = rand() % 4;
    if (a == 0)
    {
        printf("\033[35m  /\\_/\\\033[0m\n");
        printf("\033[35m ( o.o )\033[0m");
        printf("\033[3m go back soon\033[0m");
        printf(" :(\n");
        printf("\033[35m  > ^ < \033[0m\n");
        printf("\n");
    }
    else if (a == 1)
    {
        printf("\033[34m  /\\_/\\\033[0m\n");
        printf("\033[34m ( o.o )\033[0m");
        printf("\033[3m miss you\033[0m");
        printf(" :(\n");
        printf("\033[34m  > ^ < \033[0m\n");
        printf("\n");
    }
    else if (a == 2)
    {
        printf("\033[33m  /\\_/\\\033[0m\n");
        printf("\033[33m ( o.o )\033[0m");
        printf("\033[3m bye\033[0m");
        printf(" :(\n");
        printf("\033[33m  > ^ < \033[0m\n");
        printf("\n");
    }
    else if (a == 3)
    {
        printf("\033[32m  /\\_/\\\033[0m\n");
        printf("\033[32m ( o.o )\033[0m");
        printf("\033[3m run again please\033[0m");
        printf(" :(\n");
        printf("\033[32m  > ^ < \033[0m\n");
        printf("\n");
    }
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
void gamariMonthFinder(int lMonth)
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
        printf(" (Sya'ban)");
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
int intPart(double value)
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
void MiladiToLunar(int year, int month, int day)
{
    int juliandate;

    if (year > 1582 || (year == 1582 && (month > 10 || (month == 10 && day >= 15))))
    {
        juliandate = intPart((1461 * (year + 4800 + intPart((month - 14) / 12))) / 4) + intPart((367 * (month - 2 - 12 * intPart((month - 14) / 12))) / 12) - intPart((3 * intPart((year + 4900 + intPart((month - 14) / 12)) / 100)) / 4) + day - 32075;
    }
    else
    {
        juliandate = 367 * year - intPart((7 * (year + 5001 + intPart((month - 9) / 7))) / 4) + intPart((275 * month) / 9) + day + 1729777;
    }

    int l = juliandate - 1948440 + 10632;
    int n = intPart((l - 1) / 10631);
    l = l - 10631 * n + 354;

    int j = (intPart((10985 - l) / 5316)) * (intPart((50 * l) / 17719)) + (intPart(l / 5670)) * (intPart((43 * l) / 15238));

    l = l - (intPart((30 - j) / 15)) * (intPart((17719 * j) / 50)) - (intPart(j / 16)) * (intPart((15238 * j) / 43)) + 29;

    int lMonth = intPart((24 * l) / 709);
    int lDay = l - intPart((709 * lMonth) / 24);
    int lYear = 30 * n + j - 30;
    printf("%d / %02d", lYear, lMonth);
    gamariMonthFinder(lMonth);
    printf(" / %d", lDay);
}
void Conversion()
{
    int wanted;
    do
    {
        system("cls");
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
        //////////////////////////////////////////////////////////////////////!/*شمسی به میلادی*/
        if (ShamsiKabisehFinder(y_shamsi))
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
            if (ADKabisehFinder(y_ad))
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
        printf("\n%d / %d (", y_ad, m_ad);
        AdMonthFinder(m_ad);
        printf(") / %d", d_ad);
        printf("\n");
        MiladiToLunar(y_ad, m_ad, d_ad);
        printf("\n\n");
        printf("want to try again? press 1, if else press 0 : ");
        scanf("%d", &wanted);
    } while (wanted == 1);
    main();
}

void conversionMiladi()
{
    system("cls");
    int wanted;
    do
    {
        int thisMonth, thisMonthShamsi, thisYearShamsi, thisDayShamsi, thisYear, thisDay;
        printf("Enter Year : ");
        scanf("%d", &thisYear);
        if (thisYear == 0)
        {
            main();
            break;
        }
        printf("Enter Month : ");
        scanf("%d", &thisMonth);
        if (thisMonth == 0)
        {
            main();
            break;
        }
        printf("Enter Day : ");
        scanf("%d", &thisDay);
        if (thisDay == 0)
        {
            main();
            break;
        }
        if (thisMonth > 6 || (thisMonth == 6 && thisDay > 21))
        {
            thisYearShamsi = thisYear - 621; // اختلاف شمسی و میلادی
        }
        else
        {
            thisYearShamsi = thisYear - 622; // اختلاف شمسی و میلادی
        }
        //! ///////////////////////////تبدیل ماه
        if (thisMonth > 3 || (thisMonth == 3 && thisDay > 21))
        {
            thisMonthShamsi = thisMonth - 3;
        }
        else
        {
            thisMonthShamsi = thisMonth + 9;
        }
        //////////////////////////تبدیل روز
        thisDayShamsi = thisDay + 9;
        //////////////////////برای اینکه ماه و روز رو بیشتر از حد نیاره
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
        printf("\n%d / %02d ", thisYearShamsi, thisMonthShamsi);
        MonthNameShamsiForconversion(thisMonthShamsi);
        printf(" / %02d", thisDayShamsi);
        printf("\n");
        MiladiToLunar(thisYear, thisMonth, thisDay);
        printf("\n");
        printf("\nDo You want to enter again? press 1, if else, press 0 : ");
        scanf("%d", &wanted);
    } while (wanted == 1);
    main();
}

void MonthNameShamsiForconversion(int thisMonthShamsi)
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