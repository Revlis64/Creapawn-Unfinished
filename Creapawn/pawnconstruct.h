#pragma once

const uint8_t speciesStats[32][5]
{
  //NULL
  /*VOIDISMAL*/{0, 1, 2, 2, 2},
  
  //SYNTH
  /*AUDIOUSE*/{1, 3, 0, 1, 3},
  /*BOLTNETIC*/{1, 1, 1, 3, 2},
  /*DRIBBY*/{1, 2, 2, 1, 2},
  /*LUMINAT*/{1, 3, 0, 2, 2},
  /*MICRUNT*/{1, 2, 2, 0, 3},
  /*ODRION*/{1, 2, 3, 2, 0},
  /*OUTLECTRIC*/{1, 3, 1, 0, 3},
  /*SLUGAMMA*/{1, 3, 3, 1, 0},
  /*SPYMERA*/{1, 1, 3, 0, 3},
  /*XENAUCER*/{1, 3, 2, 2, 0},

  //NATURE
  /*BEETHRONE*/{2, 0, 3, 2, 2},
  /*BUBBLUE*/{2, 3, 3, 0, 1},
  /*BUNNERINA*/{2, 2, 0, 2, 3},
  /*CHAMPANZON*/{2, 2, 1, 2, 2},
  /*CHLOROAR*/{2, 2, 2, 2, 1},
  /*CRIBBIT*/{2, 0, 3, 3, 1},
  /*DASHOUND*/{2, 2, 0, 3, 2},
  /*MAYHAM*/{2, 1, 3, 3, 0},
  /*NECRAWLER*/{2, 0, 1, 3, 3},
  /*TERRUPTION*/{2, 2, 2, 3, 0},

  //MYSTIC
  /*CHIVAMPERA*/{3, 3, 1, 1, 2},
  /*DUALDRA*/{3, 2, 1, 3, 1},
  /*FAEFLUFF*/{3, 0, 2, 2, 3},
  /*GRIFELIOS*/{3, 3, 0, 3, 1},
  /*MAUROAH*/{3, 2, 1, 1, 3},
  /*PEGSHIRE*/{3, 1, 1, 2, 3},
  /*POLTERROR*/{3, 3, 1, 3, 0},
  /*RAVUACK*/{3, 3, 2, 0, 2},
  /*SCARDRA*/{3, 1, 0, 3, 3},
  /*SQUEAMASK*/{3, 0, 3, 1, 3},

  //OMNI
    /*TRIKURN*/{4, 3, 2, 1, 1},
};

const uint8_t zodiacStats[13][4]
{
  /*NONE*/{0, 0, 0, 0},
  /*CAPRICORN*/{3, 0, 1, 3},
  /*AQUARIUS*/{3,  3, 0, 1},
  /*PISCES*/{2, 2, 1, 2},
  /*ARIES*/{2, 0, 3, 2},
  /*TAURUS*/{0, 3, 2, 2},
  /*GEMINI*/{1, 2, 2, 2},
  /*CANCER*/{1, 3, 2, 1},
  /*LEO*/{ 0, 3, 3, 1},
  /*VIRGO*/{3, 1, 1, 2},
  /*LIBRA*/{2, 2, 2, 1},
  /*SCORPIO*/{3, 0, 3, 1},
  /*SAGITTARIUS*/{2, 1, 2, 2}
};

void CreatePawnByte(uint8_t pawnNumber)
{
  pawn[pawnNumber][0] = ((random( 0, 32)) * 8) + (random(0, 8));
  pawn[pawnNumber][1] = ((random( 0, 15)) * 16) + 16;
}

void PawnStatConstruct(uint8_t pawnByte, uint8_t pawnByteTwo, uint8_t pawnNumber)
{
  for ( pawnByte = 0; pawnByte > 15; pawnByte-=16)
    ++zodiac[pawnNumber];
    if ( pawnNumber < 4 )
      for ( pawnByte; pawnByte > 0; --pawnByte)
        ++experience[pawnNumber];

  type[pawnNumber] = speciesStats[pawnByteTwo / 8][0];
  level[pawnNumber] = (pawnByteTwo % 8) + 1;
  if ((experience[pawnNumber] == 15) & (level[pawnNumber] == 8))
    ++level[pawnNumber];
  maxEnergy[pawnNumber] = ((level[pawnNumber] * (speciesStats[pawnByteTwo / 8][1] + zodiacStats[zodiac[pawnNumber]][0] + 4)) + 15) / 5;
  energy[pawnNumber] = maxEnergy[pawnNumber];
  power[pawnNumber] = ((level[pawnNumber] * (speciesStats[pawnByteTwo / 8][3] + zodiacStats[zodiac[pawnNumber]][2] + 4)) + 15) / 10;
  damageResistance[pawnNumber] = ((level[pawnNumber] * (speciesStats[pawnByteTwo / 8][2] + zodiacStats[zodiac[pawnNumber]][1] + 4)) + 15) / 10;
  /*quickness[pawnNumber] =((level[pawnNumber] * (speciesStats[pawnByteTwo / 8][4] + zodiacStats[zodiac[pawnNumber]][3] + 4)) + 15) / 10;*/
  actionCost[pawnNumber] = 5 - ((speciesStats[pawnByteTwo / 8][4] + zodiacStats[zodiac[pawnNumber]][3]) / 2);
}



void ClearEnemyPawnBytes(uint8_t pawnNumber)
{
  if ( pawnNumber > 3 )
  {
    pawn[pawnNumber][0] = 0;
    pawn[pawnNumber][1] = 0;
  }
}

void ClearPawnStats(uint8_t pawnNumber)
{
  type[pawnNumber] = 0;
  level[pawnNumber] = 0;
  zodiac[pawnNumber] = 0;
  maxEnergy[pawnNumber] = 0;
  energy[pawnNumber] = 0;
  actionCost[pawnNumber] = 0;
  power[pawnNumber] = 0;
  damageResistance[pawnNumber] = 0;
  if (pawnNumber < 4)
  {
    experience[pawnNumber] = 0;
    maxExperience[pawnNumber] = 0;
  }
}

void PawnConstruct()
{
  
  for (uint8_t a = 0; a < 4; ++a)
    for (uint8_t b = 0; b < 4; ++b)
      pawnBoardLocation[b][a] = 8; 

  for (uint8_t i = 0; i < 8; ++i)
  {
    ClearEnemyPawnBytes(i);
    ClearPawnStats(i);
    bool a = random (0, 2);
    uint8_t guaranteedPawn = (random (0, 4)) + 4;
    if (((i == guaranteedPawn) || (a == 1)) & (i > 3)) 
      CreatePawnByte(i);
    if (pawn[i][1] > 15)
      PawnStatConstruct( pawn[i][1], pawn[i][0], i);
    if (i < 4)
        {
          pawnXPosition[i] = 64;
          pawnYPosition[i] = i * 16;
          pawnDirection[i] = right;
          pawnBoardLocation[pawnXPosition[i] / 16][0] = i;
        } 
        else
        {
          pawnXPosition[i] = 112;
          pawnYPosition[i] = (i - 4) * 16;
          pawnDirection[i] = left;
          pawnBoardLocation[pawnXPosition[i] / 16][3] = i;
        }
  }
  
}
