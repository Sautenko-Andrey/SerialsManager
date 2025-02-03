#pragma once
#include<memory>
#include"SimpleSerialsFactory.h"
#include"Serial.h"

class SerialsStore {

public:

    explicit SerialsStore(std::unique_ptr<SimpleSerialsFactory> &&factory)
    : m_factory{std::move(factory)}{}


    std::unique_ptr<Serial> createSerial(AvailableSerials selected_serial, 
                                       std::string &season,
                                       std::string &lang){

        std::unique_ptr<Serial> serial{nullptr};

        serial = m_factory->createSerial(selected_serial, season, lang);

        return std::move(serial);
    }


private:
    
    std::unique_ptr<SimpleSerialsFactory> m_factory{nullptr};
};