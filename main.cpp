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

    wezel *nowy_wezel(bool is_leaf) {

        wezel *n_node=new wezel;
        n_node->n_arr=new wezel*[MAX_NODE_POINT];
        n_node->k_arr=new int[MAX_KEYS];
        n_node->leaf=is_leaf;
        n_node->amount=0;
        return n_node;

    }

    void podziel_wezel(int i,wezel *cnode, wezel *curr){

        wezel *new_node=nowy_wezel(cnode->leaf);
        new_node->leaf=cnode->leaf;
        new_node->amount=order-1;

        for(int j=0;j<order-1;j++) {

            new_node->k_arr[j]=cnode->k_arr[j+order];

        }

        if(cnode->leaf==false){

            for(int j=0;j<order;j++){

                new_node->n_arr[j]=cnode->n_arr[j+order];

            }
        }

        cnode->amount=order-1;

        for(int j=curr->amount;j>=i+1;j--) {

            curr->n_arr[j+1]=curr->n_arr[j];

        }

        curr->n_arr[i+1]=new_node;

        for(int j=curr->amount-1;j>=i;j--) curr->k_arr[j+1]=curr->k_arr[j];

        curr->k_arr[i]=cnode->k_arr[order-1];

        curr->amount=curr->amount+1;
    }

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

            while(i>=0 && curr->k_arr[i] > key) i--;

                if(curr->n_arr[i+1]->amount==MAX_KEYS) {

                    podziel_wezel(i+1,curr->n_arr[i+1],curr);

                    if(curr->k_arr[i+1]<key) i++;
                }
                insert_n_full(key, curr->n_arr[i+1]);
            }
        }


    void tree_insert(){
        //pobranie danych od uzytkownika
        cout<<"Podaj klucz"<<endl;
        int k;
        cin>>k;
        //

        if(root==NULL){
            root=nowy_wezel(true);
            root->k_arr[0]=k;
            root->amount=1;
        }
        else {

            if(root->amount==MAX_NODE_POINT) {
                wezel *growth =nowy_wezel(false);
                growth->n_arr[0]=root;
                podziel_wezel(0,root,growth);
                int i=0;

                if(growth->k_arr[0]<k) i++;

                insert_n_full(k,growth->n_arr[i]);

                root=growth;
            }
            else insert_n_full(k,root);
        }
    }

};


int main()
{
    Bdrzewo new_tree;
    new_tree.inicjalizacja_drzewa();
    new_tree.tree_insert();
    return 0;
}
