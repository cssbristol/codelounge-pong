#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;

enum eDir {STOP=0, LEFT=1, UPLEFT=2, DOWNLEFT=3, RIGHT=4, UPRIGHT=5, DOWNRIGHT=6};

//Class for a ball object
class cBall{
private:
	int x,y;
	int originalX, originalY;
	eDir direction;

public:
	//Constructor for ball object
  cBall(int posX, int posY){
		//Some code
		//Clue : for the moment, set all x and y values
		//of the object as the parameters given
		direction = STOP;
	}

	//Reset all values to original
	void reset(){
		//Some code
		//Clue : Remember that we want the ball to move back to
		// the original coordinates
		direction = STOP;
	}

	//Change direction of the ball to given parameter
	void changeDirection(eDir d){
		//Some code
	}

	//Assign a random direction to object
	void randomDirection(){
		//Some code
		//Clue : You can use the rand() function to pick from the enum
	}

	//Return x coordinate of ball
	int getX(){
		return x;
	}

	//Return y coordinate of ball
	int getY(){
		//Some code
	}

	//Return direction of ball
	eDir getDirection(){
		//Some code
	}

	//Change x and y coordinates depending on the direction
	void move(){
		switch(direction){
			case STOP: break;
			case LEFT: x--; break;
			//Some code
			default : break;
		}
	}
};

//Class for paddle object
class cPaddle{
private:
	int x,y;
	int originalX; int originalY;

public:
	//Basic constructor for paddle object
	cPaddle(){
		x = y = 0;
	}

	//More advanced constructor for paddle object
	cPaddle(int posX, int posY) : cPaddle(){
		//Some code
		//Clue : for the moment, set all x and y values
		//of the object as the parameters given
	}

	//Reet all values to original
	void reset() {
		//Some code
		//Clue : Remember that we want the paddle to move back to
		// the original coordinates
	}

	//Return x coordinate of paddle
	int getX(){
		//Some code
	}

	//Return y coordinate of paddle
	int getY(){
		//Some code
	}

	//Change paddle coordinate to move paddle up
	void moveUp(){
		//Some code
	}

	//Change paddle coordinate to move paddle down
	void moveDown(){
		//Some code
	}
};

//Main class to play game
class cGameManager{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall * ball;
	cPaddle *player1;
	cPaddle *player2;

public:
	//Constructor
	cGameManager(int w, int h){
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 = 'i';
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w; height = h;
		ball = new cBall(w/2, h/2);
		player1 = new cPaddle(1, h/2 - 3);
		player2 = new cPaddle(w-2, h/2 - 3);
	}

	//Destructor
	~cGameManager(){
		delete ball, player1, player2;
	}

	//Increase score for relevant player and reset object positions
	void scoreUp(cPaddle * player){
		if(player == player1){
			//Some code
		}
		else if(player == player2){
			//Some code
		}

		ball->reset();
		player1->reset();
		player2->reset();
	}

	//Draw game screen onto command line
  void draw(){
  	system("clear"); //system("cls") on windows

		//Draw top wall
  	for(int i = 0; i < width + 2; i++){
  		cout << "\xB2";
  	}

  	cout << endl;

		//Draw middle of board
    for(int i = 0; i < height; i++){
			//Loop through each cell and see if wall, ball, paddle or empty space should be printed
      for(int j = 0; j < width; j++){
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        if(j==0){
          cout << "\xB2";
        }

        if(ballx == j && bally == i){
          cout << "O"; //ball
        }
        else if(player1x == j && player1y == i){
          cout << "\xDB"; //player1
        }
        else if(player2x == j && player2y == i){
          cout << "\xDB"; //player2
        }

        else if (player1x == j && player1y + 1 == i)
            cout << "\xDB"; //player1
        else if (player1x == j && player1y + 2 == i)
            cout << "\xDB"; //player1
        else if (player1x == j && player1y + 3 == i)
            cout << "\xDB"; //player1

        else if (player2x == j && player2y + 1 == i)
            cout << "\xDB"; //player1
        else if (player2x == j && player2y + 2 == i)
            cout << "\xDB"; //player1
        else if (player2x == j && player2y + 3 == i)
            cout << "\xDB"; //player1

        else{
          cout << " ";
        }

        if(j == width-1){
          cout << "\xB2";
        }
      }
      cout << endl;
    }

		//Draw bottom wall
  	for (int i = 0; i < width + 2; i++){
  		cout << "\xB2";
  	}

		cout << endl;
    cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
  }

	//Take input from player
  void input(){
  	ball->move();

  	int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();


		//Check characters and do appropriate move
		//Remember to do a check if the paddle has enough space to move!
  	if(_kbhit()){
  		char current = _getch();
  		if(current == up1){
  			//Some code
  		}
  		if(current == up2){
  			//Some code
  		}
  		if(current == down1){
  			if(player1y + 4 < height){
  				//Some code
  			}
  		}
  		if(current == down2){
  			if(player2y + 4 < height){
  				//Some code
  			}
  		}
			//Assign random direction to ball if stopped
  		if(ball->getDirection() == STOP){
  			//Some code
  		}

			//Make the game quit if q is pressed
  		if(current == 'q'){
  			//Some code
  		}
  	}
  }

  void logic(){
  	int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();

  	//left paddle
  	for(int i = 0; i < 4; i++){
  		if(ballx == player1x + 1){
  			if(bally == player1y + i){
  				ball->changeDirection((eDir)((rand() % 3) + 4));
  			}
  		}
  	}

  	//Write collision checks for the right paddle
		//Use the above code to model your paddle

  	//bottom wall
  	if(bally == height - 1){
  		//Some code
  	}

  	//top wall
  	if(bally == 0){
  		//Some code
  	}

  	//right wall
  	if(ballx == width - 1){
  		//Some code
  	}

  	//left wall
  	if(ballx == 0){
  		//Some code
  	}
  }

	//Main game loop
  void run(){
  	while(!quit){
  		draw();
  		input();
  		logic();
  	}
  }
};

//Main function - this will start when the program starts
int main(){
  cGameManager c(40,20);
  c.run();
  return 0;
}
