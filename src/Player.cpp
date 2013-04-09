#include "Player.h"
#include <iostream>

Player::Player() {
  init();
}
Player::~Player() {
  //place holder
}

void Player::init(int xi, int yi, int forehand, 
		  int backhand, float spd,
		  float accel, int decel,
		  int agil, int aware,
		  int cutShrp) {
  x = xi;
  y = yi;
  forehandAbility = forehand;
  backhandAbility = backhand;  
  speed = spd;
  acceleration = accel;
  deceleration = decel;  
  agility = agil;   
  awareness = aware;  
  cutSharpness = cutShrp;

  bodyDirection = 0;  //angle pointing to the right of the screen.
  sightDirection = 0; //angle pointintg to the right of the screen
  hasDisc = false;

  foulingRate = foulCallRate = 0;  //@TODO
  
  //@TODO create function to calculate cutting ability
}

bool Player::toss(Player* target) {
  return target->receiveThrow();  
}


bool Player::receiveThrow() {
  return false;
}
bool Player::cut(/*int direction, int sharpness, int xDestination, int yDestination @TODO*/) {
  
  return false;
}


