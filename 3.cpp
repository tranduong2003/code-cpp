#include <iostream>
#include <string>
using namespace std;
const float pi = 3.14;

float the_tich(float r,float h){
    return pi*r*r*h;
}

void kiem_tra(float *r,float *h){
    
    if(the_tich(*r,*h) < 10){
        (*r)++; (*h)++;
    }
    else{
        (*r)--; (*h)--;
    }
    cout<<"Gia tri cua r,h luc nay la: "<<(*r)<<" "<<(*h)<<endl;
}

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

void test(float& r,float& h){
    
    if(the_tich(r,h) < 10){
        (r)++; (h)++;
    }
    else{
        (r)--; (h)--;
    }
    cout<<"Gia tri cua r,h luc nay la: "<<(r)<<" "<<(h)<<endl;
}

int main(){
    float r,h;
    cout<<"Nhap r,h: ";
    cin>>r>>h;
    cout<<"The tich cua hinh tru tron la: "<<the_tich(r,h)<<"\n";

    // kiem_tra(&r,&h);
    test(r,h);
    return 0;
}
