#pragma once
#include<memory>
#include<string>
#include"Serial.h"

enum class AvailableSerials{
    Brassic, HowIMetYourMother, TwoAndAHalfMen,
    BigBangTheory, AccordingToJim, SiliconValley,
    PoorPeople, NewGirl
};

class SimpleSerialsFactory {

public:

    std::shared_ptr<Serial> createSerial(
        AvailableSerials selected_serial,
        std::string &season,
        std::string &lang
    );
};