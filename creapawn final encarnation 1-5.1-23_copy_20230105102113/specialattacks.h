#pragma once

         void HitBlastStrike()
         {
            uint8_t directionSelector = (selectedPawnX < selectedSpotX) ? 0 : 1;
            pawn[selectedPawn].facingDirection = ((selectedSpotY == selectedPawnY) && (selectedSpotX != selectedPawnX)) ? directionSelector : pawn[selectedPawn].facingDirection;
            bool damageMultiplier = (pawn[selectedPawn].specialAttack == 4) ? 1 : 0;
            if ((pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].energy - (pawn[selectedPawn].power * (damageMultiplier + 1))) <= 0)
            pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].energy = 0;  
            else pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].energy -= pawn[selectedPawn].power * (damageMultiplier + 1);
          --buttonClick;
         }

         void SpecialAttacks()
         {
          switch (pawn[selectedPawn].specialAttack)
           {
             case 0:
             {
               if (selectedSpotY == selectedPawnY)
                 pawn[selectedPawn].facingDirection = ((selectedPawnX - selectedSpotX) + 1) / 2;
               uint8_t pawnHolder = pawnBoardLocation[selectedSpotY][selectedSpotX];
               pawnBoardLocation[selectedSpotY][selectedSpotX] = pawnBoardLocation[selectedPawnY][selectedPawnX];
               pawnBoardLocation[selectedPawnY][selectedPawnX] = pawnHolder;
             }
               break;
             case 1:
               for (uint8_t i = 3; i < 6; ++i)
            if ((pawn[i].energy - (((pawn[selectedPawn].power) / 3) + 1)) <= 0)
              pawn[i].energy = 0;  
              else pawn[i].energy -= ((pawn[selectedPawn].power) / 3) + 1;
              break;
              case 2:
                if (selectedSpotY == selectedPawnY)
                  pawn[selectedPawn].facingDirection = ((selectedPawnX - selectedSpotX) + 1) / 2;
                  pawn[pawnBoardLocation[selectedSpotY][selectedSpotX]].energy = 0;  
                  pawn[selectedPawn].energy = 0;
              break;
              case 3 ... 4:
                HitBlastStrike();            
                break;
              case 6:
                endureAttack = selectedPawn;
                break;
              case 9:
               for (uint8_t i = 0; i < 3; ++i)
                 if ((pawn[i].energy + (((pawn[i].power) / 2) + 1)) >= pawn[i].maxEnergy)
                 pawn[i].energy = pawn[i].maxEnergy;  
                 else pawn[i].energy += ((pawn[selectedPawn].power) / 2) + 1;
                break;                
           }           
         }
