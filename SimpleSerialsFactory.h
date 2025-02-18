#pragma once
#include<memory>
#include<string>
#include"Serial.h"


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

enum class AvailableSerials{
    Brassic, HowIMetYourMother, TwoAndAHalfMen,
    BigBangTheory, AccordingToJim, SiliconValley,
    PoorPeople, NewGirl, Interni, None
};

class SimpleSerialsFactory {

public:

    template<typename T>
    std::unique_ptr<Serial> createSerial(
        AvailableSerials selected_serial,
        T &&season,
        T &&lang
    );
    
};


template<typename T>
    std::unique_ptr<Serial> SimpleSerialsFactory::createSerial(
        AvailableSerials selected_serial,
        T &&season,
        T &&lang
    )
    {
    
        switch (selected_serial)
        {
        case AvailableSerials::Brassic:
            return std::make_unique<Brassic>(
                std::forward<T>(season),
                std::forward<T>(lang));   //NRVO — Named Return Value Optimization
            break;
    
        case AvailableSerials::HowIMetYourMother:
            return std::make_unique<HIMYM>(
                std::forward<T>(season),
                std::forward<T>(lang));
            break;
    
        case AvailableSerials::TwoAndAHalfMen:
            return std::make_unique<THM>(
                std::forward<T>(season),
                std::forward<T>(lang));
            break;
    
        case AvailableSerials::AccordingToJim:
            return std::make_unique<ATJ>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        case AvailableSerials::SiliconValley:
            return std::make_unique<SiliconValley>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        case AvailableSerials::BigBangTheory:
            return std::make_unique<BigBangTheory>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        case AvailableSerials::PoorPeople:
            return std::make_unique<PoorPeople>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        case AvailableSerials::NewGirl:
            return std::make_unique<NewGirl>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        case AvailableSerials::Interni:
            return std::make_unique<Interni>(
                std::forward<T>(season),
                std::forward<T>(lang)
            );
            break;
    
        default:
            std::cout << "Error! Unknown serial requested\n"
                         "For help run this command: serials --help\n";
            std::exit(1);
        }
       
    }