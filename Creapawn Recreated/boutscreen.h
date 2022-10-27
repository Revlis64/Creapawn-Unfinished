#pragma once


//void DrawSprite(unint16_t bringSprite, uint8_t )
DrawPawn(uint16_t bringSprite, int16_t x, int16_t y, bool foreColor, uint8_t currentPawnDirection)
{
  bool backColor = foreColor ? 1 : 0;

  ardbitmap.drawBitmap(x, y, pawnSpriteBackground[bringSprite / 8], 16, 16, backColor, ALIGN_NONE, currentPawnDirection);
  ardbitmap.drawBitmap(x, y, pawnSprite[bringSprite / 8], 16, 16, foreColor, ALIGN_NONE, currentPawnDirection);
}

void DrawBoutScreen()
{
  uint8_t textBoxOrganizer = 0;
  uint8_t y = 0;
  for (uint8_t x = 0; x < 4; ++y)
  {
    if ((pawnByte[x][1] > 15) && (textBoxOrganizer < 8))
    {
      if (pawn[textBoxOrganizer].energy > 0)
        TextBox(0, (textBoxOrganizer * 7), 61, 6);
      bool textColor = (pawn[textBoxOrganizer].energy == 0) ? WHITE : BLACK;
      Text(pawnByte[textBoxOrganizer][0], 1, 1 + (37 * (textBoxOrganizer / 4)) + (textBoxOrganizer * 7), textColor);
      tinyfont.setCursor(51, 1 + (37 * (textBoxOrganizer / 4)) + (textBoxOrganizer * 7));
      if (pawn[textBoxOrganizer].energy < 10)
        tinyfont.print(F("0"));
      tinyfont.print(pawn[textBoxOrganizer].energy);
      ++textBoxOrganizer;
    }

    arduboy.fillRect((y * 16) + 64, x * 16, 16, 16, (x + y)%2);
    if ((y == 4) && (x != 4))
    {
      y = 0;
      ++x;
    }
  }

}

