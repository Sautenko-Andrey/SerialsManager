#pragma once
#include<memory>
#include"SimpleSerialsFactory.h"
#include"Serial.h"

class SerialsStore {

public:

    SerialsStore(const std::shared_ptr<SimpleSerialsFactory> factory)
    : m_factory{factory}{}

    std::shared_ptr<Serial> createSerial(AvailableSerials selected_serial, 
                                       std::string &season,
                                       std::string &lang){

        std::shared_ptr<Serial> serial{nullptr};

        serial = m_factory->createSerial(selected_serial, season, lang);

        return serial;
    }


private:
    std::shared_ptr<SimpleSerialsFactory> m_factory{nullptr};
};