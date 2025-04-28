//
// Created by hector on 16-04-19.
//

#ifndef TOBII_IS4_X11_RUNNERCONFIG_H
#define TOBII_IS4_X11_RUNNERCONFIG_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <libconfig.h++>

using namespace libconfig;
using namespace std;

#define CONFIG_FILE "/etc/tobii.cfg"
#define CFG_SCREEN_NAME "screen"

class RunnerConfig {
public:
    bool load();

private:
public:
    string getSelectedScreen() const;

    void setSelectedScreen(const string &mSelectedScreen);


private:
    string m_selectedScreen;

    string loadField(const char *fieldName, Config *cfg);
};


#endif //TOBII_IS4_X11_RUNNERCONFIG_H
