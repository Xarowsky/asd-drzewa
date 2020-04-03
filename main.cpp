#include<iostream>

#define MAX_KEYS order-1
#define MAX_NODE_POINT 2*order-1

using namespace std;

struct wezel{

    wezel **n_arr;
    int *k_arr;
    int amount;
    bool leaf;

};

class Bdrzewo{

private:
    wezel *root;
    int order;
public:
    void inicjalizacja_drzewa(){

        cout<<"Podaj rzad drzewa"<<endl;
        cin>>order;

        root->n_arr=new wezel*[MAX_KEYS];
        root->k_arr=new int[MAX_NODE_POINT];
        root->leaf=1;
        root->amount=0;

    }

    void tree_insert();

    void  tree_delete();

    void tree_search();

};


int main()
{
    Bdrzewo new_tree;
    new_tree.inicjalizacja_drzewa();
    return 0;
}
