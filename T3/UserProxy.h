#pragma once
#include<string>
# include "EncryptStrategy.h"
# include "VerificationStrategy.h"
# include "User.h"
#include<iostream>
using namespace std;

class UserProxy{
public:
    RealUser* usr;
    EncryptStrategy *es;
    VerificationStrategy *vs;
    UserProxy(RealUser* ruser,EncryptStrategy* enc,VerificationStrategy* ver){
        usr = ruser;
        es = enc;
        vs = ver;
        ruser = nullptr;
        enc = nullptr;
        ver = nullptr;
    }
    void sendMessage(string mes){
        string processed_mes;
        processed_mes = es->encode(mes);
        usr->sendMessage(processed_mes);
        cout << vs->verify(mes) << endl;
    }
};