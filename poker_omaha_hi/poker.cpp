#include"poker.h"

int Poker::getPlayerHandRankin(Card** newHand, Card** newCommunityCards)
{
    int sizeCommunityCards = NUMBER_OF_VALID_COMMUNITY_HAND + NUMBER_OF_VALID_PLAYER_HAND;
    int firstCardUser = 0;
    int secondCardUser= 1;
    


    Card** combinationOfCards = new Card* [sizeCommunityCards];


    while (firstCardUser != NUMBER_OF_VALID_COMMUNITY_HAND)
    {

        combinationOfCards[0] = newHand[firstCardUser];
        combinationOfCards[1] = newHand[secondCardUser];

        communityCardCombinations(combinationOfCards, sizeCommunityCards);

    
        secondCardUser++;
        if (secondCardUser == SIZE_OF_PLAYER_DECK)
        {
            firstCardUser++;
            secondCardUser = firstCardUser + 1;
        }
    }

}

void Poker::communityCardCombinations(Card** combinationOfCards, int sizeCommunityCards, Card** newCommunityCards)
{
    int firstCardCommunity = 0;
    int secondCardCommunity = 1;
    int thirdCardCommunity = secondCardCommunity + 1;

    for (firstCardCommunity = 0; firstCardCommunity < NUMBER_OF_VALID_COMMUNITY_HAND; firstCardCommunity++)
    {
        secondCardCommunity = firstCardCommunity + 1;

        while (secondCardCommunity != SIZE_OF_PLAYER_DECK)
        {
            combinationOfCards[2] = newCommunityCards[firstCardCommunity];
            combinationOfCards[3] = newCommunityCards[secondCardCommunity];
            combinationOfCards[4] = newCommunityCards[thirdCardCommunity];




            thirdCardCommunity++;
            if (thirdCardCommunity == sizeCommunityCards)
            {
                secondCardCommunity++;
                thirdCardCommunity = secondCardCommunity + 1;
            }


        }

    }
}
