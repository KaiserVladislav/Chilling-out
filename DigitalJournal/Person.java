package DigitalJournal;

public class Person {
    private String FullName;
    private int PhoneNumber;

    public String getFullName() {
        return FullName;
    }

    public int getPhoneNumber() {
        return PhoneNumber;
    }

    public Person(String FullName, int PhoneNumber){
        this.FullName=FullName;
        this.PhoneNumber=PhoneNumber;
    }
}
