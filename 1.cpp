#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x,n;
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"Nhap n: ";
    cin>>n;

    int dem = 1;
    for(int i=2;dem<=n;++i){
        int dem_uoc = 0;
        for(int j=1;j<=i;++j){
            if(i%j==0) dem_uoc++;
        }
        if(dem_uoc == 2){
            cout<<x<<" x "<<i<<" = "<<x*i<<endl;
            dem++;
        }   
    }
    return 0;
}