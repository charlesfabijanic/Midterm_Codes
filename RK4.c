#include<stdio.h>



#define dy(t,theta) -g/l*theta
#define dtheta(t,theta) y0


int main()
{
	float theta0, y0, h, yn, thetan, t, g, l, k1,k2,k3,k4;

	int i, n;
	h = 1;
	t = 0;
	n = 6/h;
	theta0 = 0.174533;
	y0 = 0;
	g = 9.81;
	l = 0.6;

	for (i = 0; i < n+1; i++)
	{
		k1=h*dy(t,theta0);
        k2=h*dy(t+h*0.5,theta0+k1/2);
        k3=h*dy(t+h*0.5,theta0+k2/2);
        k4=h*dy(t+h,theta0+k3);
    
        yn = y0 +(k1+2*k2+2*k3+k4)/6;
    
        k1=h*yn;
        k2=h*yn;
        k3=h*yn;
        k4=h*yn;
    
    
        thetan = theta0 + (k1+2*k2+2*k3+k4)/6;
		printf("%f, %f \n", t, theta0);
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}
	
	return 0;
}