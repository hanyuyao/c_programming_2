#include <iostream>

using namespace std;

typedef struct Sparse_vector{
    int dim;
    int val;
    Sparse_vector* next;
} Sparse_vector;

Sparse_vector ReadVector(void)
{
    Sparse_vector sv;
    Sparse_vector* svPlace = &sv;
    char temp;

    cin >> sv.dim;
    cin >> temp;
    cin >> sv.val;

    while(svPlace->dim != 0 || svPlace->val != 0){
        svPlace->next = new Sparse_vector();
        cin >> svPlace->next->dim;
        cin >> temp;
        cin >> svPlace->next->val;
        svPlace = svPlace->next;
    }
    svPlace->next = NULL;
    return sv;
}

void ShowVector(Sparse_vector sv)
{
    Sparse_vector* svPlace;
    svPlace = &sv;
    cout << sv.dim << ':' << sv.val << ' ';

    while(svPlace->next != NULL){
        svPlace = svPlace->next;
        cout << svPlace->dim << ':' << svPlace->val << ' ';
    }
}

int main()
{
    Sparse_vector sv1 = ReadVector();
    Sparse_vector sv2 = ReadVector();
    long long int ans = 0;

    Sparse_vector* sv1Place = &sv1;
    Sparse_vector* sv2Place = &sv2;

    while(sv1Place != NULL && sv2Place != NULL){
        if(sv1Place->dim > sv2Place->dim){
            sv2Place = sv2Place->next;
        }
        else if(sv1Place->dim < sv2Place->dim){
            sv1Place = sv1Place->next;
        }
        else{
            ans += (sv1Place->val * sv2Place->val);
            sv1Place = sv1Place->next;
            sv2Place = sv2Place->next;
        }
    }

    cout << ans << endl;
}
