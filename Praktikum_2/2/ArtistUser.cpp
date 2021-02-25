//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include <iostream>
#include "ArtistUser.h"

using namespace std;

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* nama): User::User(nama){
    this->num_of_music_uploaded = 0;
    uploaded_music_list = new char*[100];
    for (int i = 0; i<100; i++){
        uploaded_music_list[i] = "NULL";
    }
    num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& a): User::User(a){
    this->num_of_artist = a.num_of_artist;
    this->uploaded_music_list = a.uploaded_music_list;
    num_of_artist++;
}

ArtistUser::~ArtistUser(){
    /*this->num_of_music_uploaded = 0;
    cout << "Artist User "<<this->name<<" deleted"<<endl;
    num_of_artist--;*/
}

void ArtistUser::uploadMusic(char* judul){
    for (int i = 0; i<100; i++){
        if (uploaded_music_list[i] == "NULL"){
            uploaded_music_list[i] = judul;
            break;
        }
    }
}
void ArtistUser::deleteUploadedMusic(char* judul){
    for (int i = 0; i<100; i++){
        if (uploaded_music_list[i] == judul){
            uploaded_music_list[i] = "NULL";
            break;
        }
    }
}
void ArtistUser::viewUploadedMusicList() const{
    if (ArtistUser::getNumOfMusicUploaded() == 0){
        cout << "No music uploaded" << endl;
    }else{
        int nomor = 1;
        for(int i = 0; i < ArtistUser::getNumOfMusicUploaded() ; i++){
            cout <<nomor<<". "<<uploaded_music_list[i] << endl;
            nomor++;
        }
    }
}
int ArtistUser::getNumOfMusicUploaded() const{
    int i = 0;
    int total = 0;
    while ((this->uploaded_music_list[i]!="NULL")&&(i<100)){
        total++;
    }
    return total;
}

int ArtistUser::getNumOfArtist() {
    return ArtistUser::num_of_artist;
}