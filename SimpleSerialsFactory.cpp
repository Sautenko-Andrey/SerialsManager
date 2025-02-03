#include"SimpleSerialsFactory.h"
#include"Brassic.h"
#include"HIMYM.h"
#include"THM.h"
#include"ATJ.h"
#include"SiliconValley.h"
#include"BBT.h"
#include"PoorPeople.h"
#include"NewGirl.h"
#include"Interni.h"
#include<iostream>


std::shared_ptr<Serial> SimpleSerialsFactory::createSerial(
    AvailableSerials selected_serial,
    std::string &season,
    std::string &lang
)
{
    std::shared_ptr<Serial> serial{nullptr};

    switch (selected_serial)
    {
    case AvailableSerials::Brassic:
        serial = std::make_shared<Brassic>(season, lang);
        break;

    case AvailableSerials::HowIMetYourMother:
        serial = std::make_shared<HIMYM>(season, lang);
        break;

    case AvailableSerials::TwoAndAHalfMen:
        serial = std::make_shared<THM>(season, lang);
        break;

    case AvailableSerials::AccordingToJim:
        serial = std::make_shared<ATJ>(season, lang);
        break;

    case AvailableSerials::SiliconValley:
        serial = std::make_shared<SiliconValley>(season, lang);
        break;

    case AvailableSerials::BigBangTheory:
        serial = std::make_shared<BigBangTheory>(season, lang);
        break;

    case AvailableSerials::PoorPeople:
        serial = std::make_shared<PoorPeople>(season, lang);
        break;

    case AvailableSerials::NewGirl:
        serial = std::make_shared<NewGirl>(season, lang);
        break;

    case AvailableSerials::Interni:
        serial = std::make_shared<Interni>(season, lang);
        break;

    default:
        std::cout << "Error! Unknown serial requested\n"
                     "For help run this command: serials --help\n";
        std::exit(1);
    }

    return serial;
}