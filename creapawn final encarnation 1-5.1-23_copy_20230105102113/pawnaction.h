#pragma once

void PlayerMoveSelection()
{
       if ((pawn[selectedPawn].specialAttack == 1) || (pawn[selectedPawn].specialAttack == 6) || (pawn[selectedPawn].specialAttack == 9))
         SpecialAttacks();
         else {         
    directionHolder = ((selectedSpotX == selectedPawnX) && directionHolder == 2) ? pawn[selectedPawn].facingDirection : directionHolder;
    if ((arduboy.justPressed(UP_BUTTON)) && (selectedSpotY > 0))
      --selectedSpotY;
      else if ((arduboy.justPressed(DOWN_BUTTON)) && (selectedSpotY < 3))
        ++selectedSpotY;
        else if ((arduboy.justPressed(LEFT_BUTTON)) && (selectedSpotX > 0))
          --selectedSpotX;
          else if ((arduboy.justPressed(RIGHT_BUTTON)) && (selectedSpotX < 3))
            ++selectedSpotX;
    uint8_t directionSelector = (selectedPawnX < selectedSpotX) ? 0 : 1;
    pawn[selectedPawn].facingDirection = ((selectedSpotY == selectedPawnY) && (selectedSpotX != selectedPawnX)) ? directionSelector : pawn[selectedPawn].facingDirection;
       }
    if(arduboy.justPressed(A_BUTTON))
    {
      if (((((selectedPawnY - selectedSpotY) == 1) && (selectedPawnX == selectedSpotX))
       || (((selectedPawnY - selectedSpotY) == -1) && (selectedPawnX == selectedSpotX))
       || (((selectedPawnX - selectedSpotX) == 1) && (selectedPawnY == selectedSpotY))
       || (((selectedPawnX - selectedSpotX) == -1) && (selectedPawnY == selectedSpotY)))
       || (pawn[selectedPawn].specialAttack == 3))       
      {  
       switch (selectedMove)
       {       
         case 0:
         if (pawnBoardLocation[selectedSpotY][selectedSpotX] == 6)
         {
          if (selectedSpotY == selectedPawnY)
            pawn[selectedPawn].facingDirection = ((selectedPawnX - selectedSpotX) + 1) / 2;
            //uint8_t pawnHolder = pawnBoardLocation[selectedSpotY][selectedSpotX];
            pawnBoardLocation[selectedSpotY][selectedSpotX] = pawnBoardLocation[selectedPawnY][selectedPawnX];
            pawnBoardLocation[selectedPawnY][selectedPawnX] = 6; /*pawnHolder;*/
            actionPoints[0] -= pawn[selectedPawn].actionCost;  
            --buttonClick;
         }
          break;
          case 1:
         if (pawnBoardLocation[selectedSpotY][selectedSpotX] < 6)
          HitBlastStrike();
          actionPoints[0] -= (pawn[selectedPawn].actionCost + 2);             
          break;

        case 2:
          SpecialAttacks();
          SpecialAttackCostFinder(pawn[selectedPawn].specialAttack);
          actionPoints[0] -=  (pawn[selectedPawn].actionCost + specialAttackCost);
          --buttonClick;
          break; 

        case 3:
          turn = 1;
          break;        
       }
                    
      }      
    }
}