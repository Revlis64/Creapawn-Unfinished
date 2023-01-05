#pragma once


//void DrawSprite(unint16_t bringSprite, uint8_t )
void DrawPawn(uint16_t bringSprite, int16_t x, int16_t y, bool foreColor, uint8_t currentPawnDirection)
{
  bool backColor = (foreColor == BLACK) ? WHITE : BLACK;

  ardbitmap.drawBitmap(x, y, pawnSpriteBackground[bringSprite / 8], 16, 16, backColor, ALIGN_NONE, currentPawnDirection);
  ardbitmap.drawBitmap(x, y, pawnSprite[bringSprite / 8], 16, 16, foreColor, ALIGN_NONE, currentPawnDirection);
}

void DrawBoutScreen()
{
  uint8_t textBoxOrganizer = 0;
  for (uint8_t i = 0; i < 8; ++i)
  {
    textBoxOrganizer = (i == 4) ? 4 : textBoxOrganizer;
    if ((pawnByte[i][1] > 15))
    {
      if (pawn[i].energy > 0)
        TextBox(0, ((textBoxOrganizer * 7) + (9 * (textBoxOrganizer / 4))), 61, 6);
      bool textColor = (pawn[i].energy == 0) ? WHITE : BLACK;
      Text(pawnByte[i][0], 1, 1 + (9 * (textBoxOrganizer / 4)) + (textBoxOrganizer * 7), textColor);
      tinyfont.setCursor(51, 1 + ((textBoxOrganizer * 7) + (9 * (textBoxOrganizer / 4))));
      if (pawn[i].energy < 10)
        tinyfont.print(F("0"));
      tinyfont.print(pawn[i].energy);
      ++textBoxOrganizer;
    }
  }
  uint8_t y = 0;
  for (uint8_t x = 0; x < 4; y)
  {
    arduboy.fillRect((y * 16) + 64, x * 16, 16, 16, (x + y)%2);
    ++y;
    if ((y == 4) && (x != 4))
    {
      y = 0;
      ++x;
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

