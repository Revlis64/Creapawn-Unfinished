
   /*
   Copyright (C) 2022 Revlis

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   */

#include <Arduboy2.h>
#include <Tinyfont.h>
#include <ArduboyTones.h>
#include <ArduboyTonesPitches.h>

Arduboy2Base arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
ArduboyTones sound(arduboy.audio.enabled);
#define ARDBITMAP_SBUF arduboy.getBuffer()
#include <ArdBitmap.h>
ArdBitmap<WIDTH, HEIGHT> ardbitmap;

  const bool right = 0;
  const bool left = 1;
  const uint8_t up = 3;
  const uint8_t down = 4;
  uint8_t gameState = 1;
  uint8_t pawn[8][2];
  uint8_t player;
  uint8_t enemy;
  uint8_t attacker;
  uint8_t defender;
  uint8_t type[8];
  uint8_t level[8];
  uint8_t zodiac[8];
  uint8_t maxEnergy[8];
  uint8_t energy[8];
  uint8_t actionCost[8];
  uint8_t power[8];
  uint8_t damageResistance[8];
  uint8_t experience[4];
  uint8_t maxExperience[4];
  uint8_t pawnXPosition[8];
  uint8_t pawnYPosition[8];
  bool pawnDirection[8];
  uint8_t pawnBoardLocation[4][4];
  uint8_t drawSelectedPawn;
  /*uint8_t turnList[32];*/
  bool turn;
  uint8_t actionPoints[2];
  uint8_t selectedPawn;
  uint8_t buttonClick;

#include "bitmap.h"
#include "text.h"
#include "pawnconstruct.h"
#include "boutscreen.h"
#include "bout.h"

void Game()
{
  switch (gameState) 
  {
    case 1:
    pawn[0][0] = random( 0, 256);
    pawn[0][1] = (random( 0, 225)) + 16;
    pawn[1][0] = random( 0, 256);
    pawn[1][1] = (random( 0, 225)) + 16;
    pawn[2][0] = random( 0, 256);
    pawn[2][1] = (random( 0, 225)) + 16;
    pawn[3][0] = random( 0, 256);
    pawn[3][1] = (random( 0, 225)) + 16;
      PawnConstruct();
      /*CompileTurnList();*/
      gameState = 0;
      selectedPawn = 0;
      drawSelectedPawn = 1;
      
      break;
    case 0:
      Bout();
      DrawBoutScreen();
      
      break;
    case 2:
      break;
  }


}

void setup()
{
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.initRandomSeed();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!arduboy.nextFrame())
    return;
  arduboy.clear();
  arduboy.pollButtons();
  Game();
  arduboy.display();
}
