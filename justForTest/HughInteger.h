#include<string>  
#ifndef HUGHINTEGER_H  
#define HUGHINTEGER_H  
class HughInteger {
private:
    int num[40];
    int length;
public:
    HughInteger(std::string);
    void input(std::string);
    void output();
    void add(HughInteger);
    void subtract(HughInteger);

    bool isEqualTo(HughInteger);
    bool isNotEqualTo(HughInteger);
    bool isGreatThan(HughInteger);
    bool isLessThan(HughInteger);
    bool isGreatThanOrEqualTo(HughInteger);
    bool isLessThanOrRqualTo(HughInteger);
    bool isZero();

};


#endif // !HUGHINTEGER_H  
