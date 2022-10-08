#pragma once

/*void CompileTurnList()
{
  for (uint8_t pawnNumber = 0; pawnNumber < 8; ++pawnNumber)
  {
    uint8_t pawnQuickness = quickness[pawnNumber];
    for (uint8_t turnSlot = 0; turnSlot < 31; ++turnSlot)
    {
      if ((energy[pawnNumber] > 0) & (pawnQuickness > 0) & ((pawnQuickness > quickness[turnList[turnSlot]]) || ((turnSlot > 0) & (turnList[turnSlot - 1] == turnList[turnSlot]) & (pawnQuickness > (quickness[turnList[turnSlot]] / 2)))))
      {
        turnList[turnSlot + 1] = turnList[turnSlot];
        turnList[turnSlot] = pawnNumber;
        pawnQuickness = pawnQuickness / 2;
      }
    }
  }
}
*/

void BoutMovement()
{
  
}

void enemyDecision()
{
  for (uint8_t i = 0; i < 12; ++i)
  {
    
    switch (i)
    {
      case 0 ... 3:
        
        break;
      case 4 ... 7:

        break;
      case 8 ... 12:

        break;     
    }
  }
}

void EnemyMovement(uint8_t enemyDirection)
{
 switch (enemyDirection)
 {
  case left:
  
    break;
  case up:
  
    break;
  case down:
  
    break;
  ++turn;
 }
}

//void 
//void UpdateTurnList()

void Bout() 
{
 switch (turn)
 {
  case 0:
    switch (buttonClick)
    {
      case 0:
        if((arduboy.justPressed(UP_BUTTON)) & (selectedPawn > 0))
          for (int8_t i = selectedPawn - 1; i > -1; --i)
            if(energy[i] > 0)
            {
              selectedPawn = i;
              i = -1;
            }
        if((arduboy.justPressed(DOWN_BUTTON)) & (selectedPawn < 3))
          for (uint8_t i = selectedPawn + 1; i < 4; ++i)
            if(energy[i] > 0)
            {
              selectedPawn = i;
              i = 4;
            }
        if(arduboy.justPressed(A_BUTTON))
          buttonClick++;      
        break;   

  case 1:
    if(arduboy.justPressed(B_BUTTON))
      --buttonClick;
    break;
    
    }


    break;
  case 1:
    enemyDecision();
    break;
 }
}
