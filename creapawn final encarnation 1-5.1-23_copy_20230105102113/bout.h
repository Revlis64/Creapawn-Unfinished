void Bout() 
{
 switch (turn)
 {
  case 0:
    switch (buttonClick)
    {
      case 0:
        if(arduboy.justPressed(UP_BUTTON))
        {
          if (selectedPawn > 0)
          {
            for (int8_t i = --selectedPawn; i > 0; --i)
              if(pawn[i].energy > 0)
              {
                selectedPawn = i;
                i = 0;
              }
          }
        }
        if(arduboy.justPressed(DOWN_BUTTON))
        {
          if (selectedPawn < 2)
          {
            for (uint8_t i = ++selectedPawn; i < 2; ++i)
              if(pawn[i].energy > 0)
              {
                selectedPawn = i;
                i = 2;
              }
          }
        }
        if(arduboy.justPressed(LEFT_BUTTON) && selectedMove > 0)
          --selectedMove;
        if(arduboy.justPressed(RIGHT_BUTTON) && selectedMove < 3)
          ++selectedMove;
        if (selectedMove == 2)
          SpecialAttackCostFinder(pawn[selectedPawn].specialAttack);
          else if (selectedMove == 1)
            specialAttackCost = 2; 
            else specialAttackCost = 0;
        if((arduboy.justPressed(A_BUTTON)) && ((pawn[selectedPawn].actionCost + (specialAttackCost)) <= actionPoints[0]))
        {
          selectedSpotX = selectedPawnX;
          selectedSpotY = selectedPawnY; 
          directionHolder = 2;    
          buttonClick++;  
        }    
        break;   

  case 1:

      PlayerMoveSelection();
    if(arduboy.justPressed(B_BUTTON))
    {
      pawn[selectedPawn].facingDirection = (directionHolder != 2) ? directionHolder : pawn[selectedPawn].facingDirection;
      --buttonClick;      
    }
    break;
    
    }


    break;
  case 1:
    //enemyDecision();
    break;
 }
}