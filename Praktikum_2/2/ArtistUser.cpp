//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include <iostream>
#include "ArtistUser.h"

using namespace std;

#define N_MAX_UPLOADED_MUSIC_LIST 1000
#define NULL_SONG "EMPTY"

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char* [N_MAX_UPLOADED_MUSIC_LIST];
    for (int i = 0; i < N_MAX_UPLOADED_MUSIC_LIST; i++) {
        this->uploaded_music_list[i] = new char[strlen(NULL_SONG)];
        strcpy(uploaded_music_list[i], NULL_SONG);
    }

    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& au) : User(au.name) {
    this->num_of_music_uploaded = au.num_of_music_uploaded;
    this->uploaded_music_list = new char* [N_MAX_UPLOADED_MUSIC_LIST];
    for (int i = 0; i < N_MAX_UPLOADED_MUSIC_LIST; i++) {
        this->uploaded_music_list[i] = new char[strlen(NULL_SONG)];
        strcpy(this->uploaded_music_list[i], au.uploaded_music_list[i]);
    }

    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    cout << "Artist user " << this->name << " deleted" << endl;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* song) {
    for (int i = 0; i < N_MAX_UPLOADED_MUSIC_LIST; i++) {
        if (strcmp(this->uploaded_music_list[i], NULL_SONG) == 0) {
            this->uploaded_music_list[i] = new char[strlen(song)];
            strcpy(this->uploaded_music_list[i], song);
            break;
        }
    }

    this->num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* song) {
    for (int i = 0; i < N_MAX_UPLOADED_MUSIC_LIST; i++) {
        if (strcmp(this->uploaded_music_list[i], song) == 0) {
            strcpy(this->uploaded_music_list[i], NULL_SONG);
            this->num_of_music_uploaded--;
            break;
        }
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {
    int j = 0;
    for (int i = 0; i < N_MAX_UPLOADED_MUSIC_LIST; i++)
    {
        if (strcmp(this->uploaded_music_list[i], NULL_SONG) != 0) {
            j++;
            cout << j << ". " << this->uploaded_music_list[i] << endl;
        }
    }

    if (j == 0)
        cout << "No music uploaded" << endl;
}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return num_of_artist;
}