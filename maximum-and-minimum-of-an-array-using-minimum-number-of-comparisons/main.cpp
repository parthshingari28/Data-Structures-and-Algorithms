#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,-10,100,70};
    int min=0;
    int max=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i < n; i++){
        cout<<arr[i]<<endl;
    }
    if(n == 1){
        min=max=arr[0];
    }
    if(arr[0] > arr[1]){
        max = arr[0];
        min = arr[1];
    }
    else{
        max = arr[1];
        min = arr[0];
    }
    for(int i=2; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        else if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<"max : "<<max<<endl;
    cout<<"min : "<<min<<endl;
    return 0;
}