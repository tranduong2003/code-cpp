#include <iostream>
#include <string>
using namespace std;

struct Player{
    string name;
    int age;
    float h,w;
    float BMI(){
        return w / (h * h);
    }
};

int main(){
    Player p;
    p.name = "Duong"; p.age = 20; p.w = 60; p.h = 1.7;
    cout<<p.BMI()<<endl;
    int a = 5;
    int &b = a;
    cout<<a<<endl;

    int *pa = &a;
    (*pa) *=2;
    cout<<a<<endl;
    return 0;
}