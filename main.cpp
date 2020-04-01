#include<iostream>
using namespace std;

struct wezel{

    int data;
    wezel *next[];

};

class Bdrzewo{

    private:
        wezel *wierzcholek=NULL;
        int rzad=10;

    public:
        void inicjalizacja(){

            cout<<"Podaj rzad drzewa:"<<endl;

            while(rzad>5) cin>>rzad;

        }

        void dodaj(){

        }

        void szukaj(){


        }
};





int main()
{
    Bdrzewo tree;
    tree.inicjalizacja();
    return 0;
}
