//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include "User.h"
#include <iostream>

using namespace std;

#define N_MAX_MUSIC_LIST 1000
#define NULL_SONG "EMPTY"

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->num_of_favourite_music = 0;
    this->music_list = new char* [N_MAX_MUSIC_LIST];
    for (int i = 0; i < N_MAX_MUSIC_LIST; i++) {
        this->music_list[i] = new char[strlen(NULL_SONG)];
        strcpy(this->music_list[i], NULL_SONG);
    }

    n_user++;
}

// cctor
User::User(const User& u) {
    this->name = new char[strlen(u.name)];
    strcpy(this->name, u.name);
    this->num_of_favourite_music = u.num_of_favourite_music;
    this->music_list = new char* [N_MAX_MUSIC_LIST];
    for (int i = 0; i < N_MAX_MUSIC_LIST; i++) {
        this->music_list[i] = new char[strlen(NULL_SONG)];
        strcpy(this->music_list[i], u.music_list[i]);
    }

    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User() {
    cout << "User " << this->name << " deleted" << endl;
    n_user--;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* song) {
    for (int i = 0; i < N_MAX_MUSIC_LIST; i++) {
        if (strcmp(this->music_list[i], NULL_SONG) == 0)
        {
            this->music_list[i] = new char[strlen(song)];
            strcpy(this->music_list[i], song);
            break;
        }
    }

    this->num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* song) {
    for (int i = 0; i < N_MAX_MUSIC_LIST; i++) {
        if (strcmp(this->music_list[i], song) == 0) {
            strcpy(this->music_list[i], NULL_SONG);
            this->num_of_favourite_music--;
            break;
        }
    }
}

void User::setName(char* newName) {
    strcpy(this->name, newName);
}

char* User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
    int j = 0;
    for (int i = 0; i < N_MAX_MUSIC_LIST; i++) {
        if (strcmp(this->music_list[i], NULL_SONG) != 0) {
            j++;
            cout << j << ". " << this->music_list[i] << endl;
        }
    }

    if (j == 0)
        cout << "No music in your favourite list" << endl;
}

int User::getNumOfUser() {
    return n_user;
}