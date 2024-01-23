#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<vector<std::string> > grammar={
        {"S","AB"},
        {"A","a"},
        {"B","C"},
        {"C","D"},
        {"D","b"}
    };
    for(int i=0;i<grammar.size();++i){
        for(int j=i+1;j<grammar.size();++j){
            if(grammar[i][1]==grammar[j][0]){
                grammar[i][1]=grammar[j][1];
                grammar.erase(grammar.begin()+j);
                i--;
            }
        }
    }
    //printing grammar productions
    for(int i=0;i<grammar.size();++i){
        cout<<grammar[i][0]<<"->"<<grammar[i][1]<<endl;
    }
    return 0;
}