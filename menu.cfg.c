#include <stdio.h>
#include <stdlib.h>
#include "menu.cfg.h"

extern void backtolastpage();

/*********menu configuration***********/
const tstMenuconfig menuarray[] = {
/*   menu_name            upper_page        lower_page	*/
    /*nenTopMenu*/       {nenNone,          nenSecondLevel},
    /*nenSecondMenu1*/   {nenTopLevel,      nenThirdLevel1},
    /*nenSecondMenu2*/   {nenTopLevel,      nenThirdLevel2},
    /*nenTPMSMenu*/      {nenSecondLevel,   nenTPMS       },
    /*nenVerMenu*/       {nenSecondLevel,   nenVersionInfo},
    /*nenWarnInfoMenu*/	 {nenSecondLevel,   nenWarnInfo   },
    /*nenBackLightMenu*/ {nenSecondLevel,   nenBackLight  },
    /*nenLanguageMenu*/  {nenSecondLevel,   nenLanguage   },
    /*nenThemeMenu*/     {nenSecondLevel,   nenTheme      },
    /*nenSoundMenu*/     {nenSecondLevel,   nenSound      },
    /*nenBatteryMenu*/   {nenSecondLevel,   nenBattery    },
    /*nenRGBMenu*/       {nenSecondLevel,   nenRGB        },
};



/******************inetrnal page configuration**********************/
const tstPageconfig pagearray[] = {
/**   pagename         first_menu            last_menu      **/
    /*nenTopLevel*/    {nenTopMenuStart,     nenTopMenuEnd    },
    /*nenSecondLevel*/ {nenSecondMenuStart,  nenSecondMenuEnd },
    /*nenThirdLevel1*/ {nenThirdMenu1Start,  nenThirdMenu1End },
    /*nenThirdLevel2*/ {nenThirdMenu2Start,  nenThirdMenu2End },
};
/******************extern page configuration**********************/
const Fun externpagepointer[] = {
    drawTPMS,
    drawver,
    drawwarninfo,
    drawbacklight,
    drawlanguage,
    drawtheme,
    drawsound,
    drawbattery,
    drawRGB
};

/************data field************/
const tstMenudrawdata menudataarray[] = {
/** menu_name             menu_data  **/
    /*nenTopMenu*/        {"MENU"},
    /*nenSecondMenu1*/    {"SecondMenu1"},
    /*nenSecondMenu2*/    {"SecondMenu2"},
    /*nenTPMSMenu*/       {"TPMSMenu"},
    /*nenVerMenu*/        {"VerMenu"},
    /*nenWarnInfoMenu*/   {"WarnInfoMenu"},
    /*nenBackLightMenu*/  {"BackLightMenu"},
    /*nenLanguageMenu*/   {"LanguageMenu"},
    /*nenThemeMenu*/      {"ThemeMenu"},
    /*nenSoundMenu*/      {"SoundMenu"},
    /*nenBatteryMenu*/    {"BatteryMenu"},
    /*nenRGBMenu*/        {"RGBMenu"},
};

/************data field************/


/****extern page draw****/

void drawTPMS(){
    printf("         Welcome!!!\n!!!This is TPMS page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawver(){
    printf("         Welcome!!!\n!!!This is Version page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawwarninfo(){
    printf("         Welcome!!!\n!!!This is warn information page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawbacklight(){
    printf("         Welcome!!!\n!!!This is backlight page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawlanguage(){
    printf("         Welcome!!!\n!!!This is language page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawtheme(){
    printf("         Welcome!!!\n!!!This is theme page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawsound(){
    printf("         Welcome!!!\n!!!This is sound page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawbattery(){
    printf("         Welcome!!!\n!!!This is battery page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
void drawRGB(){
    printf("         Welcome!!!\n!!!This is RGB page!!!\n\ninput 'q' back to menu page!\n");
    char a = 0;
    a = getchar();
    scanf("%c", &a);
    if(a == KEY_BACK){
        backtolastpage();
    }
}
/****extern page draw****/


