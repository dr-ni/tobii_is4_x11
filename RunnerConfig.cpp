//
// Created by hector on 16-04-19.
//

#include "RunnerConfig.h"


string RunnerConfig::loadField(const char *fieldName, Config *cfg) {
    // Get the store name.
    try {
        string name = cfg->lookup(fieldName);
        cfg->lookup(fieldName);
        return name;
    }
    catch (const SettingNotFoundException &nfex) {
        cerr << "No '" << fieldName << "' setting in configuration file." << endl;
    }
    return "";
}

bool RunnerConfig::load() {
    Config cfg;

    // Read the file. If there is an error, report it and exit.
    try {
        cfg.readFile(CONFIG_FILE);
    }
    catch (const FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return false;
    }
    catch (const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return false;
    }
    m_selectedScreen = loadField(CFG_SCREEN_NAME, &cfg);
    return true;
}

string RunnerConfig::getSelectedScreen() const {
    return m_selectedScreen;
}

void RunnerConfig::setSelectedScreen(const string &mSelectedScreen) {
    m_selectedScreen = mSelectedScreen;
}
