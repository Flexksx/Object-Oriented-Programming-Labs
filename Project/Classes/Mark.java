package Project.Classes;

public class Mark {

  private float Value;
  private String Date;
  private boolean ModifyPermission = false;
  private boolean Absent;

  public Mark(float value, String date) {
    this.Value = value;
    this.Date = date;
  }

  public Mark(String date) {
    this.Absent = true;
    this.Value = 0;
    this.Date = date;
  }

  public String getDate() {
    return this.Date;
  }

  public float getValue() {
    return this.Value;
  }

  public boolean canBeModified() {
    return this.ModifyPermission;
  }

  public boolean isAbsent() {
    return this.Absent;
  }

  public void setDate(String date) {
    if (canBeModified()) {
      this.Date = date;
    } else {
      System.err.println("This mark's date cannot be modified.");
    }
  }

  public void setValue(float value) {
    if (canBeModified()) {
      this.Value = value;
    } else {
      System.err.println("This mark's value cannot be modified");
    }
  }

  public void setAbsence(boolean absent) {
    if (canBeModified()) {
      this.Absent = absent;
    } else {
      System.err.println("You cannot put an absence here.");
    }
  }
}
