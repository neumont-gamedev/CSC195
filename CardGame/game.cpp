#include "game.h"
using namespace std;

void Game::StartGame()
{
	m_deck.Shuffle();

	// split deck
	cards_t cards = m_deck.m_cards;

	std::size_t const half_size = cards.size() / 2;
	cards_t split_lo(cards.begin(), cards.begin() + half_size);
	cards_t split_hi(cards.begin() + half_size, cards.end());

	// give each player half
	m_players[0].SetDeck(Deck{ split_lo });
	m_players[1].SetDeck(Deck{ split_hi });

	m_round = 1;
}

void Game::StartRound()
{
	system("cls"); // clear the console

	std::cout << "Round: " << m_round << std::endl;

	cards_t cards;
	int winner = -1;
	while (winner == -1 && !m_gameOver)
	{
		// make sure players have cards
		for (size_t i = 0; i < m_players.size(); i++)
		{
			if (m_players[i].HasCards() == false)
			{
				m_gameOver = true;
			}
		}

		if (m_gameOver) continue;

		cards.push_front(m_players[1].DealCard()); // cards = p2card
		cards.push_front(m_players[0].DealCard()); // cards = p1card, p2card

		cout << m_players[0] << " " << cards[0] << endl;
		cout << m_players[1] << " " << cards[1] << endl;

		if (cards[0] == cards[1]) // war
		{
			// make sure players have cards
			for (size_t i = 0; i < m_players.size(); i++)
			{
				if (m_players[i].HasCards() == false)
				{
					m_gameOver = true;
				}
			}

			if (!m_gameOver)
			{
				cout << "!!! War !!!\n\n";
				cards.push_back(m_players[0].DealCard());
				cards.push_back(m_players[1].DealCard());
			}
		}
		if (cards[0] > cards[1]) // 0 = player 1 | 1 = player 2
		{
			winner = 0; // 0 = player 1
		}
		else if (cards[1] > cards[0])
		{
			winner = 1; // 1 = player 2
		}
	}

	if (winner != -1)
	{
		// show winner
		cout << m_players[winner] << " Won!!!\n";

		// add cards to winner
		for (size_t i = 0; i < cards.size(); i++)
		{
			m_players[winner].AddCard(cards[i]);
		}
	}

	// show player winning card count
	for (size_t i = 0; i < m_players.size(); i++)
	{
		cout << m_players[i] << " deck: " << m_players[i].GetDeck().GetCount() << " cards: " << m_players[i].GetCardCount() << endl;
	}

	// check for game over
	for (size_t i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].HasCards() == false)
		{
			m_gameOver = true;
		}
	}

	cout << "\n\npress enter to continue...";
	//cin.ignore();
	m_round++;
}

