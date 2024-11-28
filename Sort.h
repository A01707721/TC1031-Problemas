#include <vector>
#include <iostream>
 
using namespace std;
 
class Solution{
    public:
    vector<int> bubbleSort(vector<int> &source) {
	vector<int> v(source);
 
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}
 
void swap(vector<int> &v, int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}
 
 
int solve(vector<int> &v,int c){
    int count=1;
    int total=0;
    int temp=v[0];
    for(int i=1; i < v.size();i++){
        if(v[i]==temp){
            count++;
        }
        else{
            total=total+min(c,count);
            temp=v[i];
            count=1;
        }
    }
    total=total+min(c,count);
    return total;
 
}
};
 
 
int main(){
    Solution test;
    int t;
    cin >> t;
    int n,c;
    while(t--){
        cin >> n >> c;
        vector<int> planets;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            planets.push_back(aux);
        }
        planets=test.bubbleSort(planets);
        int aux=test.solve(planets,c);
        cout << aux << endl;
 
    }
    return 0;
    
 
}
