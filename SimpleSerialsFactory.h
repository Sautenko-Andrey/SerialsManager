#pragma once
#include<memory>
#include<string>
#include"Serial.h"

enum class AvailableSerials{
    Brassic, HowIMetYourMother, TwoAndAHalfMen,
    BigBangTheory, AccordingToJim, SiliconValley,
    PoorPeople, NewGirl, Interni
};

class SimpleSerialsFactory {

public:

    std::unique_ptr<Serial> createSerial(
        AvailableSerials selected_serial,
        std::string &season,
        std::string &lang
    );
};