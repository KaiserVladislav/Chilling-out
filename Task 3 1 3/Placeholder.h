#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

class Placeholder{
    public :
        Placeholder();
        Placeholder(int size);  
        ~Placeholder();
        void setup();
        int first();
        int second();
        int sum();

    private:
        int size; // even and >2 
        int array[];

};

#endif