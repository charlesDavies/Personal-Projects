#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

class Player{
    public:
        string name;
        int strength;
        int health;
        int health_max;
        int speed;
        int level;
        int xp;
        string status;

};

class Enemy{
    public:
        string name;
        int strength;
        int health;
        int health_max;
        int speed;
        int level;
        int xp;
        string type;
        string status;

        //FUNCTION THAT MAKES ENEMY MOVES
        void enemy_move(Player &P, Enemy &E){

            if(E.speed > P.speed)
            {
                cout << "The " << E.name <<  " goes first!" << endl;
                cout << "The " << E.name <<  " attacks!" << endl;
                if(E.type == "humanoid")
                {
                    cout << "The " << E.name << " does " << E.strength * 1.2 << " damage!\n";
                    P.health = P.health - E.strength * 1.2;
                }
                if(E.type == "insect")
                {
                    cout << "The " << E.name << " does " << E.strength * 10.3 << " damage and heals a bit back!\n";
                    P.health = P.health - E.strength * 10.3;
                    E.health += E.strength * 5.3;
                    cout << E.name << ": " << E.health << "HP" << endl;

                }
                if(E.type == "busker_boss")
                {
                    srand((unsigned) time(0));
                    int randomNumber = rand() % 5;
                    cout << randomNumber;
                    if(randomNumber == 0) 
                    {
                      cout << E.name << " performs a shitty Oasis cover! The sound is deafening!" << endl;
                      cout << E.name << " does " << E.strength / 2 << " damage and poisons you!" << endl;
                      P.health -= E.strength / 2;
                      P.status = "poisoned";
                    }   
                    if(randomNumber == 1) 
                    {
                      cout << E.name << " hits you with his guitar!" << endl;
                      cout << E.name << " does " << E.strength * 2 << " damage!" << endl;
                      P.health -= E.strength * 2;
                     
                    }
                    if(randomNumber == 2) 
                    {
                      cout << E.name << " eats a Greggs and recovers health!" << endl;
                      cout << E.name << " heals " << E.health / 8 << "  health points!" << endl;
                      E.health += E.health / 8;
                      
                    } 
                     if(randomNumber == 3) 
                    {
                      cout << E.name << " takes coins out of his hat and throws them at you!" << endl;
                      cout << E.name << " deals  " << E.strength * 1.5 << "  health points!" << endl;
                      P.health -= E.strength * 1.5;
                      
                    }   
                     if(randomNumber == 4) 
                    {
                      cout << E.name << " rallies his audience! His stats increase and he gains health regeneration!" << endl;
                      E.strength = E.strength * 1.1;
                      E.speed = E.speed * 1.1;
                      E.status = "regenerating";

                      
                    }      
                    if(E.status == "regenerating")
                    {
                        cout << E.name << " gains " << E.health_max / 24 << " health back." << endl;
                    }                            

                   
                }
            }
            if(P.speed > E.speed)
            {
            
                cout << "The " << E.name <<  " attacks!" << endl;
                if(E.type == "humanoid")
                {
                    cout << "The " << E.name << " does " << E.strength * 1.2 << " damage!\n";
                    P.health = P.health - E.strength * 1.2;
                }
                if(E.type == "insect")
                {
                    cout << "The " << E.name << " does " << E.strength * 10.3 << " damage and heals a bit back!\n";
                    P.health = P.health - E.strength * 10.3;
                    E.health += E.strength * 5.3;
                    cout << E.name << ": " << E.health << "HP" << endl;
                }
                if(E.type == "busker_boss")
                {
                    srand((unsigned) time(0));
                    int randomNumber = rand() % 5;
                    cout << randomNumber;
                    if(randomNumber == 0) 
                    {
                      cout << E.name << " performs a shitty Oasis cover! The sound is deafening!" << endl;
                      cout << E.name << " does " << E.strength / 2 << " damage and poisons you!" << endl;
                      P.health -= E.strength / 2;
                      P.status = "poisoned";
                    }   
                    if(randomNumber == 1) 
                    {
                      cout << E.name << " hits you with his guitar!" << endl;
                      cout << E.name << " does " << E.strength * 2 << " damage!" << endl;
                      P.health -= E.strength * 2;
                     
                    }
                    if(randomNumber == 2) 
                    {
                      cout << E.name << " eats a Greggs and recovers health!" << endl;
                      cout << E.name << " heals " << E.health / 8 << "  health points!" << endl;
                      E.health += E.health / 8;
                      
                    } 
                     if(randomNumber == 3) 
                    {
                      cout << E.name << " takes coins out of his hat and throws them at you!" << endl;
                      cout << E.name << " deals  " << E.strength * 1.5 << "  health points!" << endl;
                      P.health -= E.strength * 1.5;
                      
                    } 
                     if(randomNumber == 4) 
                    {
                      cout << E.name << " rallies his audience! His stats increase and he gains health regeneration!" << endl;
                      E.strength = E.strength * 1.1;
                      E.speed = E.speed * 1.1;
                      E.status = "regenerating";

                      
                    }      
                    if(E.status == "regenerating")
                    {
                        cout << E.name << " gains " << E.health_max / 10000 << " health back." << endl;
                    }               
                    

                   
                }
                

            }
        }
        

};

//FUNCTION THAT LEVELS UP PLAYERS AND ENEMYS
void level_up(Player &P1, Enemy &E1, Enemy &E2){

    //RANDOM NUMBER GEN
    srand((unsigned) time(0));
    int randomNumber;
  
    randomNumber = (rand() % P1.level - 2) + P1.level;
    //cout << randomNumber << endl;
    if (randomNumber <= 0)
    {
        randomNumber = 1;
    }

    E1.level = randomNumber;
    E1.strength = 10 + (E1.level * 8.6);
    E1.health = 100 + (E1.level * 11.6);
    E1.health_max = 100 + (E1.level * 15.6);
    E1.speed = 10 + (E1.level * 9.6);
    E1.xp = E1.level * E1.health_max - (E1.health_max / 1.6);

    E2.level = randomNumber;
    E2.strength = 3 + (E1.level * 1.6);
    E2.health = 90 + (E1.level * 11.6);
    E2.health_max = 90 + (E1.level * 15.6);
    E2.speed = 100 + (E1.level * 1.11);
    E2.xp = E1.level * E1.health_max - (E1.health_max / 1.6);

    // THIS IS DONE TO ALLOW THE ENEMY TO LEVEL UP WITH YOU 

    // YOUR STATS INCREASE
    P1.health_max = P1.health_max * 1.2;
    P1.speed = P1.speed * 1.15;
    P1.strength = P1.strength * 1.10;
    P1.level += 1;
    string stat_to_increase;
    
    cout << "You are now level " << P1.level << "!\n";
    cout << "Please choose a stat to increase: Speed, Strength, Health" << endl;
    cin >> stat_to_increase;

    if (stat_to_increase == "speed")
    {
        P1.speed = P1.speed * 1.3;
    }

    if (stat_to_increase == "strength")
    {
        P1.strength = P1.strength * 1.3;
    }

    if (stat_to_increase == "health")
    {
        P1.health_max = P1.health_max * 1.3;
    }

    cout << "Max Health: " << P1.health_max << endl;
    cout << "Speed: " << P1.speed << endl;
    cout << "Strength: " << P1.strength << endl;

    if(P1.level == 10)
    {
        cout << "You have learned the move cuss!" << endl;
    }


    if(P1.level == 20)
    {
        cout << "You have learned the move dickslap!" << endl;
    }

    


}

void random_battle(Enemy &E1, Enemy &E2, Player &P1){
 
    


    Enemy enemies[2] = {E1, E2};

    srand( time(NULL) ); //Randomize seed initialization
	int r = rand() % 2; // Decides which enemy will appear
    
    



    cout << "A level " << enemies[r].level << " " << enemies[r].name << " Appears!" << endl;
    int turn = 0;
    
    //RESET ENEMY HEALTH TO MAX AFTER EACH BATTLE
    enemies[r].health = enemies[r].health_max;

  while (enemies[r].health > 0 && P1.health > 0)
  {
      turn++;
      
      cout << "----------TURN " << turn << "-----------" << endl;
      cout << P1.name << ": " << P1.health << "HP" << endl;
      cout << enemies[r].name << ": " << enemies[r].health << "HP" << endl;
      if (P1.level < 20)
      {
          cout << "Punch, Kick or Heal?" << endl;
      }
      if(P1.level >= 20)
      {
          cout << "Punch, Kick, Heal or Dickslap?" << endl;
      }
      string input;
      cin >> input;

      if (enemies[r].speed > P1.speed)
      {
        if (enemies[r].health > 0)
        {
            if (r == 0)
            {
                cout << "The " << enemies[r].name <<  " goes first!" << endl;
                cout << "The " << enemies[r].name <<  " attacks!" << endl;
                cout << "The " << enemies[r].name << " does " << enemies[r].strength * 1.2 << " damage!\n";
                P1.health = P1.health - enemies[r].strength * 1.2;
            }

            if (r == 1)
            {
                cout << "The " << enemies[r].name <<  " goes first!" << endl;
                cout << "The " << enemies[r].name <<  " sucks your blood!" << endl;
                cout << "The " << enemies[r].name << " does " << enemies[r].strength * 10.3 << " damage and heals a bit back!\n";
                P1.health = P1.health - enemies[r].strength * 10.3;
                enemies[r].health += enemies[r].strength * 5.3;
                cout << enemies[r].name << ": " << enemies[r].health << "HP" << endl;

            }
            
            
            
        }
      }
      if (P1.health >= 0)
      {
        if (input == "punch")
        {
            enemies[r].health = enemies[r].health - P1.strength * 1.5;
            cout << P1.name << " punches!" << endl;
            cout << P1.name << " does " << P1.strength * 1.5 << " damage!\n";
            cout << enemies[r].name << " health drops to " << enemies[r].health << endl;
        }
        if (input == "kick")
        {
            enemies[r].health = enemies[r].health - P1.speed * 1.7;
            cout << P1.name << " kicks!" << endl;
            cout << P1.name << " does " << P1.speed * 1.7 << " damage!\n";
            cout << enemies[r].name << " health drops to " << enemies[r].health << endl;
        }
        if (input == "heal")
        {
            P1.health = P1.health_max;
            cout << P1.name << " heals to max health!\n";
            
        }
        if (input == "cuss" && P1.level >= 10)
        {
            P1.strength = P1.strength * 1.15;
            P1.speed = P1.speed * 1.15;
            P1.health_max = P1.health_max * 1.15;

            cout << P1.name << " raises his stats!\n";
            
        }

        if (input == "dickslap" && P1.level >= 20)
        {
            enemies[r].health = enemies[r].health - P1.speed + P1.strength * 3;
            cout << P1.name << " performs a majestic dickslap!" << endl;
            cout << P1.name << " does " << (P1.speed + P1.strength) * 3 << " damage!\n";
            cout << enemies[r].name << " health drops to " << enemies[r].health << endl;

        }
      }

      if (enemies[r].speed < P1.speed)
      {
        if (enemies[r].health > 0)
        {

            if (r == 0)
            {
                cout << "The " << enemies[r].name <<  " attacks" << endl;
                cout << "The " << enemies[r].name << " does " << enemies[r].strength * 1.2 << " damage!\n";
                P1.health = P1.health - enemies[r].strength * 1.2;
            }
            if (r == 1)
            {
                cout << "The " << enemies[r].name <<  " goes first!" << endl;
                cout << "The " << enemies[r].name <<  " attacks!" << endl;
                cout << "The " << enemies[r].name << " does " << enemies[r].strength * 10.3 << " damage and heals a bit back!\n";
                P1.health = P1.health - enemies[r].strength * 10.3;
                enemies[r].health += enemies[r].strength * 5.3;
                cout << enemies[r].name << ": " << enemies[r].health << "HP" << endl;
            }
            
            
        }
      }


      
  }

  if (P1.health <= 0)
  {
      cout << "------------" << P1.name << " FAINTED------------" << endl;
      cout << "Oh no! You fainted! Would you like to continue?" << endl;
      string carry_on;
      cin >> carry_on;
    if (carry_on == "yes")
    {
        P1.health = P1.health_max;
        random_battle(E1, E2, P1);
    }
    else{
        cout << "So you've given up...." << endl;
    }
      
  }



  if (enemies[r].health <= 0)
  {
      cout << P1.name << " defeated " << enemies[r].name << endl;
      cout << P1.name << " gained " << enemies[r].xp << " xp" << endl;
      P1.xp += enemies[r].xp;
      cout << P1.xp << endl;
  }

  if (P1.xp >= P1.level * 100 )
      {
        if (P1.health > 0){
           cout << "LEVEL UP" << endl;
           level_up(P1, E1, E2);
           P1.health = P1.health_max;
         }
      }

     if(P1.status == "poisoned")
      {
        cout << "The poison ticks away at your health!" << endl;
        cout << "Poison does " << P1.health_max / 16 << " damage." << endl;
        P1.health -= P1.health_max / 16;
      }

      cout << "---------------------------" << endl;
  
}

//SINGLE BATTLES WITH A PREDETERMINED ENEMY
void battle(Enemy &E, Player &P){
 
    


    
    



    cout << "A level " << E.level << " " << E.name << " Appears!" << endl;
    int turn = 0;
    
    //RESET ENEMY HEALTH TO MAX AFTER EACH BATTLE
    E.health = E.health_max;

  while (E.health > 0 && P.health > 0)
  {
      turn++;
      
      
      cout << "----------TURN " << turn << "-----------" << endl;
      cout << P.name << ": " << P.health << "HP" << endl;
      cout << E.name << ": " <<E.health << "HP" << endl;
     if (P.level < 20)
      {
          cout << "Punch, Kick or Heal?" << endl;
      }
      if(P.level >= 20)
      {
          cout << "Punch, Kick, Heal or Dickslap?" << endl;
      }
      string input;
      cin >> input;

      if (E.speed > P.speed)
      {
        if (E.health > 0)
        {
           E.enemy_move(P, E);
            
            
            
        }
      }
      if (P.health >= 0)
      {
        if (input == "punch")
        {
           E.health = E.health - P.strength * 1.5;
            cout << P.name << " punches!" << endl;
            cout << P.name << " does " << P.strength * 1.5 << " damage!\n";
            cout << E.name << " health drops to " << E.health << endl;
        }
        if (input == "kick")
        {
            E.health = E.health - P.speed * 1.7;
            cout << P.name << " kicks!" << endl;
            cout << P.name << " does " << P.speed * 1.7 << " damage!\n";
            cout << E.name << " health drops to " << E.health << endl;
        }
        if (input == "heal")
        {
            P.health = P.health_max;
            cout << P.name << " heals to max health!\n";
            
        }
        if (input == "cuss" && P.level >= 10)
        {
            P.strength = P.strength * 1.15;
            P.speed = P.speed * 1.15;
            P.health_max = P.health_max * 1.15;

            cout << P.name << " raises his stats!\n";
            
        }
        if (input == "dickslap" && P.level >= 20)
        {
            E.health = E.health - P.speed + P.strength * 3;
            cout << P.name << " performs a majestic dickslap!" << endl;
            cout << P.name << " does " << P.speed + P.strength * 3 << " damage!\n";
            cout << E.name << " health drops to " << E.health << endl;

        }
      }
      

      if (E.speed < P.speed)
      {
        if (E.health > 0)
        {

           E.enemy_move(P, E);
            
        }
      }


      
  }

  if (P.health <= 0)
  {
      cout << "------------" << P.name << " FAINTED------------" << endl;
      cout << "Oh no! You fainted! Would you like to continue?" << endl;
      string carry_on;
      cin >> carry_on;
  }
    


  if (E.health <= 0)
  {
      cout << P.name << " defeated " << E.name << endl;
      cout << P.name << " gained " << E.xp << " xp" << endl;
      P.xp += E.xp;
      cout << P.xp << endl;
  }

  if (P.xp >= P.level * 100 )
      {
        if (P.health > 0){
           cout << "LEVEL UP" << endl;
           level_up(P, E, E);
           P.health = P.health_max;
         }
      }

      cout << "---------------------------" << endl;

   if(P.status == "poisoned")
      {
        cout << "The poison ticks away at your health!" << endl;
        cout << "Poison does " << P.health_max / 16 << " damage." << endl;
        P.health -= P.health_max / 16;
      }
  
  
  
}

int main() 
{

 
  
  //PLAYER CHARACTER CLASS
  Player P1;
  P1.name = "";
  P1.strength = 20;
  P1.health = 100;
  P1.health_max = 100;
  P1.speed = 25;
  P1.level = 1;
  P1.xp = 0;
  P1.status = "none";


  

  //GOBLIN ENEMY 
  Enemy E1;
  E1.name = "Goblin";
  E1.level = 1;
  E1.strength = 10; 
  E1.health = 100;
  E1.health_max = 100;
  E1.speed = 10;
  E1.xp = E1.level * E1.health_max - (E1.health_max / 1.6);
  E1.type = "humanoid";
  E1.status = "none";

  //GIANT MOSQUITO ENEMY
  Enemy E2;
  E2.name = "Giant Mosquito";
  E2.level = 3;
  E2.strength = 3;
  E2.health = 90;
  E2.health_max = 90;
  E2.speed = 100;
  E2.xp = E2.level * E2.health_max - (E2.health_max / 1.6); 
  E2.type = "insect";
  E2.status = "none";

  //TOWN BUSKER BOSS
  Enemy E3;
  E3.name = "Obnoxious Town Busker";
  E3.level = 30;
  E3.strength = 500;
  E3.speed = 500;
  E3.health = 1000000;
  E3.health_max = 1000000;
  E3.xp = 100000;
  E3.type = "busker_boss";
  E3.status = "none";
  
  //TEST
  Enemy enemies[2] = {E1, E2};

  //int one = 1;
  
  //TEST

  cout << "Please enter your name: ";
  cin >> P1.name;
 
  string carry_on = "yes";
  
 cout << "Would you like to train or fight the boss?" << endl;
 string input;
 string yesOrNo;
 cin >> input;
 if(input == "train")
 {
  while(P1.health >= 0 )
  {
  random_battle(E1, E2, P1);
  cout << "Carry on training?" << endl;
  cin >> yesOrNo;
  if(yesOrNo == "no")
  {
    cout << "Oh No! The boss appeared!" << endl;
    battle(E3, P1);
    if(P1.health > 0)
    {
    cout << "You did it! The boss is no more!";
    }
    break;
  }


  }
 }
 if(input == "boss")
 {
     battle(E3, P1);
 }

  
  
  
  

  cout << P1.level;
}