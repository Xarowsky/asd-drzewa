#include<iostream>

#define MAX_KEYS 2*order
#define MAX_NODE_POINT 2*order+1

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
        root=NULL;
    }

    wezel *nowy_wezel() {

        wezel *n_node=new wezel;
        n_node->n_arr=new wezel*[MAX_NODE_POINT];
        n_node->k_arr=new int[MAX_KEYS];
        n_node->leaf=true;
        n_node->amount=0;
        return n_node;

    }

    void podziel_wezel(){}

    void insert_n_full(int key,wezel *curr){

        int i=curr->amount-1;
        if (curr->leaf==true) {

            while(i>=0 && curr->k_arr[i]>key) {

                curr->k_arr[i+1]=curr->k_arr[i];
                i--;

            }

            curr->k_arr[i+1]=key;
            curr->amount=curr->amount+1;

        }
        else {

            while(i>=0 && curr->k_arr > key) i--;

                if(curr->n_arr[i+1]->amount==MAX_KEYS) {

                    podziel_wezel(i+1,curr->n_arr[i+1]);

                    if(curr->k_arr[i+1]<k) i++;
                }
                insert_n_full(key, curr->n_arr[k+1]);
            }
        }
    }

    void tree_insert(){
        //pobranie danych od uzytkownika
        cout<<"Podaj klucz"<<endl;
        int k;
        cin>>k;
        //

        if(root==NULL){
            root=nowy_wezel();
        }
        else {
            if(root->amount==MAX_NODE_POINT) {

            }


        }
    }

    void  tree_delete();

    void tree_search();

};


int main()
{
    Bdrzewo new_tree;
    new_tree.inicjalizacja_drzewa();
    return 0;
}
