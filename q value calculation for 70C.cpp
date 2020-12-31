#include <stdio.h>
#include <math.h>
float Q_Value(float z1, float z2,float z3,float k1, float k2,float k3);
float Q_Value(float z1, float z2,float z3,float k1, float k2,float k3)
{
	float l;
	float q = 0.0;
	float eqn =0.0;
	float h = 1.0;
    while(h > 0.001)
    {
        eqn = (z1/(q + k1*(1-q)))+(z2/(q + k2*(1-q))) +(z3/(q + k3*(1-q)));
        printf("\n  eqn = %f",eqn);
        printf("\n  q = %f",q);
        h = 1 - eqn;
        if (h<0)
        {
		h = h*-1;
		}
        printf("\n  h = %f",h);
		q = q+0.005;
	}
    return q-0.005;
}

int main() {    
float temp = 70;
float a1= 3.9892, a2 = 4.00266, a3 = 4.02832,b1 = 1070.617, b2 = 1171.53, b3 = 1268.636 ,c1 = -40.454, c2 = -48.784 , c3 = -56.199, p = 1.0;
float z[3];
for(int j =0; j<3; j++)
{
	printf( "Enter z value :");
	scanf("\n %f", &z[j]);
}
    	float k1 = 0.986923*(pow(10,(a1 - (b1/(c1+temp+273.15)))));
    	float k2 = 0.986923*(pow(10,(a2 - (b2/(c2+temp+273.15)))));
    	float k3 = 0.986923*(pow(10,(a3 - (b3/(c3+temp+273.15)))));
    	float q = Q_Value(z[0], z[1],z[2],k1,k2,k3);
		printf("\n %f",q);
}
