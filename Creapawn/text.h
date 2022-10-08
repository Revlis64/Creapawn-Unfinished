#pragma once

void TextBox(uint8_t x, uint8_t y,uint8_t w, uint8_t l)
{
  arduboy.fillRoundRect(x, y, w, l, WHITE);
}



void Text(uint16_t bringText, uint8_t x, uint8_t y, bool textColor) 
{
  tinyfont.setTextColor(textColor);

  tinyfont.setCursor( x, y);
  switch (bringText)
  {

// NULL //
    case 0 ... 7:
      tinyfont.print(F("VOIDISMAL"));
      break;

// SYNTH //
    case 8 ... 15:
      tinyfont.print(F("AUDIOUSE"));
      break;
    case 16 ... 23:
      tinyfont.print(F("BOLTNETIC"));
      break;
    case 24 ... 31:
      tinyfont.print(F("DRIBBY"));
      break;
    case 32 ... 39:
      tinyfont.print(F("LUMINAT"));
      break;
    case 40 ... 47:
      tinyfont.print(F("MICRUNT"));
      break;
    case 48 ... 55:
      tinyfont.print(F("ODRION"));
      break;
    case 56 ... 63:
      tinyfont.print(F("OUTLECTRIC"));
      break;
    case 64 ... 71:
      tinyfont.print(F("SLUGAMMA"));
      break;
    case 72 ... 79:
      tinyfont.print(F("SPYMERA"));
      break;
    case 80 ... 87:
      tinyfont.print(F("XENAUCER"));
      break;

// NATURE //      
    case 88 ... 95:
      tinyfont.print(F("BEETHRONE"));
      break;
    case 96 ... 103:
      tinyfont.print(F("BUBBLUE"));
      break;
    case 104 ... 111:
      tinyfont.print(F("BUNNERINA"));
      break;
    case 112 ... 119:
      tinyfont.print(F("CHAMPANZON"));
      break;
    case 120 ... 127:
      tinyfont.print(F("CHLOROAR"));
      break;
    case 128 ... 135:
      tinyfont.print(F("CRIBBIT"));
      break;
    case 136 ... 143:
      tinyfont.print(F("DASHOUND"));
      break;
    case 144 ... 151:
      tinyfont.print(F("MAYHAM"));
      break;
    case 152 ... 159:
      tinyfont.print(F("NECRAWLER"));
      break;
    case 160 ... 167:
      tinyfont.print(F("TERRUPTION"));
      break;

// MYSTIC //
    case 168 ... 175:
      tinyfont.print(F("CHIVAMPERA"));
      break;
    case 176 ... 183:
      tinyfont.print(F("DUALDRA"));
      break;
    case 184 ... 191:
      tinyfont.print(F("FAEFLUFF"));
      break;
    case 192 ... 199:
      tinyfont.print(F("GRIFELIOS"));
      break;
    case 200 ... 207:
      tinyfont.print(F("MAUROAH"));
      break;
    case 208 ... 215:
      tinyfont.print(F("PEGSHIRE"));
      break;
    case 216 ... 223:
      tinyfont.print(F("POLTERROR"));
      break;
    case 224 ... 231:
      tinyfont.print(F("RAVUACK"));
      break;
    case 232 ... 239:
      tinyfont.print(F("SCARDRA"));
      break;
    case 240 ... 247:
      tinyfont.print(F("SQUEAMASK"));
      break;

// OMNI //
    case 248 ... 255:
      tinyfont.print(F("TRIKURN"));
      break;

    case 256:
      tinyfont.print(F("VS"));
      break;
      
    case 257:
      tinyfont.print(F("AP"));
      break;
  }
}
