#ifndef MENU_CFG_H_INCLUDED
#define MENU_CFG_H_INCLUDED

/*******************structural definition******************/

/*********macro key value*********/
#define KEY_KILL 'k'
#define KEY_UP  'w'
#define KEY_DOWN 's'
#define KEY_BACK 'q'
#define KEY_OK 'o'

/***********menu theme***********
*       normal
*       round
* choose only one
********************************/
#define NORMAL_THEME 1
#define ROUND_THEME 0

/**the number of menus displayed on a page**/
#define MENU_NUMBER 6

/*********total page******/
typedef enum{
    nenTopLevel,
    nenSecondLevel,
    nenThirdLevel1,
    nenThirdLevel2,
    nenTotalMenuPage,
    nenTPMS,
    nenVersionInfo,
    nenWarnInfo,
    nenBackLight,
    nenLanguage,
    nenTheme,
    nenSound,
    nenBattery,
    nenRGB
}tenMenuPage;


/*********total menu item according page to classification*********/

/**nenTopLevel**/
typedef enum{
    nenTopMenuStart = 0,
    nenTopMenu = nenTopMenuStart,
    nenTopMenuEnd = nenTopMenu,
/**nenSecondLevel**/
    nenSecondMenuStart,
    nenSecondMenu1 = nenSecondMenuStart,
    nenSecondMenu2,
    nenSecondMenuEnd = nenSecondMenu2,
/**nenThirdLevel1**/
    nenThirdMenu1Start,
    nenTPMSMenu = nenThirdMenu1Start,
    nenVerMenu,
    nenThirdMenu1End = nenVerMenu,
/**nenThirdLevel2**/
    nenThirdMenu2Start,
    nenWarnInfoMenu = nenThirdMenu2Start,
    nenBackLightMenu,
    nenLanguageMenu,
    nenThemeMenu,
    nenSoundMenu,
    nenBatteryMenu,
    nenRGBMenu,
    nenThirdMenu2End = nenRGBMenu,
    nenNone
}tenMenuId;


/******page draw function pointer******/
typedef void(*Fun) (void);

/************draw menu data***************/
typedef struct{
    char *drawself;
}tstMenudrawdata;

/*********page configuration*********/
typedef struct{
    tenMenuId pagefirstmenu;
    tenMenuId pageendmenu;
}tstPageconfig;

/********menu configuration*********/
typedef struct{
    tenMenuPage out;
    tenMenuPage ok;
}tstMenuconfig;


/****************structural definition*********************/

/************extern data************/

/*****current page*****/
extern tenMenuPage currentpage;
/*****current menu*****/
extern tenMenuId currentmenu;
/*****last menu*****/
extern tenMenuId lastmenu;
/*****last page*****/
extern tenMenuPage lastpage;
/****menu configuration array****/
extern const tstMenuconfig menuarray[];
/****inetrnal page configuration array****/
extern const tstPageconfig pagearray[];
/****draw menu data array****/
extern const tstMenudrawdata menudataarray[];
/****extern page draw function****/
extern const Fun externpagepointer[];

/************extern data************/




/****extern page draw****/

void drawTPMS();
void drawver();
void drawwarninfo();
void drawbacklight();
void drawlanguage();
void drawtheme();
void drawsound();
void drawbattery();
void drawRGB();
void drawBcInfo();


/****extern page draw****/

#endif // MENU_CFG_H_INCLUDED

