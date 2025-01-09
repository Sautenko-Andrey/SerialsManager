#include"HasSeasonsPrintBehavior.h"
#include<iostream>



void HasSeasonsPrintBehavior::printSeasonsInfo(const std::string &name, 
                                               int seasons) const
{
    std::cout << name << " has " << seasons << " season(s)\n";
}