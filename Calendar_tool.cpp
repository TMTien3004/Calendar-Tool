#include <stdio.h>

bool namNhuan(int y)
{
    bool leap_year;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        leap_year = true;
    return false;
}

int nthDay(int d, int m, int y)
{
    int nth_day;
    switch (m)
    {
    case 1:
        nth_day = 0 + d;
        break;
    case 2:
        nth_day = 31 + d;
        break;
    case 3:
        nth_day = 59 + d;
        break;
    case 4:
        nth_day = 90 + d;
        break;
    case 5:
        nth_day = 120 + d;
        break;
    case 6:
        nth_day = 151 + d;
        break;
    case 7:
        nth_day = 181 + d;
        break;
    case 8:
        nth_day = 212 + d;
        break;
    case 9:
        nth_day = 243 + d;
        break;
    case 10:
        nth_day = 273 + d;
        break;
    case 11:
        nth_day = 304 + d;
        break;
    case 12:
        nth_day = 334 + d;
        break;
    }
    if (namNhuan(y) && m > 2)
        nth_day += 1;
    return nth_day;
}

void addDate(int d, int m, int y)
{
    int day, month, year;
    int added_date;

    printf("Nhap ngay, thang, nam\n");
    scanf("%d %d %d", &day, &month, &year);
    printf("Nhap so ngay muon cong them:\n");
    scanf("%d", &added_date);

    int sum = nthDay(day, month, year) + added_date;

    for (int i = year;; i++)
    { //tinh nam
        if (namNhuan(i))
        {
            if (sum <= 366)
                break;
            else
            {
                sum -= 366;
                year += 1;
            }
        }
        else
        {
            if (sum <= 365)
                break;
            else
            {
                sum -= 365;
                year += 1;
            }
        }
    }

    for (int i = 1;; i++)
    {
        if ((sum - nthDay(0, i, year)) < 0)
        {
            month = i - 1;
            day = sum - nthDay(0, i - 1, year);
            break;
        }
    }
    printf("Ngay, thang, nam moi la: %d/%d/%d\n", day, month, year);
}

int main()
{
    int day, month, year, nth_day;
    int added_date, leap_year, day_in_month;

    //Kiem tra xem so ngay trong thang co hop le khong, neu co in ra so ngay trong thang
    if ((day < 1 || day > day_in_month) || (month < 1 || month > 12) || year < 0)
        printf("Ngay thang nam khong hop le\n");

    //Set so ngay trong thang
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        day_in_month = 31;
        break;
    case 2:
        if (namNhuan(year))
            day_in_month = 29;
        else
            day_in_month = 28;
        break;
    default:
        day_in_month = 30;
        break;
    }

    //Input
    addDate(day, month, year);

    return 0;
}

//Vẫn còn lỗi tính dư 1 ngày: coi lại hàm nthDay