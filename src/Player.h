class Player {
  private:
    const float width = .5; //the width of an average player.
    const float depth = 1.0/3.0; //the depth of an average player - front to back
    int x;		 //Player x location in meters
    int y;		 //Player y location in meters
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
    init();
    
};
