#pragma once


//void DrawSprite(unint16_t bringSprite, uint8_t )
void DrawPawn(uint16_t bringSprite, int16_t x, int16_t y, bool foreColor, uint8_t currentPawnDirection)
{
  bool backColor = (foreColor == BLACK) ? WHITE : BLACK;

  ardbitmap.drawBitmap(x, y, pawnSpriteBackground[bringSprite / 8], 16, 16, backColor, ALIGN_NONE, currentPawnDirection);
  ardbitmap.drawBitmap(x, y, pawnSprite[bringSprite / 8], 16, 16, foreColor, ALIGN_NONE, currentPawnDirection);
}

void DrawAttackSymbol(uint8_t bringSprite)
{

  switch (bringSprite)
  {
    case 0:
      ardbitmap.drawBitmap(33, 55, swap, 8, 8, 0, 0, 0);
      break;
    case 1:
      ardbitmap.drawBitmap(33, 55, shockWave, 8, 8, 0, 0, 0);
      break;      
    case 2:
      ardbitmap.drawBitmap(33, 55, sacrifice, 8, 8, 0, 0, 0);
      break;
    case 3:
      ardbitmap.drawBitmap(33, 55, blast, 8, 8, 0, 0, 0);
      break;
    case 4:
      ardbitmap.drawBitmap(33, 55, strike, 8, 8, 0, 0, 0);
      break;
    case 6:
      ardbitmap.drawBitmap(33, 55, endure, 8, 8, 0, 0, 0);
      break;      
    case 9:
      ardbitmap.drawBitmap(33, 55, healAll, 8, 8, 0, 0, 0);
      break;   
  }             
}

void SpecialAttackCostFinder(uint8_t specialAttack)
{
  switch (specialAttack)
  {
    case 0 ... 1: case 4: case 9:
      specialAttackCost = 4;
      break;
    case 2 ... 3: case 6:
      specialAttackCost = 3;
      break; 
  }
}

void DrawBoutScreen()
{  
    uint8_t frames = (buttonClick == 1) ? 4 : 8;
  if (arduboy.everyXFrames(frames))
    drawSelectedPawn = (drawSelectedPawn == true) ? false : true;
  uint8_t textBoxOrganizer = 0;
  for (uint8_t i = 0; i < 6; i++)
  {
    textBoxOrganizer = (i == 3) ? 3 : textBoxOrganizer;
    if ((pawnByte[i][1] > 15))
    {
      if (pawn[i].energy > 0)
        TextBox(0, ((textBoxOrganizer * 7) + (9 * (textBoxOrganizer / 3))), 61, 6);
      bool textColor = (pawn[i].energy == 0) ? WHITE : BLACK;
      if ((selectedPawn != i) || (drawSelectedPawn == true))
        Text(pawnByte[i][0], 1, 1 + (9 * (textBoxOrganizer / 3)) + (textBoxOrganizer * 7), textColor);
      tinyfont.setCursor(51, 1 + ((textBoxOrganizer * 7) + (9 * (textBoxOrganizer / 3))));
      if ((i == selectedPawn) && (buttonClick == 1) && ((selectedPawnX != selectedSpotX) || (selectedPawnY != selectedSpotY)) && ((pawnBoardLocation[selectedSpotY][selectedSpotX] < 6) && (pawnBoardLocation[selectedSpotY][selectedSpotX] > 2)))
      {  
        if (drawSelectedPawn == true)
        {
          //int8_t damage = energy - 
         if ((pawn[i].energy - pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].power) < 10)
        tinyfont.print(F("0"));
        tinyfont.print(pawn[i].energy - pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].power);
        }
      } else
      {    
      if (pawn[i].energy < 10)
        tinyfont.print(F("0"));
      tinyfont.print(pawn[i].energy);
      }
      ++textBoxOrganizer;
    }
  }

  uint8_t y = 0;
  for (uint8_t x = 0; x < 4; y)
  {
    if ((pawn[pawnBoardLocation[y][x]].energy == 0) && (pawnBoardLocation[y][x] != 6))
      pawnBoardLocation[y][x] = 6;    
    arduboy.fillRect((x * 16) + 64, y * 16, 16, 16, (x + y)%2);
    switch (buttonClick)
    {
    case 0:
    if ((pawnBoardLocation[y][x] != 6) && (pawn[pawnBoardLocation[y][x]].energy > 0) && ((selectedPawn != pawnBoardLocation[y][x]) || (drawSelectedPawn == true)))
      DrawPawn(pawnByte[pawnBoardLocation[y][x]][0], (x * 16) + 64, y * 16, (pawnBoardLocation[y][x])/3, pawn[pawnBoardLocation[y][x]].facingDirection);
    if (pawnBoardLocation[y][x] == selectedPawn)
    {
      ardbitmap.drawBitmap((x * 16) + 64, y * 16, boardArrowsBackground, 16, 16, 0, 0, 0);
      ardbitmap.drawBitmap((x * 16) + 64, y * 16, boardArrowsForeground, 16, 16, 1, 0, 0);
    }

      break;
    case 1:
    if ((pawnBoardLocation[y][x] != 6) && (pawn[pawnBoardLocation[y][x]].energy > 0) && (((selectedPawn != pawnBoardLocation[y][x]) && (pawnBoardLocation[selectedSpotY][selectedSpotX] != pawnBoardLocation[y][x])) || (drawSelectedPawn == true)))
      DrawPawn(pawnByte[pawnBoardLocation[y][x]][0], (x * 16) + 64, y * 16, (pawnBoardLocation[y][x])/3, pawn[pawnBoardLocation[y][x]].facingDirection);
    ardbitmap.drawBitmap((selectedSpotX * 16) + 64, selectedSpotY * 16, boardArrowsBackground, 16, 16, 0, 0, 0);
    ardbitmap.drawBitmap((selectedSpotX * 16) + 64, selectedSpotY * 16, boardArrowsForeground, 16, 16, 1, 0, 0);
      break;
    }
    if (selectedPawn == pawnBoardLocation[y][x])
    {
      selectedPawnX = x;
      selectedPawnY = y;
    }
    ++y;
    if ((y == 4) && (x != 4))
    {
      y = 0;
      ++x;
    }
  }


  for (uint8_t i = 0; i < 4; ++i)
  {
      TextBox(16 * i, 52, 14, 12);
          if ((selectedMove != i) || (drawSelectedPawn == true))
          {
            switch (i)
            {
              case 0:
                ardbitmap.drawBitmap((i * 16) + 1, 55, move, 8, 8, 0, 0, 0);\
                tinyfont.setCursor( 9, 58);
                tinyfont.print(pawn[selectedPawn].actionCost);
                break;
              case 1:
                ardbitmap.drawBitmap((i * 16) + 1, 55, hit, 8, 8, 0, 0, 0);
                tinyfont.setCursor(25, 58);                
                tinyfont.print(pawn[selectedPawn].actionCost + 2);
                break; 
              case 2:
                SpecialAttackCostFinder(pawn[selectedPawn].specialAttack);          
                DrawAttackSymbol(pawn[selectedPawn].specialAttack);
                tinyfont.setCursor(41, 58);
                tinyfont.print(pawn[selectedPawn].actionCost + specialAttackCost);
                break;
              case 3:
                ardbitmap.drawBitmap((i * 16) + 3, 54, skip, 8, 8, 0, 0, 0);
                break;
            }   
          }
  }
  arduboy.fillRect(0, 21, 16, 6);
  Text(257, 1, 22, BLACK);
  tinyfont.setCursor(11, 22);
  if (buttonClick == 1)
  {
    if (selectedMove == 2)
      SpecialAttackCostFinder(pawn[selectedPawn].specialAttack);
      else if (selectedMove == 1)
        specialAttackCost = 2; 
        else specialAttackCost = 0;   
    if (drawSelectedPawn == true)
      tinyfont.print(actionPoints[0] - (pawn[selectedPawn].actionCost + specialAttackCost));
  } else tinyfont.print(actionPoints[0]);
  arduboy.fillRect(45, 23, 16, 6);
  Text(257, 46, 24, BLACK);
  tinyfont.setCursor(56, 24);
  tinyfont.print(actionPoints[1]);
  Text(256, 26, 23, WHITE);

}

