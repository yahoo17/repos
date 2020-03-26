// 四边形,梯形,平行四边形,矩形,正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Quadrilateral.h"

int main()
{
   
        Quadrilateral a;
        cin >> a;
        cout << fixed << setprecision(2) << a.getPerimeter();
        cout << ' ';
        cout << a.getArea2() << endl;

        Trapezoid tr(a);
        if (tr.check()) cout << "YES\n";
        else cout << "NO\n";

        //套娃警告
        Parallelogram par(a);
        if (par.check())
        {
            Rectangle rec(par);
            if (rec.check())
            {
                Square sq(rec);
                if (sq.check()) cout << "square";
                else cout << "rectangle";
            }
            else cout << "parallelogram";
        }
        else cout << "NO";
   
}


