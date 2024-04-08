package DigitalJournal;

public class Participant extends Person {
    private int CardID;

    public int getCardID() {
        return CardID;
    }

    public Participant(int CardID, String Fullname, int PhoneNumber){
        super(Fullname,PhoneNumber);
        this.CardID=CardID;
    }
}
