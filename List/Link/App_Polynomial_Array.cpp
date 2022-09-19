#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

#define MaxDegree 10

using namespace std;


typedef struct
{
    int CoeffArray[MaxDegree+1];
    int HighPower;
}* Polynomial;

void ZerePolynomial(Polynomial Poly)
{
    for(int i=0;i<MaxDegree+1;i++)
        Poly->CoeffArray[i]=0;

    Poly->HighPower=0;
}

void AddPolynomial( const Polynomial Poly1,
                    const Polynomial Poly2, Polynomial PolySum)
{
    ZerePolynomial(PolySum);
    PolySum->HighPower=max(Poly1->HighPower,Poly2->HighPower);

    for (int i = 0; i < PolySum->HighPower + 1; i++)
    {
        PolySum->CoeffArray[i]=Poly1->CoeffArray[i]
                            +Poly2->CoeffArray[i];
    }
}

void MultPolynomial( const Polynomial Poly1,
                     const Polynomial Poly2, Polynomial PolyProd)
{
    ZerePolynomial(PolyProd);
    PolyProd->HighPower=Poly1->HighPower+Poly2->HighPower;

    if(PolyProd->HighPower>MaxDegree)
        throw "Excceed array size";
    
    else
    {
        for(int i=0;i<=Poly1->HighPower;i++)
        {
            for(int j=0;j<=Poly2->HighPower;j++)
                PolyProd->CoeffArray[i+j]+=Poly1->CoeffArray[i]
                                         *Poly2->CoeffArray[j];
        }
    }
}








