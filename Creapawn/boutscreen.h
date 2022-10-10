#pragma once

/*  
    arduboy.fillRect( pawnXPosition[squareSelector], pawnYPosition[squareSelector], 16, 16, (((pawnYPosition[squareSelector] + pawnXPosition[squareSelector]) * 4) % 128) / 64);
*/

void DrawSprite(uint16_t bringSprite, uint8_t x, uint8_t y, bool color, uint8_t currentPawnDirection) 
{
  uint8_t color2 = true;
  if (color == true)
   color2 = false;
   
  switch (bringSprite)
  {
    case 0 ... 255:
      ardbitmap.drawBitmap(x, y, pawnSpriteBackground[bringSprite / 8], 16, 16, color2, ALIGN_NONE, currentPawnDirection);
      ardbitmap.drawBitmap(x, y, pawnSprite[bringSprite / 8], 16, 16, color, ALIGN_NONE, currentPawnDirection);
      break;
  }
}

void DrawBoutScreen() 
{

  uint8_t a = 0; 
  uint8_t b = 0;
  uint8_t c = 0;
  for (uint8_t i = 0; i < 4; ++a)
  {
    if ((pawn[i][1] > 15) & (a == 1))
    {
      if (energy[i] > 0)
        TextBox(0, (b * 7), 61, 6);
      bool textColor = BLACK;
      if (energy[i] == 0)
        textColor = WHITE;
      Text(pawn[i][0], 1, 1 + (b * 7), textColor);
    //(grabText, x, y)
      tinyfont.setCursor(51, 1 + (b * 7));
      if (energy[i] < 10)
        tinyfont.print(F("0"));
      tinyfont.print(energy[i]);
      ++b;
    }

    if ((pawn[i+4][1] > 15) & (a == 1))
    {
      if (energy[i+4] > 0)
        TextBox(0, 37 + (c * 7), 61, 6);
      bool textColor = BLACK;
      if (energy[i+4] == 0)
        textColor = WHITE;
      Text(pawn[i+4][0], 1, 38 + (c * 7), textColor);
    //(grabText, x, y)
      tinyfont.setCursor(51, 38 + (c * 7));
      if (energy[i+4] < 10)
        tinyfont.print(F("0"));
      tinyfont.print(energy[i+4]);
      ++c;
    }
    
    if ((a == 4) & (i != 4))
    {
      a = 0;
      ++i;
    }
    
    arduboy.fillRect((a * 16) + 64, i * 16, 16, 16, (i + a)%2);
    


  }
  uint8_t frames = (buttonClick == 1) ? 4 : 8;
  if (arduboy.everyXFrames(frames))
    if (drawSelectedPawn == 1)
      drawSelectedPawn = 0;
      else drawSelectedPawn = 1;

  for (uint8_t i = 0; i < 8; ++i)
  {
    if (pawn[i][1] <= 15)
      continue;

    if (((selectedPawn != i) & (buttonClick == 0)) || (drawSelectedPawn == 1))
    {
      DrawSprite(pawn[i][0], pawnXPosition[i], pawnYPosition[i], i / 4, pawnDirection[i]);
    }
    else if (buttonClick == 1)
    {
        if(i == selectedPawn)
        {
          uint8_t boardY = (pawnYPosition[selectedPawn] / 16);
          uint8_t boardX = ((pawnXPosition[selectedPawn] - 64) / 16);

          if((boardY > 0) && (pawnBoardLocation[boardY - 1][boardX] == 8))
            continue;
            
          if((boardY > 1) && (pawnBoardLocation[boardY - 1][boardX] < 8) && (pawnBoardLocation[boardY - 2][boardX] == 8))
            continue;
        }

        DrawSprite(pawn[i][0], pawnXPosition[i], pawnYPosition[i], i / 4, pawnDirection[i]);
    }
  }




  arduboy.fillRect(0, 28, 16, 6);
  Text(257, 1, 29, BLACK);
  tinyfont.setCursor(11, 29);
  tinyfont.print(actionPoints[0]);
  arduboy.fillRect(45, 30, 16, 6);
  Text(257, 46, 31, BLACK);
  tinyfont.setCursor(56, 31);
  tinyfont.print(actionPoints[1]);
  Text(256, 26, 30, WHITE);
}
