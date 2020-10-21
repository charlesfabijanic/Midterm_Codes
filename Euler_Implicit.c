#include<stdio.h>


#define dy(t,theta) -g/l*theta0*h
#define dtheta(t,theta) h*y0

int main()
{
	float tt, w, theta0, y0, h, yn, thetan, slope_y, slope_theta, t, g, l;
	int i, n;
	h = 0.15;
	t = 0;
	tt = 6;
	n = tt/h;
	theta0 = 0.174533;
	y0 = 0;
	g = 9.81;
	l = 0.6;
	w = g / l;
	for (i = 0; i < n+1; i++)
	{
		printf("%f, %f \n", t, theta0);
		
		yn = (y0-h*w*theta0)/(1+h*h*w);
		thetan = theta0+h*yn;
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}
	printf("This is Euler, Implicit Method");
	return 0;



}