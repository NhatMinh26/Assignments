#include <bits/stdc++.h>
#define eps 0.000001
using namespace std;

double distance(double xa, double ya, double xb, double yb) {
	return sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
}

bool triangle(double xa, double ya, double xb, double yb, double xc, double yc) {
	double d1 = distance(xa,ya,xb,yb);
	double d2 = distance(xa,ya,xc,yc);
	double d3 = distance(xb,yb,xc,yc);
	if (d1+d2-d3 <= eps || d1+d3-d2 <= eps || d2+d3-d1 <= eps) {
		return true;
	} else {
		return false;
	}
}

double tichVoHuong(double xa,double ya,double xb,double yb,double xc, double yc){
	double check = (yb - ya)*(xc - xb)-(yc - yb)*(xb - xa);
	return check;
}
int main() {
    double xa,ya,xb,yb,xc,yc,xd,yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    double m= tichVoHuong(xc,yc,xd,yd,xa,ya);
    double n= tichVoHuong(xc,yc,xd,yd,xb,yb);
    double z= tichVoHuong(xa,ya,xb,yb,xc,yc);
    double t= tichVoHuong(xa,ya,xb,yb,xd,yd);
    if (triangle(xa,ya,xb,yb,xc,yc) || triangle(xa,ya,xb,yb,xd,yd) || triangle(xb,yb,xc,yc,xd,yd) || triangle(xa,ya,xc,yc,xd,yd)){ 
	cout << "yes";
	}
	 else { if (m*n<0 && z*t<0) {
	 	cout << "yes";
	 }
	 	else cout<<"no";
	 }
	 return 0;
}
