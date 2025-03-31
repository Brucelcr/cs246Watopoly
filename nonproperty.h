#ifndef NONPROPERTY_H
#define NONPROPERTY_H

#include "square.h"
#include "player.h"
#include <string>
#include <memory>

class NonProperty : public Square {
public:
    NonProperty(const std::string& name, int position);
    virtual ~NonProperty() = default;

    virtual void landOn(Player& player) = 0;
    virtual void passBy(Player& player);

protected:
    int position;
};

// Specific non-property types
class CollectOSAP : public NonProperty {
public:
    CollectOSAP(int position);
    void landOn(Player& player) override;
};

class Tuition : public NonProperty {
public:
    Tuition(int position);
    void landOn(Player& player) override;
};

class GoToTims : public NonProperty {
public:
    GoToTims(int position);
    void landOn(Player& player) override;
};

class DC_Tims_Line : public NonProperty {
public:
    DC_Tims_Line(int position);
    void landOn(Player& player) override;
};

class GooseNesting : public NonProperty {
public:
    GooseNesting(int position);
    void landOn(Player& player) override;
};

class CoopFee : public NonProperty {
public:
    CoopFee(int position);
    void landOn(Player& player) override;
};

class SLC : public NonProperty {
public:
    SLC(int position);
    void landOn(Player& player) override;
};

class NeedlesHall : public NonProperty {
public:
    NeedlesHall(int position);
    void landOn(Player& player) override;
};

#endif