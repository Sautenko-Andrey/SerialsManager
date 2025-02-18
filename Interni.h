#pragma once
#include<string>
#include"Serial.h"


class Interni : public Serial {

public:

    Interni(std::string season, std::string lang);

    const std::string& who() const override;


private:

    inline static const std::string m_website_url{"https://baskino.se/10257-serial-interny-onlain-1-14-sezon-vse-serii.html"};

    inline static const std::string m_serial_full_name{"Interni"};
};