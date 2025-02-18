#include"Serial.h"
#include<iostream>


// Constructor
Serial::Serial(std::string season, std::string voice)
:
m_season{std::move(season)},
m_voice{std::move(voice)}
{}


// Methods

void Serial::openSerial(std::string &season, 
                    std::string &voice)
{
    // Set up voice
    (voice == "russian" || voice == "") ? voice = m_voice_url_rus
                                        : voice = m_voice_url_eng;

    if(!season.empty() && season[0] == '-'){
        // Remove one character starting at position 0
        season.erase(0, 1);

        // Check season diapason
        // If it runs out of bounds we guess it's as a season #1
        int season_num = std::stoi(season);

        if(season_num > m_max_season_number){
            season = "1";
        }

        season += m_season_url;
    }

    // Set up command
    std::string command;
    if(m_url.find("baskino") != std::string::npos){
        command = "xdg-open " + m_url + " > /dev/null 2>&1";
    }
    else{
        command = "xdg-open " + m_url + voice +
                  "/" + season + " > /dev/null 2>&1";
    }

    if(system(command.c_str())){
        std::cout << "Couldn't correctly open desired serial"
                     " because of incorrect parameters.\nCheck your "
                     "parameters or type: <serials --help>\n";
        exit(1);
    }

}


void Serial::openSerial(){

    // Set up voice
    (m_voice == "russian" || m_voice == "") ? m_voice = m_voice_url_rus 
                                            : m_voice = m_voice_url_eng;

    if(!m_season.empty() && m_season[0] == '-'){
        // Remove one character starting at position 0
        m_season.erase(0, 1);

        // Check season diapason
        // If it runs out of bounds we guess it's as a season #1
        int season_num = std::stoi(m_season);

        if(season_num > m_max_season_number){
            m_season = "1";
        }

        m_season += m_season_url;
    }

    // Set up command
    std::string command;
    if(m_url.find("baskino") != std::string::npos){
        command = "xdg-open " + m_url + " > /dev/null 2>&1";
    }
    else{
        command = "xdg-open " + m_url + m_voice +
                  "/" + m_season + " > /dev/null 2>&1";
    }

    if(system(command.c_str())){
        std::cout << "Couldn't correctly open desired serial"
                     " because of incorrect parameters.\nCheck your "
                     "parameters or type: <serials --help>\n";
        exit(1);
    }
}


void Serial::setMaxSeasonNumber(const int number){
    if(number > m_max_season_number){
        m_max_season_number = number;
    }
}


constexpr int Serial::getSeasonsNumber() const{
    return m_max_season_number;
}


void Serial::printSeasons() const{
    m_ptr_seasons_print->printSeasonsInfo(who(),
                                          getSeasonsNumber());
}


void Serial::setSeasonsPrintBehavior(
        std::unique_ptr<SeasonsPrintBehavior> &&behavior)
{
    if(behavior != nullptr){
        m_ptr_seasons_print = std::move(behavior);
    }
}