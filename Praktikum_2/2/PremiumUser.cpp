//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 2

#include <iostream>
#include "PremiumUser.h"

using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char* name) : User(name) {
    this->active = true;
    this->num_of_music_downloaded = 0;
}

PremiumUser::PremiumUser(const PremiumUser& pu) : User(pu.name) {
    // implementasikan jika diperlukan, 
    // jika tidak diperlukan, hapus cctor
    // jika perlu diimplementasikan, print "Premium User Copied<endl>"
    this->active = pu.active;
    this->num_of_music_downloaded = pu.num_of_music_downloaded;
}

// dtor; implementasikan jika diperlukan
PremiumUser::~PremiumUser() {
    // jika tidak diperlukan, hapus dtor
    // jika diperlukan
    // selain implementasi, print juga "Premium user <nama user> deleted<endl>"
    // Contoh:
    // Premium user A deleted
    cout << "Premium user " << this->name  << " deleted" << endl;
}

void PremiumUser::downloadMusic(char* song) {
    // print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
    // Contoh: 
    // Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
    //
    // Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
    if (this->active)
        cout << "Music Downloaded: " << song << endl;
    else
        cout << "Activate premium account to download music" << endl;
}

void PremiumUser::inactivatePremium() {
    this->active = false;
}
void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const {
    return this->active;
}