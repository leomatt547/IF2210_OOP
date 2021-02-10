#include <iostream>
#include "Bottle.hpp"

using namespace std;

int Bottle::numOfBottle = 0;

Bottle::Bottle(): id(numOfBottle + 1){
    this->waterHeight = 0.00;
    this->height = 10.00;
    this->radius = 10.00;
    numOfBottle += 1;
}

Bottle::Bottle(float height, float radius): id(numOfBottle + 1){
    this->waterHeight = 0.00;
    this->height = height;
    this->radius = radius;
    numOfBottle += 1;
}

Bottle::Bottle(const Bottle& bottle): id(bottle.id){
    this->height = bottle.height;
	this->radius = bottle.radius;
	this->waterHeight = bottle.waterHeight;
}

Bottle::~Bottle(){
    
}

int Bottle::getId() const{
    return this->id;
}

float Bottle::getWaterVolume() const{
    return (PI * this->radius * this->radius * this->waterHeight);
}

float Bottle::getBottleVolume() const {
	return (PI * this->radius * this->radius * this->height);
}

void Bottle::setHeight(float height) {
	this->height = height;
	if (this->height < this->waterHeight) {
		this->waterHeight = this->height;
	}
}

void Bottle::addWater(float waterVolume) {
	float selisih = waterVolume / (PI * this->radius * this->radius);
	if (this->waterHeight + selisih > this->height) {
		this->waterHeight = this->height;
	}else{
		this->waterHeight = this->waterHeight + selisih;
	}
}

void Bottle::substractWater(float waterVolume) {
	float selisih = waterVolume / (PI * this->radius * this->radius);
	if (this->waterHeight - selisih < 0) {
		this->waterHeight = 0.00;
	} else {
		this->waterHeight = this->waterHeight - selisih;
	}
}

float Bottle::getWaterHeightIfVolume(float waterVolume) const {
	return (waterVolume / (PI * this->radius * this->radius));
}

void Bottle::pourWaterTo(Bottle& other) {
	float WaterVolume1 = PI * this->radius * this->radius * this->waterHeight;
	float WaterVolume2 = other.getWaterVolume();
	float otherBottleVolume = other.getBottleVolume();
	if (WaterVolume1 > otherBottleVolume - WaterVolume2) {
		this->substractWater(otherBottleVolume - WaterVolume2);
		other.waterHeight = other.height;
	}else{
		this->waterHeight = 0.00;
		other.addWater(WaterVolume1);
	}
}