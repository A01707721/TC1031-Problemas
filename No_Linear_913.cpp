#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <vector>
 
using namespace std;
 
class Graph{
    public:
    int *matrix;
    int size;
    vector<int> leaves;
    Graph(int n){
        matrix= new int [n*n];
        size=n;
        for(int i=0; i < n*n; i++){
            matrix[i]=0;
        }
        leaves.resize(n,1);
    }
    ~Graph() {
        delete[] matrix;
    }
    void add_matrix(int branch, int leaf){
        matrix[(branch-1)*size + leaf]=1;
    }
 
    string print(){
        stringstream aux;
        for(int i=0; i < size*size; i++){
            aux << matrix[i] << " ";
        }
        return aux.str();
    }
 
    string printv(){
        stringstream aux;
        for(int i=0; i < size; i++){
            aux << leaves[i] << " ";
        }
        return aux.str();
    }
 
    bool spruce(){
        for(int i=0; i < size; i++){
            int flag=0;
            int acum=0;
            for(int j=0; j  < size; j++){
                int index=size*i+j;
                if(matrix[index]!=0){
                    flag=1;
                    if(leaves[j]==1){
                        acum++;
                    }
                }
            }
            if(flag==1){
                if(acum<3){
                    return false;
                }
            }
            else{
                if(acum>0 && acum<3){
                return false;
                }
            }   
        }
        return true;
    }
    
 
    void not_leaf(int n){
       leaves[n-1]=0;
    }
 
};
 
 
int main(){
    int n;
    cin >> n;
    Graph solve(n);
    for(int i=1; i < n; i++){
        int aux;
        cin >> aux;
        solve.not_leaf(aux);
        solve.add_matrix(aux,i);
    }
    bool cond=solve.spruce();
        if(cond==false){
            cout << "No";
        }
        else{
            cout << "Yes";
        }
}
