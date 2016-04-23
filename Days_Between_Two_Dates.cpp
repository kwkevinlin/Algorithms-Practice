int DaysInMonth(int month, int year);
/*
 * This function is provided, and returns the number of days in a particular month of a year.
 */
int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) {

    //Number of days from day1 to end of the year1
    int Day1ToYearEnd;
    for (int i = 12; i >= month1; i--) { //Days from start of month1 to year end
        Day1ToYearEnd += DaysInMonth(i, year1);
    }
    Day1ToYearEnd -= day1; //Offset back by day1, since the for loop counts from the start of month1
    
    //Number of days from start of year2 to day2
    int year2ToDay2;
    for (int i = 1; i < month2; i++) {
        year2ToDay2 += DaysInMonth(i, year2);
    }
    year2ToDay2 += day2; //Offset for uncounted days in month2
    
    //Number of days in between the two years
    int daysBetweenYears = (year2-year1-1) * 365;
   
    //Return as days in between the two dates, the sum of all three above
    return Day1ToYearEnd + year2ToDay2 + daysBetweenYears;
}