#include<stdio.h>



#define dy(t,theta) -g/l*theta0
#define dtheta(t,theta) y0


int main()
{
	float theta0, y0, h, yn, thetan, t, g, l,k1,k2;

	int i, n;
	h = 0.001;
	n = 6/h;
	t = 0;
	
	theta0 = 0.174533;
	y0 = 0;
	g = 9.81;
	l = 0.6;

	for (i = 0; i < n+1; i++)
	{
		k1=h*dy(t,theta0);
        k2=h*dy(t+h,theta0+k1);
        yn = y0 + (k1+k2)/2;
        k1=h*yn;
        k2=h*yn;
        thetan = theta0 + (k1+k2)/2;
        printf("%f, %f \n", t, theta0);
        y0 = yn;
        theta0 = thetan;
        
		
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}
	return 0;
}