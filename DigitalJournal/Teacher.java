package DigitalJournal;

public class Teacher extends Participant{
    private String Position;
    private String Qualification;

    public String getPosition() {
        return Position;
    }

    public String getQualification() {
        return Qualification;
    }

    public Teacher(int CardID, String FullName, int PhoneNumber, String Position, String Qualification){
        super(CardID,FullName,PhoneNumber);
        this.Position=Position;
        this.Qualification=Qualification;
    }

}
