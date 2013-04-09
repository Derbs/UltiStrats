#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {
  private:
    const static float width = .5; //the width of an average player. (in meters)
    const static float depth = 1.0/3.0; //the depth of an average player - front to back
    double x;		 //Player x location in meters
    double y;		 //Player y location in meters
    int height;  	 //Player's height.  May be used for layout function...
    int cuttingAbility;  //0-10 discreet, arbitrary stat
    int forehandAbility; //0-10 discreet, arbitrary stat
    int backhandAbility; //0-10 discreet, arbitrary stat
    float speed; 	 //0-5 (in meters/sec)
    float acceleration;  //0-5 (in meters/sec/sec) [maybe not realistic to accelerate that quickly... but let's go with it!]
    int deceleration;    //0-5 (in meters/sec/sec) [again, high value may not be realistic...]
    int agility;       	 //the speed at which a player changes direction. (angle)
    int bodyDirection;   //the angle which a player's body is facing
    int sightDirection;  //the angle which a player's head is facing
    int awareness;	 //an angle, but it is actually the width of a player's frame of view.  will be visualized as a cone centered on sightDirection.  
    int cutSharpness;    //the sharpest cut a player can make in degrees.
    bool hasDisc;	 //does the player have the disc right now?
    int foulingRate;     //a percentage from 0 to 100.  How often does the player foul?
    int foulCallRate;    //a % from 0-100.  if a player IS fouled, what is the rate that a player calls it?
  public:
    Player();
    ~Player();

    void init(double xi = 20, double yi = 20, int forehand = 10, 
	      int backhand = 10, float spd = 3.0,
              float accel = 1.0, int decel = 2.0,
	      int agil = 60, int aware = 60,
	      int cutShrp = 150);

   //getters
    double getX();
    double getY();
    int getBodyFacing();
    int getSightFacing();

    bool cut(/*int direction, //0-360
	     int sharpness, //0-cutSharpness max
	     int xDestination,
	     int yDestination @TODO*/);
    bool toss(Player* target);
    bool receiveThrow();
};
#endif
