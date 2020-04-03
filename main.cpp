#include<iostream>
using namespace std;

struct wezel;

struct key{

    int wartosc;
    wezel *prawy;
    wezel *lewy;

};

struct wezel{

    key *arr;
    int amount;

};

class Bdrzewo{

private:
    wezel root;
    int order;
public:
    void inicjalizacja_drzewa();

    void tree_insert();

    void  tree_delete();

    void tree_search();

};


int main()
{
    Bdrzewo tree;
    tree.inicjalizacja();
    return 0;
}
