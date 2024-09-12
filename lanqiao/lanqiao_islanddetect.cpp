#include<bits/stdc++.h>
using namespace std;
double xa, ya, xb, yb, l;
double xap, yap, xbp, ybp;
double x1, yy1, x2, y2, x3, y3;
double accuracy = 0.0002;
double p1, p2, p3, p4;
double area = 0;
int temp;
double tempdou;
double findp(double xap, double yap, double xbp, double ybp, double left, double s){
    double high, low;
    double pivot = (double)(ybp - yap) * left / (xbp - xap) + (double)(xbp * yap - ybp * xap) / (xbp - xap);
    if(s == 1){
        low = pivot;
        high = 1500;
    }
    else{
        low = -1500;
        high = pivot;
    }
    double middle = (low + high) / 2;
    double suml = sqrt((left - xap) * (left - xap) + (middle - yap) * (middle - yap)) + 
                  sqrt((left - xbp) * (left - xbp) + (middle - ybp) * (middle - ybp));
    int count = 0;
    while(fabs(suml - l) > 0.0001){
        if(s == 1){
            if(suml > l){
                high = middle;
                middle = (low + high) / 2;
            }
            else{
                low = middle;
                middle = (low + high) / 2;
            }
        }
        else{
            if(suml > l){
                low = middle;
                middle = (low + high) / 2;
            }
            else{
                high = middle;
                middle = (low + high) / 2;
            }
        }
        suml = sqrt((left - xap) * (left - xap) + (middle - yap) * (middle - yap)) + 
               sqrt((left - xbp) * (left - xbp) + (middle - ybp) * (middle - ybp));
    }
    return middle;
}
int main(){
    scanf("%lf %lf %lf %lf %lf\n%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &l, &x1, &yy1, &x2, &y2, &x3, &y3);
	for(double left = -1000;left <= 1000;left += accuracy){
        //triangle points cal
        if(x1 >= left && x2 >= left && x3 >= left){
            p1 = 0;
            p2 = 0;
        }
        else if(x1 <= left && x2 <= left && x3 <= left){
            p1 = 0;
            p2 = 0;
        }
        else{
            if((x1 > left && x2 > left) || (x1 < left && x2 < left)){
                temp = x1;
                x1 = x3;
                x3 = temp;
                temp = yy1;
                yy1 = y3;
                y3 = temp;
            }
            if((x1 > left && x3 > left) || (x1 < left && x3 < left)){
                temp = x1;
                x1 = x2;
                x2 = temp;
                temp = yy1;
                yy1 = y2;
                y2 = temp;
            }
            p1 = (double)(y3 - yy1) * left / (x3 - x1) + (double)(x3 * yy1 - y3 * x1) / (x3 - x1);
            p2 = (double)(y2 - yy1) * left / (x2 - x1) + (double)(x2 * yy1 - y2 * x1) / (x2 - x1);
            if(p2 > p1){
                tempdou = p2;
                p2 = p1;
                p1 = tempdou;
            }
            
        }
        //flat circle points cal
        if((xa > left && xb > left) || (xa < left && xb < left)){
            xap = 2 * left - xa;
            
        }
        else{
            xap = xa;
        }
        yap = ya;
        xbp = xb;
        ybp = yb;
        double dist = sqrt((xbp - xap) * (xbp - xap) + (ybp - yap) * (ybp - yap));
        if(dist >= l){
            continue;
        }
        p3 = findp(xap, yap, xbp, ybp, left, 1);
        p4 = findp(xap, yap, xbp, ybp, left, 2);
        if(p4 > p3){
            tempdou = p4;
            p4 = p3;
            p3 = tempdou;
        }
        double dl = 0;
        if(p2 >= p3 || p4 >= p1){
            continue;
        }
        else if(p1 >= p3 && p3 >= p2 && p2 >= p4){
            dl = p3 - p2;
        }
        else if(p3 >= p1 && p1 >= p4 && p4 >= p2){
            dl = p1 - p4;
        }
        else if(p1 >= p3 && p3 >= p4 && p4 >= p2){
            dl = p3 - p4;
        }
        else if(p3 >= p1 && p1 >= p2 && p2 >= p4){
            dl = p1 - p2;
        }
        area += dl * accuracy;
    }
    
    printf("%.2lf\n", area);

    return 0;
}