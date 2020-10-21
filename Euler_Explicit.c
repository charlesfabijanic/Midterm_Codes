#include<stdio.h>


#define dy(t,theta) -g/l*theta0
#define dtheta(t,theta) y0

int main()
{
	float theta0, y0, h, yn, thetan, slope_y, slope_theta, t, g, l;

	int i, n;
	h = 0.5;
	t = 0;
	n =6/h ;
	theta0 = 0.174533;
	y0 = 0;
	g = 9.81;
	l = 0.6;
	for (i = 0; i < n+1; i++)
	{
		slope_y = dy(t, theta);
		
		slope_theta = dtheta(t, yn);
		yn = y0 + h*slope_y;
		thetan = theta0 + h*yn;
		printf("%f, %f \n", t, theta0);
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}

	return 0;



}