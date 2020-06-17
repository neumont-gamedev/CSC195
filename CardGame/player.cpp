#include "player.h"

Card Player::DealCard()
{
	if (m_deck.GetCount() == 0)
	{
		m_deck.SetCards(m_cards);
		m_deck.Shuffle();
		m_cards.clear();
	}

	return m_deck.DealCard();
}
