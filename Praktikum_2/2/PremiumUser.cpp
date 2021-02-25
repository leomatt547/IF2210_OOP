//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include <iostream>
#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser(char* nama): User(nama){
    this->active = true;
    this->num_of_music_downloaded = 0;
}

PremiumUser::~PremiumUser(){
    /*
    this->num_of_music_downloaded = 0;
    this->active = false;
    cout << "Premium User "<<this->name<<" deleted"<<endl;
    */
}

PremiumUser::PremiumUser(const PremiumUser& a) : User(a){
    this->num_of_music_downloaded = a.num_of_music_downloaded;
    this->active = a.active;
}

void PremiumUser::downloadMusic(char* judul){
    if(this->active==true){
        cout << "Music Downloaded: "<< judul<< endl;
        num_of_music_downloaded++;
    }else{
        cout << "Activate premium account to download music"<<endl;
    }
}

void PremiumUser::inactivatePremium(){
    this->active = false;
}

void PremiumUser::activatePremium(){
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const{
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const{
    this->active;
}
