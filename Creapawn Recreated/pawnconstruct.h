const uint8_t speciesStats[32][5]
{
  // Type, Energy, Damage Resistance, Power, Action Cost
  //NULL
  /*VOIDISMAL*/{0, 0, 0, 0, 0},
  
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
  /*XENAUCER*/{1, 1, 2, 2, 2},

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

const uint8_t zodiacStats[16][4]
{
  // Energy, Damage Resistance, Power, Action Cost
  /*NONE*/{0, 0, 0, 0},
  /*NONE*/{0, 0, 0, 0},
  /*NONE*/{0, 0, 0, 0},
  /*SAGITTARIUS*/{2, 1, 2, 2},
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
  /*OPHIUCHUS*/{3, 2, 2, 0}
};

void CreatePawnByte(uint8_t pawnNumber)
{
  pawnByte[pawnNumber][0] = ((random( 0, 32)) * 8) + (random(0, 8));
  pawnByte[pawnNumber][1] = ((random( 0, 15)) * 16) + 16;
}

void PawnStatConstruct(uint8_t pawnByteTwo, uint8_t pawnByteThree, uint8_t pawnNumber)
{
  for (pawnByteThree = pawnByteThree; pawnByteThree > 15; pawnByteThree -= 16)
    ++pawn[pawnNumber].zodiac;
    if (pawnNumber < 4)
      for (pawnByteThree = pawnByteThree; pawnByteThree > 0; --pawnByteThree)
        ++pawn[pawnNumber].experience;

  pawn[pawnNumber].type = speciesStats[pawnByteTwo / 8][0];
  pawn[pawnNumber].level = (pawnByteTwo % 8) + 1;
  pawn[pawnNumber].level = ((pawn[pawnNumber].experience == 15) && (pawn[pawnNumber].level == 8)) ? ++pawn[pawnNumber].level : pawn[pawnNumber].level;
  pawn[pawnNumber].maxEnergy = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][1] + zodiacStats[pawn[pawnNumber].zodiac][0] + 4)) + 15) / 5;
  pawn[pawnNumber].energy = pawn[pawnNumber].maxEnergy;
  pawn[pawnNumber].damageResistance = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][2] + zodiacStats[pawn[pawnNumber].zodiac][1] + 4)) + 15) / 10;
  pawn[pawnNumber].power = ((pawn[pawnNumber].level * (speciesStats[pawnByteTwo / 8][3] + zodiacStats[pawn[pawnNumber].zodiac][2] + 4)) + 15) / 10;
  pawn[pawnNumber].actionCost = 5 - ((speciesStats[pawnByteTwo / 8][4] + zodiacStats[pawn[pawnNumber].zodiac][3]) / 2);
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
  pawn[pawnNumber].damageResistance = 0;
  pawn[pawnNumber].power = 0;
  pawn[pawnNumber].actionCost = 0;
  if (pawnNumber < 4)
  {
    pawn[pawnNumber].experience = 0;
    pawn[pawnNumber].maxExperience = 0;
  }
}

void PawnConstruct()
{
  
  for (uint8_t row = 0; row < 4; ++row)
    for (uint8_t colom = 0; colom < 4; ++colom)
      pawnBoardLocation[row][colom] = 8;

  for ( uint8_t i = 0; i < 8; ++i)
  {
    if (i > 3)
      ClearPawnBytes(i);
    ClearPawnStats(i);
    bool a = random (0, 2);
    uint8_t guaranteedPawn = (random  (0,4)) + 4;
    if (((i == guaranteedPawn) || (a == 1)) && (i > 3))
      CreatePawnByte(i);
    if (pawnByte[i][1] > 15)
      PawnStatConstruct( pawnByte[i][0], pawnByte[i][1], i);

      switch (i)
      {
        case 0 ... 3:
          pawn[i].facingDirection = Direction::Right;
          pawnBoardLocation[i][0] = i;
          break;
        case 4 ... 7:
          pawn[i].facingDirection = Direction::Left;
          pawnBoardLocation[i - 4][3] = i;
          break;
      }
  }
}
