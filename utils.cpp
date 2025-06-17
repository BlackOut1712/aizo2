#include <iostream>
#include <string>

using namespace std;

string* split(const std::string& str, char splitter){

string temp[str.length()];
int j=0;

    for(int i=0, t=0; i<str.length(); i++){
        if(str[i] == splitter){
            temp[j++] = str.substr(t, i-1);
            t = i+1;
        } 
    }

    return temp;
}