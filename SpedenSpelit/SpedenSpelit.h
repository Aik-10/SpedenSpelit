#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H
#include <arduino.h>

/*
  initializeTimer() subroutine intializes Arduino Timer1 module to
  give interrupts at rate 1Hz
  
*/
void initializeTimer(void);

/*
  initializeGame() subroutine is used to initialize all variables
  needed to store random numbers and player button push data.
  This function is called from startTheGame() function.
  
*/
void initializeGame(void);

/*
  checkGame() subroutine is used to check the status
  of the Game after each player button press.
  
  If the latest player button press is wrong, the game stops
  and if the latest press was right, game display is incremented
  by 1.
  
  Parameters
  byte lastButtonPress of the player 0 or 1 or 2 or 3
  
*/

/*
  startTheGame() subroutine calls InitializeGame()
  function and enables Timer1 interrupts to start
  the Game.
*/
void startTheGame(void);

long lastRandomNumber = -1; // Initialize to a value not in the desired range
long getRandomNumber() {
  long randomGeneratedNumber;
  
  do {
    randomGeneratedNumber = random(0, 4);
  } while (randomGeneratedNumber == lastRandomNumber);

  lastRandomNumber = randomGeneratedNumber;
  return randomGeneratedNumber;
}


#endif