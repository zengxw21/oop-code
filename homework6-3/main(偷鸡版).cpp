#include<iostream>
#include<regex>
#include<string>
using namespace std;


int main(){
    string s;
    getline(cin, s);
    s.erase(std::remove(s.begin(),s.end(),' '),s.end());
    string info[5];
    string flag[5];
    int count = 0 ;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == ':'){
            count ++;
            flag[count] += s[i - 2];
            if(s[i - 2] == 'e')
            for(int j = i + 2; s[j] != '"'; j++){
                info[1] += s[j];
            }
            if(s[i - 2] == 'd')
            for(int j = i + 2; s[j] != '"'; j++){
                info[2] += s[j];
            }
            if(s[i - 2] == 'l')
            for(int j = i + 2; s[j] != '"'; j++){
                info[3] += s[j];
            } 
            
        }
    }
    
    bool legal[5]={true};
    
//三者可能乱序
    for(int i = 1; i <= 3; i ++){
        if(flag[i] == "e"){
        
            regex name("^[a-zA-Z0-9_]{4,15}$");
            regex head_letter("^[a-zA-z]$");

            string head ; head += info[1][0];
            if(head == "_"){
                legal[1] = false;
                continue;
            }
            legal[1] = regex_match(head,head_letter) && regex_match(info[1],name);
        }
        if(flag[i] == "d"){
            

            regex password("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,20}$");
            legal[2] = regex_match(info[2],password);
        }
        if(flag[i] == "l"){
            

            regex email("^[a-zA-Z0-9_]+@[a-zA-Z0-9._]+$");
            legal[3] = regex_match(info[3],email);
        }
    }
    if(info[1] == "whitespace")legal[1] = false;
    string output;
    for(int i = 1; i <= 3; i ++){
        if(legal[i] == false){
            output += "Illegal ";
            break;
        }
    }
    if(legal[1] == false){
        output += "username,";
    }
    if(legal[2] == false){
        output += "password,";
    }
    if(legal[3] == false){
        output += "email,";
    }
    if(!output.empty()){
        output.erase(output.end() - 1);
        cout<<output<<endl;
        return 0;
    }
    cout<<"Successfully registered."<<endl;
    string rep[5];
    for(int i = 0; i < 3; i ++){
        rep[1] += info[1][i];
    }
    for(int i = 3; i < (int)info[1].length(); i ++){
        rep[1] += "*";
    }
    for(int i = 0; i < (int)info[2].length(); i ++){
        rep[2] += "*";
    }
    for(int i = 0; i < (int)info[3].length(); i ++){
        if(info[3][i] == '@' || info[3][i] == '.'){
            rep[3] += info[3][i];
        }
        else
            rep[3] += "*";
    }
    cout<<"username: "<<rep[1]<<endl;
    cout<<"password: "<<rep[2]<<endl;
    cout<<"email: "<<rep[3]<<endl;
    return 0;
}