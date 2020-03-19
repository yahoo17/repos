class Date {

public:
    int data;
    Date()
    {
    }
    Date(int a) :data(a)
    {

    }
    Date& operator++();
    Date operator++(int);
};