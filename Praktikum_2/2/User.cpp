//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include <iostream>
#include "User.h"

using namespace std;

int User::n_user = 0;

User::User(char* name){
    this->name = name;
    this->num_of_favourite_music = 0;
    music_list = new char*[100];
    for (int i = 0; i<100; i++){
        music_list[i] = "NULL";
    }
}

User::User(const User& user){
    this->name = user.name;
    this->num_of_favourite_music = user.num_of_favourite_music;
    this->music_list = user.music_list;
    n_user += 1;
}

User::~User(){
    this->num_of_favourite_music = 0;
    n_user -= 1;
    cout << "User "<<this->name<<" deleted"<<endl;
}

void User::addFavouriteMusic(char* judul){
    for (int i = 0; i<100; i++){
        if (music_list[i] == "NULL"){
            music_list[i] = judul;
            break;
        }
    }
}

void User::deleteFavouriteMusic(char* judul){
    for (int i = 0; i<100; i++){
        if (music_list[i] == judul){
            music_list[i] = "NULL";
            break;
        }
    }
}

void User::setName(char* namanya){
    this->name = namanya;
}

char* User::getName() const{
    return this->name;
}

int User::getNumOfFavouriteMusic() const{
    int i = 0;
    int total = 0;
    while ((this->music_list[i]!="NULL")&&(i<100)){
        total++;
    }
    return total;
}

void User::viewMusicList() const{
    if (User::getNumOfFavouriteMusic() == 0){
        cout << "No music in your favourite list" << endl;
    }else{
        int nomor = 1;
        for(int i = 0; i < User::getNumOfFavouriteMusic() ; i++){
            cout <<nomor<<". "<<music_list[i] << endl;
            nomor++;
        }
    }
}

int User::getNumOfUser(){
    return User::n_user;
}