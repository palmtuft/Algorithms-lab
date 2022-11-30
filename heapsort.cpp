#include <iostream>
using namespace std;

void heapify(int m[], int n, int i){
    // i - корень дерева
    int maxk =i;
    int left = 2*i +1;
    int right= 2*i+2;
    if (left < n && m[left]>m[maxk]){
        maxk=left;
    }
    if (right < n && m[right]>m[maxk]){
        maxk=right;
    }
    if (maxk!=i){
        int tmp=m[i];
        m[i]=m[maxk];
        m[maxk]=tmp;
        heapify(m, n, maxk);
    }
}

void heapsort(int m[], int n){
    for(int i= n/2 -1; i>=0; i--){
        heapify(m, n, i);
    }
    for (int i= n-1; i>0; i--){
        int tmp = m[0];
        m[0]=m[i];
        m[i]=tmp;
        heapify(m, i, 0);
    }
}

int main(){
    int n;
    cin>>n;
    int m[n];
    for (int i=0; i<n; i++){
        cin>>m[i];
    }
    heapsort(m, n);
    for (int i=0; i<n; i++){
        cout<<m[i]<<" ";
    }

}
