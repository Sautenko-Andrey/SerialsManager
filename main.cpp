#include<cstdlib>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<iostream>

#include"SimpleSerialsFactory.h"
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
#include"SerialsStore.h"
#include"Help.h"


int main(int argc, char **argv){

    constexpr int min_args_num{2};  // At least one argument (serial's name)
    constexpr int max_args_num{4};  // 3 args maximum(name, season, lang)

    // Process when user types help command
    if(argc == min_args_num && std::string(argv[1]) == "--help"){
        std::cout << help_message;
        std::exit(0);
    }

    // Usage message for a user
    const std::string usage{
        "Usage: serials <-serial_name> <-season number> [-language]\n"
    };

    //Serials names
    const std::unordered_map<std::string, AvailableSerials> serials{
        {"-a" , AvailableSerials::AccordingToJim},
        {"-b" , AvailableSerials::Brassic},
        {"-h" , AvailableSerials::HowIMetYourMother},
        {"-s" , AvailableSerials::SiliconValley},
        {"-t" , AvailableSerials::TwoAndAHalfMen},
        {"-bbt" , AvailableSerials::BigBangTheory},
        {"-p", AvailableSerials::PoorPeople},
        {"-n", AvailableSerials::NewGirl},
        {"-i", AvailableSerials::Interni}
    };

    // Process when user types --serials command
    if(argc == min_args_num && std::string(argv[1]) == "--serials"){
        std::cout << "Serials amount: " << serials.size() << '\n';
        std::exit(0);
    }


    const std::unordered_map<std::string, std::string> languages{
        {"-e", "english"},
        {"-r", "russian"}
    };

    const std::unordered_set<std::string> seasons {
        "-1", "-2", "-3", "-4", "-5", "-6",
        "-7", "-8", "-9", "-10", "-11", "-12"
    };

    if(argc < min_args_num){
       std::cout << "Too few arguments. " << usage; 
    }
    else if(argc > max_args_num){
        std::cout << "Too many arguments. " << usage; 
    }

    // Find the main argument - serial's name
    AvailableSerials serial;
    for(int i{1}; i < argc; ++i){
        auto it_serial_name = serials.find(argv[i]);
        if(it_serial_name != serials.end()){
            serial = it_serial_name->second;
            break; // exit from the loop immediately
        }
    }

    std::string season;
    // Find a desired season (it could be ommited)
    for(int i{1}; i < argc; ++i){
        auto it_season_number = seasons.find(argv[i]);
        if(it_season_number != seasons.end()){
            season = *it_season_number;
            break;
        }
    }

    std::string voice{""};
    // Find a language mode (it could be ommited)
    for(int i{1}; i < argc; ++i){
        auto it_lang_mode = languages.find(argv[i]);
        if(it_lang_mode != languages.end()){
            voice = it_lang_mode->second;
            break;
        }
    }

    // Test serials store
    SerialsStore serials_store(std::make_shared<SimpleSerialsFactory>());

    // Set up and play serial
    //auto selected_serial = serials_store.playSerial(serial, season, voice);
    
    auto selected_serial = serials_store.createSerial(serial, season, voice);
    
    // If user wants to print a list of seasons for the choosen serial
    
    if(constexpr int args_num_seasons_lst{3}; 
       argc == args_num_seasons_lst && std::string(argv[2]) == "--list"){
        
        selected_serial->printSeasons();
        // exit right after
        return 0;
    }

    selected_serial->openSerial();

    return 0;
}