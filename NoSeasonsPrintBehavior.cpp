#include"NoSeasonsPrintBehavior.h"
#include<iostream>


void NoSeasonsPrintBehavior::printSeasonsInfo(const std::string &name,
                                              int seasons) const
{
    std::cout << name
              << " has "
              << seasons
              << " season(s), but this serial object doesn't support switching"
                 " between them.\n";
}