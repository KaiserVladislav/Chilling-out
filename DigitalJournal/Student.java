package DigitalJournal;

public class Student extends Participant{
    private Parent[] Parents;

    public Student(int CardID, String FullName, int PhoneNumber, Parent[] Parents){
        super(CardID, FullName, PhoneNumber);
        this.Parents=Parents;
    }

}
