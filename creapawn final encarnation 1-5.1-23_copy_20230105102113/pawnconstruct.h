const uint8_t speciesStats[32][4]
{
  // Type, Energy, Power, Action Cost
  //NULL
  /*VOIDISMAL*/{0, 0, 0, 0},
  
  //SYNTH
  /*AUDIOUSE*/{1, 2, 0, 2},
  /*BOLTNETIC*/{1, 1, 2, 1},
  /*DRIBBY*/{1, 2, 1, 1},
  /*LUMINAT*/{1, 3, 0, 1},
  /*MICRUNT*/{1, 1, 0, 3},
  /*ODRION*/{1, 1, 3, 0},
  /*OUTLECTRIC*/{1, 0, 1, 3},
  /*SLUGAMMA*/{1, 3, 1, 0},
  /*SPYMERA*/{1, 0, 2, 2},
  /*XENAUCER*/{1, 0, 3, 1},

  //NATURE
  /*BEETHRONE*/{2, 0, 2, 2},
  /*BUBBLUE*/{2, 2, 2, 0,},
  /*BUNNERINA*/{2, 1, 0, 3},
  /*CHAMPANZON*/{2, 1, 2, 1},
  /*CHLOROAR*/{2, 1, 1, 2},
  /*CRIBBIT*/{2, 3, 1, 0},
  /*DASHOUND*/{2, 2, 1, 1},
  /*MAYHAM*/{2, 1, 3, 0},
  /*NECRAWLER*/{2, 0, 1, 3},
  /*TERRUPTION*/{2, 0, 3, 1},

  //MYSTIC
  /*CHIVAMPERA*/{3, 2, 0, 2},
  /*DUALDRA*/{3, 1, 1, 2},
  /*FAEFLUFF*/{3, 2, 0, 2},
  /*GRIFELIOS*/{3, 2, 2, 0},
  /*MAUROAH*/{3, 3, 1, 0},
  /*PEGSHIRE*/{3, 1, 1, 2},
  /*POLTERROR*/{3, 1, 3, 0},
  /*RAVUACK*/{3, 0, 1, 3},
  /*SCARDRA*/{3, 0, 3, 1},
  /*SQUEAMASK*/{3, 3, 0, 1},

  //OMNI
    /*TRIKURN*/{4, 2, 1, 1},
};

const uint8_t zodiacStats[15][3]
{
  // Energy, Power, Action Cost
  /*NONE*/{0, 0, 0},
  /*NONE*/{0, 0, 0},
  /*NONE*/{0, 0, 0},
  /*CAPRICORN*/{1, 0, 3},
  /*AQUARIUS*/{2, 1, 1},
  /*PISCES*/{1, 1, 2},
  /*ARIES*/{1, 3, 0},
  /*TAURUS*/{0, 3, 1},
  /*GEMINI*/{1, 2, 1},
  /*CANCER*/{2, 2, 0},
  /*LEO*/{0, 2, 2},
  /*VIRGO*/{0, 1, 3},
  /*LIBRA*/{3, 0, 1},
  /*SCORPIO*/{3, 1, 0},
  /*SAGITTARIUS*/{2, 0, 2},
  /*OPHIUCHUS*//*{3, 2, 2, 0}*/
};

void CreatePawnByte(uint8_t pawnNumber)
{
  pawnByte[pawnNumber][0] = ((random( 0, 32)) * 8) + (random(0, 8));
  uint8_t zodiacGranter = (pawnByte[pawnNumber][0] < 8) ? 16 : 32;
  pawnByte[pawnNumber][1] = ((random( 0, 14)) * 16) + zodiacGranter;
  pawnByte[pawnNumber][1] = (pawnNumber > 2) ? (pawnByte[pawnNumber][1] += (random(0, 16))) : pawnByte[pawnNumber][1];
}

void PawnStatConstruct(uint8_t pawnByteTwo, uint8_t pawnByteThree, uint8_t pawnNumber)
{
  for (pawnByteThree; pawnByteThree > 15; pawnByteThree -= 16)
    ++pawn[pawnNumber].zodiac;
    if (pawnNumber < 3)
      for (pawnByteThree; pawnByteThree > 0; --pawnByteThree)
        ++pawn[pawnNumber].experience;

  pawn[pawnNumber].type = speciesStats[pawnByteTwo / 8][0];
  pawn[pawnNumber].level = (pawnByteTwo % 8) + 1;
  pawn[pawnNumber].level = ((pawn[pawnNumber].experience == 15) && (pawn[pawnNumber].level == 8)) ? ++pawn[pawnNumber].level : pawn[pawnNumber].level;
  pawn[pawnNumber].maxEnergy = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][1] + zodiacStats[pawn[pawnNumber].zodiac][0] + 4)) + 15) / 5;
  pawn[pawnNumber].energy = pawn[pawnNumber].maxEnergy;
  //pawn[pawnNumber].damageResistance = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][2] + zodiacStats[pawn[pawnNumber].zodiac][1] + 4)) + 15) / 10;
  pawn[pawnNumber].power = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][2] + zodiacStats[pawn[pawnNumber].zodiac][1] + 4)) + 15) / 10;
  if (pawnNumber < 3) 
  {
    pawn[pawnNumber].actionCost = 5 - ((speciesStats[pawnByteTwo / 8][3] + zodiacStats[pawn[pawnNumber].zodiac][2]) / 2);
    if (pawn[pawnNumber].type < 4)
      pawn[pawnNumber].specialAttack = ((pawnByte[pawnNumber][0] < 8) ? 0 : ((pawn[pawnNumber].zodiac + 1) / 4) * pawn[pawnNumber].type);
        else pawn[pawnNumber].specialAttack = (random( 0, 4)) * (random( 0, 4));
  } else if (pawnNumber > 2)
  {
  pawn[pawnNumber].actionCost = 2 + ((9 - (speciesStats[pawnByteTwo / 8][3] + zodiacStats[pawn[pawnNumber].zodiac][2])) / 6);   
    //if (pawn[pawnNumber].type < 4)
      //pawn[pawnNumber].specialAttack = 4;//(random( 0, (++pawn[pawnNumber].type)))^2;
      //else pawn[pawnNumber].specialAttack = (random( 0, 4))^2;
  }
}
  

void ClearPawnBytes(uint8_t pawnNumber)
{
  pawnByte[pawnNumber][0] = 0;
  pawnByte[pawnNumber][1] = 0;
}

void ClearPawnStats(uint8_t pawnNumber)
{
  pawn[pawnNumber].type = 0;
  pawn[pawnNumber].level = 0;
  pawn[pawnNumber].zodiac = 0;
  pawn[pawnNumber].maxEnergy = 0;
  pawn[pawnNumber].energy = 0;
  //pawn[pawnNumber].damageResistance = 0;
  pawn[pawnNumber].power = 0;
  pawn[pawnNumber].actionCost = 0;
  if (pawnNumber < 3)
  {
    pawn[pawnNumber].experience = 0;
    pawn[pawnNumber].maxExperience = 0;
  }
}

void PawnConstruct()
{
  uint8_t guaranteedPawn = (random  (0, 3)) + 3;
  for (uint8_t x = 0; x < 4; ++x)
    for (uint8_t y = 0; y < 4; ++y)
      pawnBoardLocation[y][x] = 6;

  for ( uint8_t i = 0; i < 6; ++i)
  {
    if (i > 2)
      ClearPawnBytes(i);
    ClearPawnStats(i);
    bool a = random (0, 2);
    if (((i == guaranteedPawn) || (a == 1)) && (i > 2))
      CreatePawnByte(i);
    if (pawnByte[i][1] > 15)
      PawnStatConstruct( pawnByte[i][0], pawnByte[i][1], i);

      switch (i)
      {
        case 0 ... 2:
        if (pawnByte[i][1] > 15)
        {
          pawn[i].facingDirection = 0;
          pawnBoardLocation[i][0] = i;
        }
          break;
        case 3 ... 5:
        if (pawnByte[i][1] > 15)
        {
          pawn[i].facingDirection = 1;
          pawnBoardLocation[(i - 3)+1][3] = i;
        }
          break;
      }
  }
}
