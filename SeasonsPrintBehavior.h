#pragma once
#include<string>


class SeasonsPrintBehavior {

public:

    virtual ~SeasonsPrintBehavior() = default;

    virtual void printSeasonsInfo(const std::string &name, int seasons) const = 0;

};