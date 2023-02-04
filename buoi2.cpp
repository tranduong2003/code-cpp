#include <iostream>
#include <string>
using namespace std;

bool isNum(string s){
    for(int i=0;i<s.size();++i){
        if(!isdigit(s[i])) 
            return false;
    }
    return true;
}
int main(int argc, char *argv[]){
    if(argc < 3){
        cout<<"Thieu du lieu"<<endl;
        exit(0);
    }
    // else if(argc > 3){
    //     cout<<"Thua du lieu"<<endl;
    //     exit(0);
    // }

    if(!isNum(argv[2])){
        cout<<"Age invalid";
        exit(0);
    }

    string name = argv[1];
    string age = argv[2];
    for(int i = 1;i<argc;++i){
        if(argv[i] == "-a"){
            age = argv[i+1];
        }
        if(argv[i] == "-n"){
            name = argv[i+1];
        }
    }

    
    cout<<name<<" "<<age;
    return 0;
}