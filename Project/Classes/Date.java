package Project.Classes;

public class Date {
    private String Day;
    private String Month;
    private String Year;

    public Date(String date){
        String[] date_array=date.split(".",3);
        this.Day=date_array[0];
        this.Month=date_array[1];
        this.Year=date_array[2];
    }
    public String getDay() {
        return this.Day;
    }
    public String getMonth() {
        return this.Month;
    }
    public String getYear() {
        return this.Year;
    }
    public void setDay(String day) {
        this.Day = day;
    }
    public void setMonth(String month) {
        this.Month = month;
    }
    public void setYear(String year) {
        this.Year = year;
    }
}
