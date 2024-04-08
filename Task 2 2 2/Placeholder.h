#ifndef __PLACEHOLDER__H
#define __PLACEHOLDER__H
class Placeholder{
    public:
        int public_field;

        Placeholder(int);
        void public_change();
        void print();
        void invoke_private_change();
        
    private:
        int private_field;

        void private_change();
};
#endif