#include<stdio.h>
#include<math.h>
  float f1  (float T1);
 float f1 (float T1)
 {
 	float a = 3.9892;
 	float b = 1070.617;
 	float c = -40.454;
 	float e = (a - (b/(c+T1)));
 	float P = pow(10.0,e);
 	return 0.986923*P;
 }
  float f2 (float T2);
  
   float f3 (float T3);
 float f2 (float T2)
 {
 	float a = 4.00266;
 	float b = 1268.636;
 	float c = -56.199;
 	float e = (a - (b/(c+T2)));
 	float x = pow(10.0,e);
 	return 0.986923*x;
}
 float f3 (float T3)
 {
 	float a = 4.02832;
 	float b = 1171.53;
 	float c = -48.784;
 	float e = (a - (b/(c+T3)));
 	float x = pow(10.0,e);
 	return 0.986923*x;
}
int main()
{

	float z[3];
	for(int j =0; j<3; j++)
	{
		printf( "Enter z value :");
		scanf("\n %f", &z[j]);
	}
	float t = 273.15;
	float p1,p2,p3;
	float val, h=1.0;
	while(h>0.001)
	{
		p1 = f1(t);
		p2 = f2(t);
		p3 = f3(t);
		val = p1*z[0] + p2*z[1] + p3*z[3];
		h = 1 - val;
		t = t+0.001;
	}
	t = t-0.1;
	printf("\n Temp is = %f",t);
}
