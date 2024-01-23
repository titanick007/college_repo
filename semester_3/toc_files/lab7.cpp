#include <bits/stdc++.h>
using namespace std;

// Leftmost Derivation Tree for-
// S → A1B
// A → 0A|ε    (represents 0*)
// B → 0B|1B|ε     (represents any valid string of 0 & 1)
// Thus, String will be of type --> (0*)1(any string of 0 & 1)

string Left_Derivation(string w, string s){

    int index_1 = -1, i = 0, index_A = 0;
    for(int i=0 ; i<w.size() ; i++){
        if(w[i] == '1'){
            index_1 = i;
            break;
        }
    }

    if(index_1 == -1){
        return "Impossible";
    }

    s = "A1B";

    while(i < index_1){
        s = "0" + s;
        i++;
        cout << s << endl;
    }

    for(int i=0 ; i<s.size() ; i++){
        if(s[i] == 'A'){
            index_A = i;
            break;
        }
    }

    s = s.substr(0, index_A) + s.substr(index_A+1, s.size() - index_A - 1);
    cout << s << endl;

    i = 0;
    while(s[i] == w[i]){
        i++;
    }

    while(i < w.size()){
        s = s.substr(0, i) + w[i] + "B";
        i++;
        cout << s << endl;
    }

    s.pop_back();

    return s;

}

signed main(){
    
    string w;   cout << "Enter a string : ";    cin >> w;

    string s = "";

    cout << Left_Derivation(w, s) << endl;
}