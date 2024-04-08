package DigitalJournal;

public class Employee extends Participant{

    private String Position;

    public String getPosition() {
        return Position;
    }

    public Employee(int CardID, String FullName, int PhoneNumber, String Position){
        super(CardID, FullName, PhoneNumber);
        this.Position = Position;
    }

}
