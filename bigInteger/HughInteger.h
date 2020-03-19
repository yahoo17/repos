#include<string>  
#include <vector>
class HughInteger {
private:
    int num[80];
    int length;
public:
    HughInteger(std::string);
    void input(std::string);
    void output();
    HughInteger& add(HughInteger);
    HughInteger& operator+ (const HughInteger& c2);
    HughInteger& subtract(HughInteger);   
    HughInteger& operator- (const HughInteger& c2);
    HughInteger& operator* (const HughInteger& c2);

    bool isEqualTo(HughInteger);
    bool isNotEqualTo(HughInteger);
    bool isGreatThan(HughInteger);
    bool isLessThan(HughInteger);
    bool isGreatThanOrEqualTo(HughInteger);
    bool isLessThanOrRqualTo(HughInteger);
    bool isZero();

};
