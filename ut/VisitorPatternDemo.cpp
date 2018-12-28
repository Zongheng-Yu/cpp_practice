#include <gtest/gtest.h>

#include <tuple>
#include <vector>
#include <iostream>

namespace MyGame{
class Knight;
class Wizard;

/* Base class for the operation that want to performs on the Player's derived
 * classes. Each overloaded virtual function is for each Player's derived class.
 * In this example, we need to performs hit action in Knight and Wizard class
 * so there are two virtual functions are needed. The IAttack interface is
 * Visitor interface in Visitor Pattern */
class IAttack {
public:
    /* According to Player class, how many damage output when attacks.*/
    virtual int hit(Knight&) const = 0;
    virtual int hit(Wizard&) const = 0;
    virtual ~IAttack() = default;
};

/* Player class is Element class in Visitor Pattern.
 * The virtual function attack is accept function in Visitor Pattern. Through
 * attack function, client code can call the desired visitor (in this example
 * is class derived from IAttack: PhysicAttack or MagicAttack )
 * The other operation is used for describe the Player character statistic.  */
class Player{
public:
    Player(int HP, int MP, int level) : HP{HP}, MP{MP}, level{level}{ };
    int getLevel() const {return level;}
    int getHP() const {return HP;}
    int getMP() const {return MP;}

    /* Call the IAttack::hit function to get damage done to the opponent.*/
    virtual int attack(const IAttack &op) = 0;

    /* When get attack, lost corresponding HP*/
    virtual int lostHP(int hit) = 0;

    /* When casting a magic, cost corresponding MP*/
    virtual int lostMP(int mana) = 0;
    virtual ~Player() = default;
    /* To simplify the program magic attack cost constant MP*/
    constexpr static int magicCost = 10;
protected:
    int HP{}; // Hit Point.
    int MP{}; // Mana Point
    int level{}; // Character Level
};

class Knight : public Player{
public:
    Knight(int HP, int MP, int level) : Player{HP, MP, level} { };

    virtual int attack(const IAttack &op) override
    {
        return op.hit(*this);
    }
    virtual int lostHP(int hit) override
    {
        return HP -= hit * 0.8;
    }
    virtual int lostMP(int mana) override
    {
        return MP -= mana;
    }
    virtual ~Knight() = default;
};

class Wizard : public Player{
public:
    Wizard(int HP, int MP, int level) : Player{HP, MP, level} { };
    virtual int attack(const IAttack &op) override
    {
        return op.hit(*this);
    }
    virtual int lostHP(int hit) override
    {
        return HP -= hit;
    }
    virtual int lostMP(int mana) override
    {
        return MP -= mana * 0.5;
    }
};

class PhysicAttack : public IAttack {
public:
    virtual int hit(Knight &player) const override
    {
        return player.getLevel() + 30;
    }

    virtual int hit(Wizard &player) const override
    {
        return player.getLevel() + 15;
    }

    virtual ~PhysicAttack() = default;
};

class MagicAttack : public IAttack {
public:
    virtual int hit(Knight &player) const override
    {
        if (player.getMP() > Player::magicCost)
        {
            player.lostMP(Player::magicCost);
            return player.getLevel() + 10;
        } else {
            return 0;
        }
    }

    virtual int hit(Wizard &player) const override
    {
        if (player.getMP() > Player::magicCost)
        {
            player.lostMP(Player::magicCost);
            return player.getLevel() + 40  + Player::magicCost;
        } else {
            return 0;
        }
    }
    virtual ~MagicAttack() = default;
};
constexpr int ATTACKER = 0;
constexpr int ATTACK = 1;
constexpr int VICTIM  = 2;

using Round = std::tuple<Player&, IAttack&, Player&>;
using Game = std::vector<Round>;

/* Implements game, in each round the victim will lost HP according to the damage
 * output that attacker caused when he is attacking. The check of whether the attacker
 * and victim are the same player isn¡¯t required.*/
void playGames(const Game& game)
{
    for (auto& round: game)
    {
        auto& attacker = std::get<ATTACKER>(round);
        auto& attack = std::get<ATTACK>(round);
        auto& victim = std::get<VICTIM>(round);
        victim.lostHP(attacker.attack(attack));
    }
}
};// namespace MyGame

namespace{
class VisitorPatternTest: public ::testing::Test
{
protected:
    MyGame::PhysicAttack physicAttack{};
    MyGame::MagicAttack magicAttack{};
};

TEST_F(VisitorPatternTest, KnightPhysicAttackWizard)
{
    MyGame::Wizard wizard{100, 100, 10};
    MyGame::Knight knight{100, 100, 10};
    MyGame::Game game{{knight, physicAttack, wizard}};
    MyGame::playGames(game);
    EXPECT_EQ(60, wizard.getHP());
}

TEST_F(VisitorPatternTest, WizardPhysicAttackKnight)
{
    MyGame::Wizard wizard{100, 100, 10};
    MyGame::Knight knight{100, 100, 10};
    MyGame::Game game{{wizard, physicAttack, knight}};
    MyGame::playGames(game);
    EXPECT_EQ(80, knight.getHP());
}

TEST_F(VisitorPatternTest, KnightMagicAttackWizard)
{
    MyGame::Wizard wizard{100, 100, 10};
    MyGame::Knight knight{100, 100, 10};
    MyGame::Game game{{knight, magicAttack, wizard}};
    MyGame::playGames(game);
    EXPECT_EQ(80, wizard.getHP());
    EXPECT_EQ(90, knight.getMP());
}

TEST_F(VisitorPatternTest, WizardMagicAttackKnight)
{
    MyGame::Wizard wizard{100, 100, 10};
    MyGame::Knight knight{100, 100, 10};
    MyGame::Game game{{wizard, magicAttack, knight}};
    MyGame::playGames(game);
    EXPECT_EQ(52, knight.getHP());
    EXPECT_EQ(95, wizard.getMP());
}}


