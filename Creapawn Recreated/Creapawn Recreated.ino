  
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

enum class GameState : uint8_t
{
  PreboutSetup,
  BoutScreen,
};

enum class Direction : uint8_t
{
  Right,
  Left,
  Up,
  Down,
};

enum class Type : uint8_t
{
  Null,
  Nature,
  Synth,
  Mystic,
  Omni,
};

enum class Zodiac : uint8_t
{
  None = 2,
  Sagittarius,
  Capricorn,
  Aquarius,
  Pisces,
  Aries,
  Taurus,
  Gemini,
  Cancer,
  Leo,
  Virgo,
  Libra,
  Scorprio,
  Ophiuchus,
};

struct Pawn
{
  uint8_t type;
  uint8_t zodiac;
  uint8_t level;
  uint8_t energy;
  uint8_t maxEnergy;
  uint8_t actionCost;
  uint8_t power;
  uint8_t damageResistance;
  uint8_t experience;
  uint8_t maxExperience;
  Direction facingDirection;
};

uint8_t pawnByte[8][2];
uint8_t pawnBoardLocation[4][4];
bool turn;
uint8_t actionPoints[2];
uint8_t selectedPawn;
uint8_t buttonClick;

Pawn pawn[8];
GameState gameState = GameState::PreboutSetup;

#include "bitmap.h"
#include "text.h"
#include "pawnconstruct.h"
#include "boutscreen.h"


void Game()
{
  switch (gameState) 
  {
    case GameState::PreboutSetup:
      pawnByte[0][0] = ((random( 0, 32)) * 8) + (random(0, 8));
      pawnByte[0][1] = (random( 0, 225)) + 16;
      pawnByte[1][0] = random( 0, 256);
      pawnByte[1][1] = (random( 0, 225)) + 16;
      pawnByte[2][0] = random( 0, 256);
      pawnByte[2][1] = (random( 0, 225)) + 16;
      pawnByte[3][0] = random( 0, 256);
      pawnByte[3][1] = (random( 0, 225)) + 16;
      PawnConstruct();
      selectedPawn = 0;
      gameState = GameState::BoutScreen;
      break;

    case GameState::BoutScreen:
    DrawBoutScreen();    
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
