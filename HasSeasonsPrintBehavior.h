#pragma once
#include<string>
#include"SeasonsPrintBehavior.h"



class HasSeasonsPrintBehavior : public SeasonsPrintBehavior {

public:

    void printSeasonsInfo(const std::string &name, int seasons) const override;

};