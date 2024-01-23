#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
 
using namespace std;

int corrState(map<pair<int,int>,vector<int>> &adjList,int index,int x){
    int val1 = -1;
    for (int i= 0;i <= 2;i++){
        if ((x & (1 << i))){
            vector<int> temp = adjList[{i,index}];
            if (temp.size()== 1 && temp[0] == -1){
                continue;
            }
            else{
                int newVal = 0;
                for (auto k : temp){
                    if (val1 == -1 || ((val1&(1 << k)) == 0))
                        newVal += (1<< k);
                }
                if (val1== -1)
                    val1 = newVal;
                else
                    val1 += newVal;
            }
        }
    }
    return val1;
        
}

void printDFA(vector<vector<int>> &DFA_transitionTable,set<int> &states){
    cout << "Transition Table of DFA: " << endl;
    cout << "q  ";
    for (int i = 0;i < DFA_transitionTable[0].size();i++){
        cout << (char) ('a'+i) << "  ";
    }
    cout << endl;
    for (int i = 1;i < DFA_transitionTable.size();i++){
        if (states.find(i) == states.end())
            continue;
        cout << "q" << i << " ";
        for (int j = 0;j < DFA_transitionTable[0].size();j++){
            if (DFA_transitionTable[i][j] == -1)
                cout << "qd ";
            else    
                cout << "q" << DFA_transitionTable[i][j] << " ";

        }
        cout << endl;
    }
    cout << endl;
}

void makeFinalDFAstates(set<int> &states,vector<int> &final,vector<int> &FinalStatesInDFA){
    for (auto x : states){
        bool flag = 0;
        for (auto i : final){
            if (((1<<i)&x) != 0)
                flag = 1;
        }
        if (flag){
            FinalStatesInDFA.push_back(x);
        }
    }
}

void printStartDFAstates(){
    cout << "Start States in DFA : q0" << endl;
}

void printFinalDFAstates(vector<int> &FinalStatesInDFA){
    cout << "Final States in DFA : ";

    cout << "q";
    for (int i = 0;i < FinalStatesInDFA.size()-1;i++){
        cout << FinalStatesInDFA[i] << ", q";
    }
    cout << FinalStatesInDFA[FinalStatesInDFA.size()-1] << endl;
}

int main(){  
    cout << "Enter Transition Table : ";
    int row,col; cin >> row >> col;
    map<pair<int,int>,vector<int>> adjList;
    for (int i = 0;i < row;i++){
        for (int j = 0;j < col;j++){
            int size; cin >> size;
            for (int k = 0;k < size;k++){
                int temp; cin >> temp;
                adjList[{i,j}].push_back(temp);
            }
        }
    }
    int sfinal; cin >> sfinal; vector<int> final;
    for (int i = 0;i < sfinal;i++){
        int temp; cin >> temp;
        final.push_back(temp);
    }
  
    //make those states which are achievable using given bits;
    set<int> states;
    //inserting obvious states;
    for (auto x : adjList){
        // debug(x.first.first);
        states.insert(1 << x.first.first);
        int val = 0;
        for (auto i : x.second){
            if (i == -1){
                val = -1;
                break;
            }
            val += (1 << i);
        }
        if (val != -1)
            states.insert(val);
    }

    //inserting all states;
    bool flag = 1;
    while (flag){
        flag = 0;
        for (auto x : states){
            int val1 = corrState(adjList,0,x);
            int val2 = corrState(adjList,1,x);

            if (val1 != -1 && states.find(val1) == states.end()){
                states.insert(val1);
                flag = 1;
            }
            if (val2 != -1 && states.find(val2) == states.end()){
                states.insert(val2);
                flag = 1;
            }
        }
    }

    //we gathered all DFA states in our set;
    //now constructing DFA;
    vector<vector<int>> DFA_transitionTable(8,vector<int>(2,-1));
    for (auto x : states){
        int val1 = corrState(adjList,0,x);
        int val2 = corrState(adjList,1,x);
        
        DFA_transitionTable[x][0] = val1;
        DFA_transitionTable[x][1] = val2;

    }
    printDFA(DFA_transitionTable,states);

    vector<int> FinalStatesInDFA;
    makeFinalDFAstates(states,final,FinalStatesInDFA);
    printStartDFAstates();
    printFinalDFAstates(FinalStatesInDFA);
    
    // row col : 3 2 
    // table : 1 0 2 0 1 1 -1 1 2 1 2 1 2
    // final state : 1 2
    // 3 2 1 0 2 0 1 1 -1 1 2 1 2 1 2 1 2
}