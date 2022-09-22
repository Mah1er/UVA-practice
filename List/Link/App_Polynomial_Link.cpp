#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct Node
{
    int Coefficient;
    int Exponent;
    struct Node* Next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
    Polynomial P=Poly->Next;
    
    while (P!=NULL)
    {
        P->Coefficient=0;
        P=P->Next;
    }
    return;
}

Polynomial CreatePoly()
{
    Polynomial P=(Polynomial)malloc(sizeof(struct Node));
    if(P==NULL)
        throw "Out of space!!";
    return P;
}

void AppendPoly(Polynomial Head,Polynomial tmp)
{
    Polynomial P=Head;
    while (P->Next!=NULL)
    {
        P=P->Next;
    }
    P->Next=tmp;
    tmp->Next=NULL;
    return;
}

//加法思路：
//创建两个指针，分别指向Poly1、Poly2，不断比较指针指向的Poly系数大小
//动态的创建PolySum的Node，并不断移动指针，直至NULL

void AddPolynomial(Polynomial Poly1
                  ,Polynomial Poly2,Polynomial PolySum)
{
    ZeroPolynomial(PolySum);
    
    //指向Poly1与Poly2的指针
    Polynomial P1,P2;
    P1=Poly1->Next;
    P2=Poly2->Next;

    int Expo1,Expo2;

    while (P1!=NULL||P2!=NULL)
    {
        if(P1!=NULL&&P2!=NULL)
        {
            Expo1=P1->Exponent;
            Expo2=P2->Exponent;
            if(Expo1>Expo2)
            {
                Polynomial tmp=CreatePoly();
                tmp->Coefficient=P1->Coefficient;
                tmp->Exponent=P1->Exponent;
                AppendPoly(PolySum,tmp);
                P1=P1->Next;
            }
            if(Expo1<Expo2)
            {
                Polynomial tmp=CreatePoly();
                tmp->Coefficient=P2->Coefficient;
                tmp->Exponent=P2->Exponent;
                AppendPoly(PolySum,tmp);
                P2=P2->Next;
            }
            if(Expo1=Expo2)
            {
                Polynomial tmp=CreatePoly();
                tmp->Coefficient=P1->Coefficient+P2->Coefficient;
                tmp->Exponent=P1->Exponent;
                AppendPoly(PolySum,tmp);
                P1=P1->Next;
                P2=P2->Next;
            }
        }
        if(P1!=NULL&&P2==NULL)
        { 
            Polynomial tmp=CreatePoly();
            tmp->Coefficient=P1->Coefficient;
            tmp->Exponent=P1->Exponent;
            AppendPoly(PolySum,tmp);
            P1=P1->Next;
        }
        if(P1==NULL&&P2!=NULL)
        {
            Polynomial tmp=CreatePoly();
            tmp->Coefficient=P2->Coefficient;
            tmp->Exponent=P2->Exponent;
            AppendPoly(PolySum,tmp);
            P2=P2->Next;
        }
    }
    return;
}                  

void Duplicate(Polynomial P1,Polynomial P2)
{

}


//看成多项式乘以多个单项式，然后再相加
void MultiPolynomial(Polynomial Poly1
                      ,Polynomial Poly2,Polynomial PolyProd)
{
    Polynomial P1,P2,TmpSum;
    P1=Poly1->Next;
    P2=Poly2->Next;

    TmpSum=CreatePoly();
    ZeroPolynomial(PolyProd);
    ZeroPolynomial(TmpSum);


    while (P1!=NULL)
    {
        P2=Poly2->Next;
        
        while (P2!=NULL)
        {
            
//  
            P2=P2->Next;
        }


        P1=P1->Next;
    }
    


}


