// mixtypes.cc -- some type combinations
#include <iostream>
using namespace std;

struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc. */
};

int main(void)
{
    antarctica_years_end s01, s02, s03;
    s01.year = 1998; // 由于s01为变量而非指针，因此使用点运算符获取其属性
    antarctica_years_end *pa = &s02; // pa为指针，获取到了来自s02的地址
    pa->year = 1999; // 因此属性访问用箭头运算符
    antarctica_years_end trio[3]; // array of 3 structures
    trio[0].year = 2003;
    cout << trio->year << endl;
    const antarctica_years_end *arp[3] = {&s01, &s02, &s03};
    cout << arp[1]->year << endl;
    const antarctica_years_end **ppa = arp;
    auto ppb = arp; // C++11 automatic type deduction
    // or else use const antarctica_years_end ** ppb = arp;
    cout << (*ppa)->year << endl;
    cout << (*(ppb + 1))->year << endl;
    return 0;
}