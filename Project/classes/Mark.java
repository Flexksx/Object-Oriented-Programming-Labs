package Project.classes;

public class Mark {

  private float value;
  private String date;
  private boolean modifyPermission = false;
  private boolean absent = false;

  public Mark(float value, String date) {
    this.value = value;
    this.date = date;
  }

  public Mark(String date) {
    this.absent = true;
    this.value = 0;
    this.date = date;
  }

  public String getDate() {
    return this.date;
  }

  public float getValue() {
    return this.value;
  }

  public boolean canBeModified() {
    return this.modifyPermission;
  }

  public boolean isAbsent() {
    return this.absent;
  }

  public void setDate(String date) {
    if (canBeModified()) {
      this.date = date;
    } else {
      System.err.println("This mark's date cannot be modified.");
    }
  }

  public void setValue(float value) {
    if (canBeModified()) {
      this.value = value;
    } else {
      System.err.println("This mark's value cannot be modified");
    }
  }

  public void setAbsence(boolean absent) {
    if (canBeModified()) {
      this.absent = absent;
    } else {
      System.err.println("You cannot put an absence here.");
    }
  }
}
