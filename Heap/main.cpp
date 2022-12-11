#include <iostream>
#include "console.h"
#include "Heap.h"
#include "testing/SimpleTest.h"
#include "vector.h"
using namespace std;

Vector<int> HeapSort(Vector<int> a){
    Heap<int> hp;
    Vector<int> result;
    for (int i=0;i<a.size();i++){
        hp.insert(a[i]);
    }
    while (!hp.isEmpty()){
        result.add(hp.extract());
    }
    return result;
}

int kthLargest(Vector<int> a, int k){
     Heap<int> hp;
    assert(a.size()>k);
    for (int i=0;i<a.size();i++){
        if (i<k){
            hp.insert(a[i]);
        }
        else{
            if (a[i]>hp.peek()){
                hp.peek()=a[i];
                hp.peekUpdated();
            }
        }
    }
    return hp.extract();
}

bool operator<(Vector<int> &a,Vector<int> &b){
    return (a[0]<b[0]);
}

Vector<int> merge(Vector<Vector<int>> a){
    Heap<Vector<int>> hp;
    Vector<int> result;
    for (auto x:a){
        if (!x.isEmpty()){
            hp.insert(x);
        }
    }
    while (!hp.isEmpty()){
        Vector<int> &x=hp.peek();
        result.add(x[0]);
        x.remove(0);
        if (x.isEmpty()){
            hp.extract();
        }
        else{
            hp.peekUpdated();
        }
    }
    return result;
}

int main() {
    Heap<int> h;
    cout<<"h.insert(1)"<<endl;
    cout<<"h.insert(2)"<<endl;
    cout<<"h.insert(3)"<<endl;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    cout<<"------------------------------------"<<endl;
    cout<<"h.contains(4) "<<h.contains(4)<<endl;
    cout<<"h.contains(2) "<<h.contains(2)<<endl;
    cout<<"h.contains(0) "<<h.contains(0)<<endl;
    cout<<"h.contains(2) "<<h.contains(2)<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"h.remove(2)"<<endl;
    h.remove(2);
    cout<<"h.contains(2) "<<h.contains(2)<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"HeapSort({3,1,2,6,9,8,7,5,4}) "<<endl;
    cout<<HeapSort({3,1,2,6,9,8,7,5,4})<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"kthLargest({3,1,2,6,9,8,7,5,4},4) "<<endl;
    cout<<kthLargest({3,1,2,6,9,8,7,5,4},4)<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"merge({{1,2,3},{3,4,5},{1,4,7},{8,9,10}}) "<<endl;
    cout<<merge({{1,2,3},{3,4,5},{1,4,7},{8,9,10}})<<endl;
    cout<<"------------------------------------"<<endl;
//    if (runSimpleTests(ALL_TESTS)) {
//        return 0;
//    }
    return 0;
}
